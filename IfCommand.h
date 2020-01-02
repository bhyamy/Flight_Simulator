//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_IFCOMMAND_H
#define AP_PROJECT_IFCOMMAND_H

#include <vector>
#include "Command.h"

class IfCommand : public Command{
public:
    IfCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //AP_PROJECT_IFCOMMAND_H
