//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <vector>
#include "Command.h"
#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Data.h"
#include "Server.h"
using namespace std;


class OpenServerCommand : public Command {
public:
    int execute(vector<string>::iterator iter) override;
    OpenServerCommand();
};


#endif //PROJECT_OPENSERVERCOMMAND_H
