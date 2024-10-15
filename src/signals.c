#include <signal.h>
#include "signals.h"

void sigint_handler(int sig) {
}

void setup_signals() {
    signal(SIGINT, sigint_handler); 
}
