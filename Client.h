//
// Created by iris on 06/01/2020.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H
#include <vector>
#include "Command.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Data.h"

class Client {
    int sock;
    sockaddr_in address;
    void send_Data();
    bool connection();
public:
    Client (string ip, int port);
    void run();

    virtual ~Client();
};


#endif //PROJECT_CLIENT_H
