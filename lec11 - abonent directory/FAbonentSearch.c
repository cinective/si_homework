#include <stdio.h>
#include <string.h>
#include "abonentstruct.h"
#include "main_functions.h"




void AbonentSearch(struct directory* dir) {



    char keyword[12] = {'0','\0'};
    /* type keyword */
    printf("\n Type a keyword: ");
    if (scanf("%11s", keyword)) {
    }
    printf("\n");


    /* try to find it */
    int users_found = 0;
    for (int i = 0; i < dir->user_count; ++i) {

        if  (  ((strcmp(keyword, dir->users[i].name)      == 0)) 
            || ((strcmp(keyword, dir->users[i].last_name) == 0)) 
            || ((strcmp(keyword, dir->users[i].number)    == 0)) ) {

               AbonentDisplayInfo(dir->users, i);
             ++users_found;
        }
    }

    /* results comment */
    if (users_found) {
        printf("\n %d Abonents Found", users_found);
    }
    else {
        printf("\n No abonents Found(");
    }

    return;
}