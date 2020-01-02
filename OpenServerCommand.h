//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <vector>
#include "Command.h"


class OpenServerCommand : Command {

    int openServer();
public:
    void openDataServer();

private:
    int execute(vector<string>::iterator iter) override;
};


#endif //PROJECT_OPENSERVERCOMMAND_H
