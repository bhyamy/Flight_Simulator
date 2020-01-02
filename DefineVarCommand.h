//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_DEFINEVARCOMMAND_H
#define AP_PROJECT_DEFINEVARCOMMAND_H


#include <vector>
#include "Command.h"
#include "Data.h"

class DefineVarCommand : public Command{
public:
    DefineVarCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //AP_PROJECT_DEFINEVARCOMMAND_H
