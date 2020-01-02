//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H
#include "Command.h"
#include "Data.h"

class SleepCommand : Command {
public:
    virtual int execute(vector<string>::iterator iter);
};


#endif //PROJECT_SLEEPCOMMAND_H
