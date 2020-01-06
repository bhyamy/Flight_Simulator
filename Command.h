//
// Created by iris on 30/12/2019.
//

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
#include <string>
using namespace std;

/*this is an abstract interface, all the commands are inheriting from this class,
 each class implementing the execute command differently*/
class Command {
public:
    virtual int execute(vector<string>::iterator iter) = 0;
};


#endif //PROJECT_COMMAND_H
