#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#else
#include <unistd.h>
#endif

#include "utils.h"


char* get_device_name(){
    char *hostname = malloc(256);
    if(hostname == NULL){
        perror("malloc error");
        return NULL;
    }
    if(gethostname(hostname, 256) == -1){
        perror("gethostname");
        free(hostname);
        return NULL;
    }
    return hostname;
}

char* get_user(){
    char *username = getenv("USER");
    if (username == NULL) {
        username = getenv("LOGNAME");
    }
    return username;

}