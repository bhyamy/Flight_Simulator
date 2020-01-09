//
// Created by bhyamy on 1/2/20.
//

#include "WhileCommand.h"

//ctor
WhileCommand::WhileCommand() {}

/*this function activates a while block, it checks the condition in every iteration
 if true activates the block inside, else continues on commands execution*/
int WhileCommand::execute(vector<string>::iterator iter) {
    int return_sum = 1;
    string condition = *iter;
    iter++;
    while (Data::get_data()->getInterpreter()->interpret(condition)->calculate()) {
        execute_block(iter);
    }
    //adds to return_sum the number of strings it needs to advance for the next string in the lexers string vector
    while (*iter != "}") {
        iter++;
        return_sum++;
    }
    return ++return_sum;
}

//dtor
WhileCommand::~WhileCommand() {}
