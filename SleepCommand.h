//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H
#include "Command.h"
#include <thread>
#include "Data.h"
#include <thread>

class SleepCommand : public Command {
public:
    SleepCommand();
    int execute(vector<string>::iterator iter) override;

    virtual ~SleepCommand();
};


#endif //PROJECT_SLEEPCOMMAND_H
