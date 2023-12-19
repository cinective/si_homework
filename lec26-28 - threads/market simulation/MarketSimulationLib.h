#include <pthread.h>
#define CUSTOMERS_COUNT 3
#define MARKETS_COUNT 5
#define SLEEP_TIME_CUSTOMER 1 //(in seconds)
#define SLEEP_TIME_LOADER 2   //
#define  LOADER_PRODUCT_LOAD_SIZE 500    //$
#define CUSTOMER_REQUIREMENT_SIZE 10000  //

//market class itself
struct market{
    pthread_mutex_t mtx;
    int product_count;
};

//creatin another data structure to send individual number 
//for every single customer thread
//we'll use them instead of TID's for convenient log format
struct arg_data{
    struct market *market_arr;
    int thread_number;
};

//thread functions
void *LoaderFunc   (void *market_ptr);
void *CustomerFunc (void *args);