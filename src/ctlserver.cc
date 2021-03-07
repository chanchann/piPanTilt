#include "ctlserver.h"


CtlServer::CtlServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const std::string &name) 
    : server_(loop, listenAddr, name),
    loop_(loop) {
    server_.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));  // conn
    server_.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3)); // conn, buf, timestamp
}

void CtlServer::start() {
    server_.start();
}

void CtlServer::onConnection(const TcpConnectionPtr&) {
    if(conn->isConnected()) {
        std::cout << "onConnection(): new connection [" 
            << conn->getName() <<  "] from " 
            << conn->getPeerAddress().getIpPortStr() << std::endl;
    } else {
        std::cout << "onConnection() : connection " 
            << conn->getName() << " is down" << std::endl;
    }   
}

void CtlServer::onMessage(const TcpConnectionPtr&,
                   Buffer&,
                   Timestamp) {
    std::cout << "onMessage(): received " << buf.getReadableBytes() 
        << " bytes from connection " << conn->getName() 
        << " at " << recieveTime.toFormatTime() <<std::endl;
    string res = buf.retrieveAllAsString()
    if(res == "start") {
        conn->send();
    }
    
}





