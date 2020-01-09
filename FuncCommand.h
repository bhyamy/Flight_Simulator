//
// Created by bhyamy on 1/9/20.
//

#ifndef AP_PROJECT_FUNCCOMMAND_H
#define AP_PROJECT_FUNCCOMMAND_H

#include "BlockCommand.h"


class FuncCommand : public BlockCommand {
public:
    FuncCommand();

    virtual ~FuncCommand();

    int execute(vector<string>::iterator iter) override;

};


#endif //AP_PROJECT_FUNCCOMMAND_H
