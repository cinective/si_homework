#include <stdio.h>
#include "main_functions.h"

void AbonentsList(struct directory* dir) {

		if (dir->user_count){
			printf("\n list of abonents:\n");
			for (int i = 0; i < dir->user_count; ++i) {
				
				printf("\n%d - %s", i, dir->users[i].name);
			}
		}
		else {
			printf(" \n List of abonbents is empty");
		}

		return;
}
