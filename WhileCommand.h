//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_WHILECOMMAND_H
#define AP_PROJECT_WHILECOMMAND_H

#include <vector>
#include "Command.h"

class WhileCommand : public Command{
public:
    WhileCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //AP_PROJECT_WHILECOMMAND_H
