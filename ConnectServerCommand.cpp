//
// Created by bhyamy on 1/2/20.
//

#include "ConnectServerCommand.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 5402


//ctor
ConnectServerCommand::ConnectServerCommand() {}

int ConnectServerCommand::execute(vector<string>::iterator iter) {
    //creating the socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    //in case of error in socket opening
    if (client_socket == -1) {
        cout << "Could not create client socket" << endl;
        return -1;
    }
    //creating a sockaddr to hold the address of the server
    sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_address.sin_port = htons(PORT);
    //connecting to a server
    int is_connect = connect(client_socket, (struct sockaddr*) &client_address, sizeof(client_address));
    //in case connection failed
    if (is_connect == -1) {
        cout << "Could not connect to the server" << endl;
        return -2;
    } else {
        cout << "Connected to server" << endl;
    }


    close(client_socket);
}
