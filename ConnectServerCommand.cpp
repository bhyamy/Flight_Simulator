//
// Created by bhyamy on 1/2/20.
//

#include "ConnectServerCommand.h"




//ctor
ConnectServerCommand::ConnectServerCommand() {}

//void ConnectServerCommand::openSocket(string ip, int port) {
   /* //creating the socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    //in case of error in socket opening
    if (client_socket == -1) {
        throw "Could not create client socket";
    }
    //creating a sockaddr to hold the address of the server
    sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr(ip.c_str());
    client_address.sin_port = htons(port);
    //connecting to a server
    int is_connect = connect(client_socket, (struct sockaddr*) &client_address, sizeof(client_address));
    //in case connection failed
    if (is_connect == -1) {
        throw "Could not connect to the server";
    } else {
        cout << "Connected to server" << endl;
    }

    close(client_socket);*/
}

int ConnectServerCommand::execute(vector<string>::iterator iter) {
    Client* client = new Client(*iter, (int) Data::get_data()._interpreter.interpret(*(++iter))->calculate());
    client->run();
    //thread server(&OpenServerCommand::openSocket, this,
    //            (int) Data::get_data()._interpreter.interpret(*iter)->calculate());
    iter++;
    return 1;
    /*thread client(&ConnectServerCommand::openSocket, this,
            (int)Data::get_data()._interpreter.interpret(*iter)->calculate(), *(iter++));
    iter++;
    return 1;*/
}




