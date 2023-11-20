#include "PrintFunks.h"

/*defining array parameters*/
#define sWidth WIDTH



void print_snail(unsigned int first_number) {

  
    int linear_arr[sWidth * sWidth];
    /*   fill the array   */
    for (int i = 0; i < (sWidth * sWidth); ++i) {

        linear_arr[i] = i + first_number;
    }
    

    /*    sort elements to another array    */
    int snail_arr[sWidth * sWidth];

    {//init with 0
        int* ptr = snail_arr;
        for (int i = 0; i < (sWidth * sWidth); ++i) {
            *ptr = 0;
            ++ptr;
        }
    }

    // for each number: move it to it's own cell (calculate the cell)

    int* current_number = linear_arr;
    int* cell = snail_arr;

    int side_length = sWidth;

    while ((*current_number != (sWidth * sWidth)) && (*current_number >= 0)) {

        //right-down corner
        for (int i = 0; i < (side_length); ++i) {       //right

            *cell = *current_number;
            if (*current_number == (sWidth * sWidth)) {
                break;
            }
            ++cell;
            ++current_number;
        }

        --cell;
        cell += sWidth;//move down

        for (int i = 0; i < (side_length -1); ++i) {    //down
        
            *cell = *current_number;
            if (*current_number == (sWidth * sWidth)) {
                break;
            }
            cell += sWidth;
            ++current_number;
        }


        cell -= sWidth;
        --side_length;  //cut length for next corner
        --cell;         //move to next corner cell


        //left-up corner
        for (int i = 0; i < (side_length); ++i) {       //left

            *cell = *current_number;
            if (*current_number == (sWidth * sWidth)) {
                break;
            }
            --cell;
            ++current_number;
        }

        ++cell;
        cell -= sWidth;//move up

        for (int i = 0; i < (side_length - 1); ++i) {    //up

            *cell = *current_number;
            if (*current_number == (sWidth * sWidth)) {
                break;
            }
            cell -= sWidth;
            ++current_number;
        }

        cell += sWidth;
        --side_length;
        ++cell;
    }

    /* put last number if it's odd */
    if (sWidth % 2){    
        *cell = *current_number;
    }


    /*    ptint it        */
    matrix_print(snail_arr, sWidth, sWidth);

    /*complete message*/
    printf("\n    it works!    \n\n\n\n"); 
}