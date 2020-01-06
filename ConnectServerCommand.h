//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_CONNECTSERVERCOMMAND_H
#define AP_PROJECT_CONNECTSERVERCOMMAND_H

#include <vector>
#include "Command.h"
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Data.h"
#include "Client.h"

//this class is a client connecting to a server
class ConnectServerCommand : public Command {
    void update(const string &line1);
    void openSocket(string ip, int port);
public:
    int execute(vector<string>::iterator iter) override;
    ConnectServerCommand();
};


#endif //AP_PROJECT_CONNECTSERVERCOMMAND_H
