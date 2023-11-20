#include "PrintFunks.h"

/*defining array parameters*/
#define ptWidth WIDTH
#define ptHeight ptWidth


void print_triangled_square(unsigned int fill_0, unsigned int fill_1, unsigned int fill_edge) {

    //create array
    int arr[ptWidth * ptHeight];

    //and fill it
    for (int i = 0; i < ptHeight; ++i) { //for each row

        for (int j = 0; j < ptWidth; ++j) { //per one row

            int index = ((i * ptWidth) + j);
            
            if (j < (ptWidth - i - 1)) {    //triangle is left
                arr[index] = fill_0;
            }
            else if (j > (ptWidth - i  - 1)) {    //it's not an edge but right triangle
                arr[index] = fill_1;
            }
            else {  //it was an edge, after all
                arr[index] = fill_edge;
            }
        }
    }

/*
    //fill the array   

        for (int i = 0; i < (ptWidth * ptWidth); ++i) {

            arr[i] = (fill_0);
        }
    

    {//Make 1-triangle



        for (int i = 0; i < (ptHeight); ++i) {              //action for each row

            int* ptr = (arr + (i * ptWidth) + ptWidth - 1);


            for (int j = 0; j < (i + 1); ++j) {                 //per one  row


                if (j == i) {             //make edge for beauty

                    *ptr = 7;
                }
                else {

                    *ptr = fill_1;
                }
              
                --ptr;
            }
        }
    }
    */
    /*    ptint it        */
    matrix_print(arr, ptWidth, ptHeight);

    /*complete message*/
    printf("\n    it works!    \n\n\n\n");
}