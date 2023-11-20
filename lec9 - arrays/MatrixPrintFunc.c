#include "PrintFunks.h"
#include <stdio.h>

void matrix_print(int *matrix, int width, int height) {

    //calculate max symbols count for number
    int max_symbols_count = 0;
    {//find biggest number & count of symbols

        int biggest = 0;

        for (int i = 0; i < height; ++i) {                

            for (int j = 0; j < width; ++j) {      

                int current = ((i * width) + j);

                if (matrix[current] > biggest) {

                    biggest = matrix[current];
                }
            }
        }

        while ((biggest / 10) >= 1) {
            biggest /= 10;
            ++max_symbols_count;
        }
    }

    {//print it

        int counter = 0;

        for (int i = 0; i < height; ++i) {                //for each row

            for (int i = 0; i < width; ++i) {             //for each number per row
                int current_number = matrix[counter];

                printf("%d  ", current_number);

                {// calculate & print spaces to equally allign columns
                    int prt = current_number;
                    int symbols_count = 0;
                    while ((prt / 10) >= 1) {

                        prt /= 10;
                        ++symbols_count;
                    }

                    if ((max_symbols_count - symbols_count) > 0) {

                        for (int i = 0; i < (max_symbols_count - symbols_count); ++i) {

                            printf(" ");
                        }
                    }
                }


                
                ++counter;
            }
            
            /* row space allignment, also depends on max symbols count */
            printf("\n");
            if (max_symbols_count > 0) {

                for (int i = 0; i < max_symbols_count; ++i) {
                    printf("\n");
                }
            }
        }
    }
}