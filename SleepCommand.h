//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H
#include "Command.h"

class SleepCommand : Command {
    int execute(string *str) override;
};


#endif //PROJECT_SLEEPCOMMAND_H
