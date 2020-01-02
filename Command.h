//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
#include <string>
using namespace std;

class Command {
public:
    virtual int execute(string str[]) = 0;
};


#endif //PROJECT_COMMAND_H
