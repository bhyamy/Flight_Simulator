//
// Created by bhyamy on 12/31/19.
//

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "Command.h"
#include "Data.h"
#include <iostream>
#include <vector>
using namespace std;

class PrintCommand : public Command {
public:
    int execute(vector<string>::iterator iter) override;
    PrintCommand();
};


#endif //PROJECT_PRINTCOMMAND_H
