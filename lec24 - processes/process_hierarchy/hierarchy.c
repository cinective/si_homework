//std
#include <stdio.h>
#include <stdlib.h>
//process libs
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Print pid & ppid */
void DrawPids(){
printf("pid == %d; ppid == %d\n", getpid(), getppid());
}



int main(void){

pid_t child_pid;
int status;

/* Create child 1 */
child_pid = fork();

if (child_pid == 0){
    /* ==== A S   C H I L D    P R O C E S S  0-1 === */
    DrawPids();
    
     /* Create Child 2 */
    child_pid = fork();
    if(child_pid == 0){
        /* === A S   C H I L D    P R O C E S S  1-2 === */
        DrawPids();
        exit(0);
    }
    else{
        /* === A S   C H I L D    P R O C E S S  0-1 === */

        /* Create Child 3 */
        child_pid = fork();
        if(child_pid == 0){
            /* === A S   C H I L D    P R O C E S S  1-3 === */
            DrawPids();
            exit(0);
        }
        else{
            /* === A S   C H I L D    P R O C E S S  0-1 === */
            wait(&status); //wait for 2 & 3
            wait(&status);
            exit(0);
        }
    }
}
/* === A S   P A R E N T    P R O C E S S  (0) === */

    /* Create Child 4*/
    child_pid = fork();
    if(child_pid == 0){
        DrawPids();

        /* Create Child 5*/
        child_pid = fork();
        if(child_pid == 0){
            DrawPids();
            exit(0);
        }
        else{
            wait(&status);
            exit(0);
        }
    }
    else{

        printf("main process pid == %d\n", getpid());
        wait(&status); //wait for 1 & 4
        wait(&status);
        return 0;
    }
}