//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_IFCOMMAND_H
#define AP_PROJECT_IFCOMMAND_H

#include "BlockCommand.h"


class IfCommand : public BlockCommand {
public:
    IfCommand();
    int execute(vector<string>::iterator iter) override;

    virtual ~IfCommand();
};


#endif //AP_PROJECT_IFCOMMAND_H
