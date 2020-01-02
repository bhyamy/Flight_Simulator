//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_CONNECTSERVERCOMMAND_H
#define AP_PROJECT_CONNECTSERVERCOMMAND_H

#include <vector>
#include "Command.h"

class ConnectServerCommand : public Command {
public:
    int execute(vector<string>::iterator iter) override;
    ConnectServerCommand();
};


#endif //AP_PROJECT_CONNECTSERVERCOMMAND_H
