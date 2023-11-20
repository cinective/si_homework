#include <stdio.h>
#include <string.h>
#include "abonentstruct.h"
#include "main_functions.h"


int main() {

    struct directory dir;
    dir.user_count = 0;

    enum menu_options option = 0;

    /*fill the whole dir*/
    //char fil[12] = { '1','\0' };
    //for (int i = 0; i < 100; ++i) {
    //    strcpy(dir.users[i].name, fil);
    //    strcpy(dir.users[i].last_name, fil);
    //    strcpy(dir.users[i].number, fil);
    //    dir.user_count++;
    //}

    PrintMenu();

    for (;;) {

        
        printf("\n");

        if (scanf("%d", &option)) {
        }
         

        switch (option) {
            
        case LIST:
            UpdScr();
            AbonentsList(&dir);
            break;

        case FIND:
            UpdScr();
            AbonentSearch(&dir);
            break;

        case ADD:
            UpdScr();
            AbonentAdd(&dir);
            break;

        case REMOVE:
            UpdScr();
            AbonentDelete(&dir);
            break;

        case EXIT:
            return 0;

        default:
            printf("incorrect option");
            break;
        }
    }
    

    return 0;
}