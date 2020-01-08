//
// Created by iris on 06/01/2020.
//

#include "Client.h"

Client::Client(string ip, int port) {
    //creating the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //in case of error in socket opening
    if (sock == -1) {
        throw "Could not create client socket";
    }
    //creating a sockaddr to hold the address of the server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip.c_str());
    address.sin_port = htons(port);
}

//requesting connection with server, if true server is connected
bool Client::connection() {
    bool is_connect = false;
    while (!is_connect) {
        int try_connect = connect(sock, (struct sockaddr *) &address, sizeof(address));
        //in case connection failed
        if (try_connect == -1) {
            cout << "Could not connect to host server" << endl;
        } else {
            cout << "Client is now connected to server" << endl;
            is_connect = true;
        }
    }
    return is_connect;
}

//creating a thread after connection was made
void Client::run() {
    if (connection()) {
        thread* clientThread = new thread(&Client::send_Data, this);
        clientThread->detach();
    }
}

//this function sends data to the server
void Client::send_Data() {
    while (!Data::get_data()->isParserDone()) {
        while (!Data::get_data()->getOutput().empty()) {
            string content = Data::get_data()->getOutput().front();
            Data::get_data()->getOutput().pop();
            int is_sent = send(sock, content.c_str(), content.size(), 0);
            if (is_sent == -1) {
                cout << "Could not send message" << endl;
            }
        }
    }
}

//dtor
Client::~Client() {}
