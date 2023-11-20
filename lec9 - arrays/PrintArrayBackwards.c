#include "PrintFunks.h"
#include <stdio.h>

/*defining array parameters*/
#define pabWidth WIDTH
#define pabHeight 1

void print_array_backwards(unsigned int first_number) {

	int arr[pabWidth];

	{//Fill the array

		int* ptr = arr;

		for (int i = 0; i < pabWidth; ++i) {
			*ptr = (first_number + i);
			++ptr;
		}
	}

	{//Reverse it

		int* PtrFirst =  arr;
		int* PtrLast  = (arr + pabWidth - 1);

		int  steps = (pabWidth / 2);

		for (int i = 0; i < steps; ++i) {

			/*Exchange*/
			int PtrBuffer = *PtrFirst;
			   *PtrFirst  = *PtrLast;
			   *PtrLast   =  PtrBuffer;
			   
			/*next step*/
			   ++PtrFirst;
			   --PtrLast;
		}

	}
	//

	/*    ptint it        */
	matrix_print(arr, pabWidth, pabHeight);

	/*complete message*/
	printf("\n    it works!    \n\n\n\n");
}