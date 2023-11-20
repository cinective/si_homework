#include "PrintFunks.h"

/*defining array parameters*/
#define psWidth WIDTH
#define psHeight psWidth


void print_square(unsigned int first_number) {

	int arr[psWidth][psHeight];
	
	/*   fill the array   */
	int* ptr = arr;
	for (int i = 0; i < (psWidth * psWidth); ++i) {
	   *ptr = (first_number + i);
	   ++ptr;
	}
	//

	/*    ptint it        */
	matrix_print(arr, psWidth, psHeight);

	/*complete message*/
	printf("\n    it works!    \n\n\n\n");
}