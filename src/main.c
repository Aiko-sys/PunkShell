#include "commands.h"
#include "exec.h"
#include "parser.h"
#include "signals.h"
#include "utils.h"
#include "version.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[MAX_INPUT_SIZE];

    setup_signals();
    
    while(1){
        printf("[%s@%s]=----=> ", get_user(), get_device_name());
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Input failed");
            break;
        }
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            break;
        }
        execute_command(input);
    }
    return 0;
}