//std
#include <stdlib.h>
#include <stdio.h>
//string
#include <string.h>
//processes libs
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//cover loop control into enum just for conveinence
enum loop_status {GO_ON = 1, STOP = 0};


int main(void){

    enum loop_status loop_status = GO_ON;

    char raw_command[60];
    const char delim[] = {" ,\n,\0"};
    //tokens for exec()
    char *first_tok;
    char *second_tok;
    char *third_tok;

    char exitstr[] = {"STOP"};
    pid_t child_pid;
    int   status;

    //main cycle
    while (loop_status){
        // getting command string
        printf("\nType command (path; bin.name; flag)");
        fgets(raw_command, 45, stdin);
        /* (insert screen clear code here) */

        // cancel loop if there is the stop command
        if(0 == strcmp(exitstr, raw_command)){
            loop_status = STOP;
            exit;
        }

        // tokenize it
        first_tok  = strtok(raw_command, delim);
        second_tok = strtok(NULL, delim);
        third_tok  = strtok(NULL, delim);

        // command execution try
        child_pid  = fork();
        if(child_pid == 0){
            printf("\n i'm a new process. BTW, my pid is %d.\n", getpid());
            execl(first_tok, second_tok, third_tok, NULL);
        }
        else{
            wait(&status);
        }

    }

    return 0;
}