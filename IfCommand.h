//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_IFCOMMAND_H
#define AP_PROJECT_IFCOMMAND_H

#include <vector>
#include "BlockCommand.h"
#include "Data.h"

class IfCommand : public BlockCommand{
public:
    IfCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //AP_PROJECT_IFCOMMAND_H
