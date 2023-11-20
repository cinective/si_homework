#include <stdio.h>
#include "abonentstruct.h"
#include "main_functions.h"

void AbonentAdd (struct directory* dir) {

    if (dir->user_count < 100) {    //check i there is free space available

        struct abonent* user_cell = (dir->users + dir->user_count);

        /* fill the fields */

        printf("\n Type new abonent name: ");

        if (scanf("%10s", user_cell->name)) {
        }

        printf("\n Last name: ");
        if (scanf("%10s", user_cell->last_name)) {
        }

        printf("\n And phone number: ");
        if (scanf("%11s", user_cell->number)) {
        }

        /* increment counter */
        dir->user_count++;
    }
    else {  //swear if array is full
        printf("\n Can't add user, directory is full");
    }

    return;
}