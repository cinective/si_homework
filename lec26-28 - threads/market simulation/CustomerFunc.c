#include "MarketSimulationLib.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
  Customer lifetime breaks with requirement satisfaction, 
  unlike as loader do.
  But cycle logic works in similar way:

  we movin' through markets looking for open mutex to occupy it
  taking away all the stuff if we have money(req) enough
  (subtracting stuff cost from requirement)
  and leaving market empty

  otherwise our cash is gone, so customer will report about it
  and turn himself off
*/
void *CustomerFunc(void *args){
    //unpacking data
        struct arg_data *data = (struct arg_data *) args;
        struct market *market = data->market_arr;
        int my_id = data->thread_number;

        int i;

    int requirement = CUSTOMER_REQUIREMENT_SIZE;

    printf("customer-%d: im created! \n", my_id);

    while(1){

        //look for free market
        for(i = 0; i < MARKETS_COUNT; ++i){

            pthread_mutex_t *mtx = &(market[i].mtx);

            //check if market locked
            if(!(pthread_mutex_lock(mtx))){
                //buy all
               if(market[i].product_count < requirement){
                    requirement -= market[i].product_count;
                    printf("customer-%d: spent %d$ at market-%d, %d$ left \n", my_id, market[i].product_count, i, requirement);
                    printf("unlocking mutex && gonna sleep for %d sec\n", SLEEP_TIME_CUSTOMER);
                    market[i].product_count = 0;
               }
               else{ //exit if requirement was satisfied
                    requirement = 0;
                    printf("customer-%d: spent %d$ at market-%d, %d$ left \n", my_id, market[i].product_count, i, requirement);
                    market[i].product_count = 0;
                    printf("requirement satisfied. unlocking mutex, closing thread \n");

                    pthread_mutex_unlock(mtx);
                    pthread_exit(NULL);
               }
               pthread_mutex_unlock(mtx);
               usleep(SLEEP_TIME_CUSTOMER * 1000000);
            }
            else{
                printf("customer-%d: market-%d is locked, keep searching.. \n", my_id, i);
            }
        }
    }
}