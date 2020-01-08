//
// Created by bhyamy on 1/2/20.
//

#include "ConnectServerCommand.h"

//ctor
ConnectServerCommand::ConnectServerCommand() {}

//this function creates the client, calls to open thread by run function
int ConnectServerCommand::execute(vector<string>::iterator iter) {
    string ip = (*iter).substr(1);
    ip.pop_back();
    Client* client = new Client(ip, (int) Data::get_data()->getInterpreter()->interpret(*(++iter))->calculate());
    client->run();
    iter++;
    return 2;
}

//dtor
ConnectServerCommand::~ConnectServerCommand() {}




