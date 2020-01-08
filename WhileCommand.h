//
// Created by bhyamy on 1/2/20.
//

#ifndef AP_PROJECT_WHILECOMMAND_H
#define AP_PROJECT_WHILECOMMAND_H

#include "BlockCommand.h"



class WhileCommand : public BlockCommand {
public:
    WhileCommand();
    int execute(vector<string>::iterator iter) override;

    virtual ~WhileCommand();
};


#endif //AP_PROJECT_WHILECOMMAND_H
