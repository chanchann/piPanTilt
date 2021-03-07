#include "SignalHandler.h"

void SignalHandler::ctrlHandler(int s) {
    printf("Caught signal %d\n",s);
    exit(1); 
}

void SignalHandler::registerSignalHandler(void (*handler)(int)) {
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
}

SignalHandler::SignalHandler() {
    registerSignalHandler(ctrlHandler);
}
