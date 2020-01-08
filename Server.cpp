//
// Created by iris on 06/01/2020.
//

#include "Server.h"

//ctor
Server::Server(int port) {
    //socket opening - a TCP protocol
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //in case of socket opening error
    if (sock == -1) {
        throw "Could not open socket";
    }
    //creating a sockaddr
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    //in case an error occurred during binding
    if (bind(sock, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP address";
    }
    //in case of an error in the listening part
    if (listen(sock, 1) == -1) {
        throw "Error during listen command";
    }
}

//this function opens thread
void Server::run() {
    if (this->connect()){
        thread* serverThread = new thread(&Server::readData,this);
        serverThread->detach();
    }
}

bool Server::connect() {
    //accepting the client
    client_socket = accept(sock, (struct sockaddr *) &address, (socklen_t *) &address);
    //in case of a client accepting error
    if (client_socket == -1) {
        throw "Could not accept the client";
    }
    close(sock);
    return true;
}

//this function reads the data as long as the parser is parsing
void Server::readData() {
    string data;
    int valRead;
    char buffer[1024];
    while (!Data::get_data()->isParserDone()) {
        valRead = read(client_socket, buffer, 1024);
        data.append(buffer, valRead);
        //if there are no \n in the buffer, read the whole info from buffer
        while (data.find('\n') == string::npos) {
            int currRead;
            currRead = read(client_socket, buffer, 1024);
            data.append(buffer);
            valRead += currRead;
        }
        //takes the exact data from the buffer
        string exactData = data.substr(0, data.find('\n'));
        //deletes all the data from the line after \n
        data.erase(0, data.find('\n') + 1);
        update(exactData);
    }
}

//this function receives the line from the buffer and updates the values
void Server::update(string data) {
    Variable *var;
    int i = 0, curr = 0, comma;
    string info;
    while (i < 36) {
        comma = data.find_first_of(',', curr);
        info = (comma != -1 ? data.substr(curr, comma - curr) : data.substr(curr));
        if ((var = Data::get_data()->getIndexTable().at(i))->getSimDirection() == "<-") {
            var->setValue(stod(info));
        }
        curr += info.size();
        curr++; //skipping the comma
        i++;
    }
}

//dtor
Server::~Server() {}
