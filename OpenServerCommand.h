//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <vector>
#include "Command.h"
#include "Server.h"

class OpenServerCommand : public Command {
public:
    int execute(vector<string>::iterator iter) override;
    OpenServerCommand();

    virtual ~OpenServerCommand();
};


#endif //PROJECT_OPENSERVERCOMMAND_H
