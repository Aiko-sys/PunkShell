#include "main.h"

int main(int argc, char **argv){


    (void)argc, (void)argv;
    char *buf = NULL, *tok;

    size_t count = 0;
    ssize_t nread;

    pid_t child_pid;
    int i, status;

    char **array;

    while(1){
        write(STDOUT_FILENO, "Punkshell$ ", 11);
        nread = getline(&buf, &count, stdin);

        if(nread == -1){
            
            perror("[ Exiting punkshell ]");
            exit(1);
        }

        tok = strtok(buf, " /n");
        array = malloc(sizeof(char*) * 1024);
        i = 0;

        while(tok){
            array[i] = tok;
            tok = strtok(NULL, " \n");
            i++;
        }

        array[i] = NULL;

        child_pid = fork();

        if(child_pid == -1){
            perror("[ERROR]: Failed to create");
            exit(41);
        } else if (child_pid == 0){
            if (execve(array[0], array, NULL) == -1)
            {
                    perror("Failed to execute");
                    exit(97);
            }
        } else{
            wait(&status);
        }

        printf("%s", buf);

    }
    free(buf);

    return (0);
}