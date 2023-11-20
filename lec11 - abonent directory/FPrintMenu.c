#include <stdio.h>
#include "main_functions.h"


void PrintMenu() {
    printf("\n      =================\n    ABONENT DIRECTORY\n  =================\n");

    printf("\n 1(LIST)   - List of users");
    printf("\n 2(FIND)   - try to find user by name");
    printf("\n 3(ADD)    - Add new user");
    printf("\n 4(REMOVE) - Remove chosen user");
    printf("\n 5(EXIT)   - Close program\n");
}

void UpdScr() {
    ClearScr();
    PrintMenu();
}