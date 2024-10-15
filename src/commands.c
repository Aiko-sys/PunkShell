#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#include "commands.h"

void clear_screen_command() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void set_color_command(const char* color) {
#ifdef _WIN32
    if (strcmp(color, "red") == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    } else if (strcmp(color, "green") == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    }
    
    
#else
    // TO DO
#endif
}