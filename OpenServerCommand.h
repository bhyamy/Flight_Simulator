//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <vector>
#include "Command.h"


class OpenServerCommand : public Command {
    int openServer();
public:
    int execute(vector<string>::iterator iter) override;
    void openDataServer();
    OpenServerCommand();
};


#endif //PROJECT_OPENSERVERCOMMAND_H
