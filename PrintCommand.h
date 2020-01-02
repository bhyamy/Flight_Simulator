//
// Created by bhyamy on 12/31/19.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"
#include <iostream>
using namespace std;

class PrintCommand : Command {
    int execute(string *str) override;
};


#endif //PROJECT_PRINTCOMMAND_H
