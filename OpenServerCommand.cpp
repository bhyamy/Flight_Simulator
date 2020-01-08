//
// Created by iris on 30/12/2019.
//

#include "OpenServerCommand.h"


//ctor
OpenServerCommand::OpenServerCommand() {}

//this function opens the thread that runs the communication with the client
int OpenServerCommand::execute(vector<string>::iterator iter) {
    Server* server = new Server((int) Data::get_data()->getInterpreter()->interpret(*iter)->calculate());
    server->run();
    return 1;
}

//dtor
OpenServerCommand::~OpenServerCommand() {}



