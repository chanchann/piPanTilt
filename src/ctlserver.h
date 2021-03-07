#ifndef CTLSERVER_H
#define CTLSERVER_H

#include "motor.h"
#include <burger/net/TcpServer.h>
#include <burger/net/EventLoop.h>
#include <functional>
#include <string>
#include <iostream>

using namespace burger;
using namespace burger::net;


class CtlServer {
public:
    CtlServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const std::string &name);
    void start();
private:
    void onConnection(const TcpConnectionPtr&);

    void onMessage(const TcpConnectionPtr&,
                   Buffer&,
                   Timestamp);
private:
    TcpServer server_; 
    EventLoop *loop_;
    Motor motor_;
}


#endif // CTLSERVER_H