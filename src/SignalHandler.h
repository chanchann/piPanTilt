#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
class SignalHandler {
public:
    explicit SignalHandler();
    virtual ~SignalHandler() = default;
    void registerSignalHandler(void (*handler)(int));
private:
    static void ctrlHandler(int s);
};


#endif // SIGNALHANDLER_H