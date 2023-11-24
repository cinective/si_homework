#include <stdio.h>

int global_int = 0;

int main(void){

    const int goal = 100000000;

    for (int i = 0; i < goal; ++i){
        global_int++;
    }

    printf("Simple for: %d \n", global_int);

    return 0;
}