#pragma once
#include <stdlib.h>
#include "abonentstruct.h"
#define ClearScr() system("@cls||clear")


enum menu_options {
	LIST = 1, FIND = 2, ADD = 3, REMOVE = 4, EXIT = 5
};

void AbonentsList       (struct directory* dir);
void AbonentDisplayInfo (struct abonent* user_array, int index);
void AbonentSearch      (struct directory* dir);
void AbonentAdd         (struct directory* dir);
void AbonentDelete      (struct directory* dir);

void PrintMenu();
void UpdScr();		//screen refresh
