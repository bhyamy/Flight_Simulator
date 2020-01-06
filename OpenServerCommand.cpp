//
// Created by iris on 30/12/2019.
//

#include "OpenServerCommand.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "Data.h"
using namespace std;

//ctor
OpenServerCommand::OpenServerCommand() {}

/*this function opens a server that listens to port 5400,
receives the information line by line*/
void OpenServerCommand::openSocket(int port) {
    //socket opening - a TCP protocol
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    //in case of socket opening error
    if (socketfd == -1) {
        throw "Could not open socket";
    }
    //creating a sockaddr
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    //in case an error occurred during binding
    if (bind(socketfd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        throw "Could not bind the socket to an IP address";
    }
    //in case of an error in the listening part
    if (listen(socketfd, 1) == - 1) {
        throw "Error during listen command";
    }
    //accepting the client
    int client_socket = accept(socketfd, (struct sockaddr*) &server_address, (socklen_t*) &server_address);
    //in case of a client accepting error
    if (client_socket == -1) {
        throw "Could not accept the client";
    }
    //reading from the client line by line (\n to \n)
    string buffer;
    string line;
    int n, enter;
    char buff[1024] = {0};
    bool reading = false;
    while (n = read(client_socket, buff, 1024)) {
        buffer.assign(buff);
        enter = buffer.find_first_of('\n');
        if (enter == string::npos) {
            if (reading) {
                line += buffer;
            }
        } else {
            if (reading) {
                line += buffer.substr(0, enter);
                update(line);
                reading = false;
                //in case that we didn't get the \n yet and we are not reading
            } else {
                int new_enter = buffer.find_first_of('\n', enter + 1);
                if (new_enter == string::npos) {
                    reading = true;
                    line = buffer.substr(enter + 1);
                } else {
                    line = buffer.substr(enter + 1, new_enter - (enter + 1));
                    update(line);
                }
            }
        }
    }
    close(socketfd);
}

//this function opens the thread that runs the communication with the client
int OpenServerCommand::execute(vector<string>::iterator iter) {
    thread server(&OpenServerCommand::openSocket, this, (int)Data::get_data()._interpreter.interpret(*iter)->calculate());

    return 1;
}

//this function receives the line from the buffer and updates the values
void OpenServerCommand::update(const string &line1) {
    Variable* var;
    int i = 0, curr = 0, comma;
    string info;
    while (i < 36) {
        comma = line1.find_first_of(',', curr);
        info = (comma != -1 ? line1.substr(curr, comma - curr) : line1.substr(curr));
        if ((var = Data::get_data()._index_table.at(i))->sim_Direction == "<-") {
            var->setValue(stod(info));
        }
        curr++;
        i++;
    }
}


