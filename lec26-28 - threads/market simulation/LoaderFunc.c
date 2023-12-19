#include "MarketSimulationLib.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

/*
  Loader is goin' to infinitly check every 
  market's mutex in sequence. In case it's open, 
  loader passing product to market,  
  reporting about that and releasing mutex. 
  thats the cycle.
  then it's gonna sleep untill next cycle.
*/

void *LoaderFunc(void *market_ptr){
    struct market *market = (struct market *) market_ptr;
    int i;

    printf("Loader: im created! \n");

    while(1){
        //look for free market
        for(i = 0; i < MARKETS_COUNT; ++i){

            pthread_mutex_t *mtx = &(market[i].mtx);

            //check if market locked
            if(!(pthread_mutex_lock(mtx))){
               market[i].product_count += LOADER_PRODUCT_LOAD_SIZE;
                printf("Loader: loaded product to market-%d, up to %d$ \n", i, market[i].product_count);
                printf("unlocking mutex && gonna sleep for %d sec \n", SLEEP_TIME_LOADER);
               pthread_mutex_unlock(mtx);
               usleep(SLEEP_TIME_LOADER * 1000000);
            }
            else{
                printf("Loader: market-%d is locked, keep searching.. \n", i);
            }
        }
    }
}