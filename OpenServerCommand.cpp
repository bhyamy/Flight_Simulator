//
// Created by iris on 30/12/2019.
//

#include "OpenServerCommand.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

void OpenServerCommand::openDataServer() {
    std::thread(openServer);
}

void OpenServerCommand::openServer() {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0); // TODO sock stream or TCP protocol?
    //checking that the socket opened without errors
    if (socketfd == -1) {
        cout << "Could not open socket" << endl;
    }
    


}