//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_SETVARCOMMAND_H
#define AP_PROJECT_SETVARCOMMAND_H

#include <vector>
#include "Command.h"
#include "Data.h"
#include <unordered_map>

class SetVarCommand : public Command{
public:
    SetVarCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //AP_PROJECT_SETVARCOMMAND_H
