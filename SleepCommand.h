//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H
#include "Command.h"
#include "Data.h"

class SleepCommand : public Command {
public:
    SleepCommand();
    int execute(vector<string>::iterator iter) override;
};


#endif //PROJECT_SLEEPCOMMAND_H
