//
// Created by iris on 06/01/2020.
//

#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H

#include <string>
#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include "Data.h"

using namespace std;

class Server {
    int sock, client_socket;
    sockaddr_in address;
    bool connect();
    void readData();
    void update(string data);

public:
    Server (int port);
    void run();
};


#endif //PROJECT_SERVER_H
