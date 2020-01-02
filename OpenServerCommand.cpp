//
// Created by iris on 30/12/2019.
//

#include "OpenServerCommand.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#define PORT 5400
using namespace std;

void OpenServerCommand::openDataServer() {
    std::thread(openServer);
}

int OpenServerCommand::openServer() {
    //socket opening
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    //checking that the socket opened without errors
    if (socketfd == -1) {
        cout << "Could not open socket" << endl;
        return -1;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    //checking that the socket binded without errors
    if (bind(socketfd, (struct sockaddr*) &address, sizeof(address)) == -1) {
        cout << "Could not bind the socket to an IP address" << endl;
        return -2;
    }
    //checking the listen command
    if (listen(socketfd, 1) == - 1) {
        cout << "Error during listen command" << endl;
        return -3;
    }
    int client_socket = accept(socketfd, (struct sockaddr*) &address, (socklen_t*) &address);
    //checking that the client was accepted without errors
    if (client_socket == -1) {
        cout << "Could not accept the client" << endl;
        return -4;
    }
    close(socketfd);
}

int OpenServerCommand::execute(vector<string>::iterator iter) {

}
