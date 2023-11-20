#include <stdio.h>
#include <string.h>
#include "abonentstruct.h"
#include "main_functions.h"


void AbonentDelete(struct directory* dir) {
    
    /* enter index*/
    unsigned int index = 0;
    printf("\nEnter index of user you wanna delete: ");
    if (scanf("%d", &index)) {
    }

    
    /* deleting */
    char empty_str[12] = {'0','0','0','0','0','0','0','0','0','0','0','\0'};
   
    if (index < dir->user_count) {     //check if index is valid
        if (dir->user_count > 1) {     //if count higher than 1

            struct abonent* last_user      = ((dir->users + (dir->user_count - 1)));
            struct abonent* user_to_delete =  (dir->users + index);

            /* paste last user instead of deleted one */
            strcpy(user_to_delete->name,      last_user->name);
            strcpy(user_to_delete->last_name, last_user->last_name);
            strcpy(user_to_delete->number,    last_user->number);

            /* clear ex-last user cell */
            strcpy(last_user->name,      empty_str);
            strcpy(last_user->last_name, empty_str);
            strcpy(last_user->number,    empty_str);
        }
        else {   
            /* just clear lonely user */
            strcpy(dir->users[index].name,      empty_str);
            strcpy(dir->users[index].last_name, empty_str);
            strcpy(dir->users[index].number,    empty_str);
        }
        /* decrement abonent counter */
        dir->user_count-- ;
        /* message of success*/
        printf("\nUser successfully  deleted");

    }
    else {//swear about incorrect user
        printf("\nCan't delete user at this index");
    }

    return;
}