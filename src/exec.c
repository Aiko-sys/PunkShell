#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <sys/types.h>

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
#ifdef _WIN32
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    char full_command[256] = "";
    for(int j = 0; args[j] != NULL; j++){
        strcat(full_command, args[j]);
        strcat(full_command, " ");
    }
    int is_empty = 1;
    for(int j = 0; full_command[j] != '\0'; j++) {
        if (!isspace((unsigned char)full_command[j])) {
            is_empty = 0; 
            break;
        }
    }
    if (is_empty) {
        return;
    } else if (strcmp(args[0], "cls") == 0) {
        clear_screen_command();
    } else if (strcmp(args[0], "color") == 0 && args[1] != NULL) {
        set_color_command(args[1]);
    } else if (!CreateProcess(NULL, full_command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Invalid command: %s\n", full_command);
    } else {

        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
# else
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

#endif
}