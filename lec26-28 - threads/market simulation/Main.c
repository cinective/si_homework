#include <stdio.h>
#include <pthread.h>
#include "MarketSimulationLib.h" 


int main(void){
    void *retval;

    // main characters
    struct market market[MARKETS_COUNT];
    pthread_t   customer[CUSTOMERS_COUNT];
    pthread_t   loader;

    struct arg_data data[CUSTOMERS_COUNT];

    // init markets parameters
    for(int i = 0; i < MARKETS_COUNT; ++i){
        market[i].product_count = 1000;
        pthread_mutex_init(&market[i].mtx, NULL);
    }


    // Here begins the simulation
    pthread_create(&loader, NULL, LoaderFunc, (void *) &market);

    for(int i = 0; i < CUSTOMERS_COUNT; ++i){
        data[i].market_arr = market;
        data[i].thread_number = i; 
        pthread_create(&customer[i], NULL, CustomerFunc, (void *) &data[i]);
    }

    // wait 'till threads closure
    for(int i = 0; i < CUSTOMERS_COUNT; ++i){
        pthread_join(customer[i], &retval);
    }
    printf("All customer threads were finished \n");

    pthread_detach(loader);
    printf("Loader thread was finished \n");

    return 0;
}
