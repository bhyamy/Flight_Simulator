//
// Created by bhyamy on 1/2/20.
//

#include "IfCommand.h"

//ctor
IfCommand::IfCommand() {}

/*this function activates an if block, first it checks the condition,
 if true activates the block inside, else continues on commands execution*/
int IfCommand::execute(vector<string>::iterator iter) {
    string condition = *iter;
    int sum = 1;
    iter++;
    if (Data::get_data()->getInterpreter()->interpret(condition)->calculate()) {
        iter++;
        sum += execute_block(iter);
    } else {
        while (*iter != "}")
            sum++;
    }
    return sum;
}

//dtor
IfCommand::~IfCommand() {}
