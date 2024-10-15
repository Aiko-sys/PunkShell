#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
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
#ifdef _WIN32
    DWORD size = 256;
    if(GetComputerNameA(hostname, &size) == 0){
        perror("GetComputerNameA");
        free(hostname);
        return NULL;
    }
#else
    if(gethostname(hostname, 256) == -1){
        perror("gethostname");
        free(hostname);
        return NULL;
    }
#endif
    return hostname;
}

char* get_user(){
#ifdef _WIN32
    
    static char username[256];
    DWORD username_len = sizeof(username);
    if(GetUserName(username, &username_len)){
        return username;
    } else{
        return NULL;
    }
#else

    char *username = getenv("USER");
    if (username == NULL) {
        username = getenv("LOGNAME");
    }
    return username;
#endif

}