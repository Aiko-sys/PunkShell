#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "signals.h"
#include "utils.h"
#include "exec.h"
#include "commands.h"

void execute_command(char* command){
    char* args[256];
    char* token;
    int i = 0;
    token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
     args[i] = NULL;

    pid_t pid;
    if(pid < 0){
        perror("fork error");

    } else if(pid == 0){

        if (execvp(args[0], args) == -1) {
            perror("command execute error");
            exit(EXIT_FAILURE);
        }
    }
    else {
        int status;
        waitpid(pid, &status, 0);
    }

}