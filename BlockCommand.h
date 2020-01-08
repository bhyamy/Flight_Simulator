//#include "Data.h"
// Created by bhyamy on 1/5/20.
//

#ifndef AP_PROJECT_BLOCKCOMMAND_H
#define AP_PROJECT_BLOCKCOMMAND_H

#include <vector>
#include "Command.h"
#include "Data.h"

class BlockCommand : public Command {
protected:
    int execute_block(vector<string>::iterator iter);
public:
    virtual int execute(vector<string>::iterator iter) = 0;

public:
    BlockCommand();

    virtual ~BlockCommand();
};


#endif //AP_PROJECT_BLOCKCOMMAND_H
