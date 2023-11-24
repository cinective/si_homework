#include <stdio.h>
#include <pthread.h>

#define INC_SCALE 100000
#define THREADS_COUNT 1000


int global_int = 0;

void *ThreadIncrement(void *arg){
    
    for(int i = 0; i < INC_SCALE; ++i){
        global_int++;
    }

    return NULL;
}



int main(void){
    
    int *retval;
    pthread_t thread[THREADS_COUNT];

    for (int i = 0; i < THREADS_COUNT; ++i){
        pthread_create(&thread[i], NULL, ThreadIncrement, NULL);
    }

    for (int i = 0; i < THREADS_COUNT; ++i){
        pthread_join(thread[i], (void **) &retval);
    }

    printf("PthreadIncrement: %d \n", global_int);

    return 0;
}