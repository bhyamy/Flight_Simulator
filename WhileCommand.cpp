//
// Created by bhyamy on 1/2/20.
//

#include "WhileCommand.h"

//ctor
WhileCommand::WhileCommand() {}

int WhileCommand::execute(vector<string>::iterator iter) {
    int return_sum = 1;
    string condition = *iter;
    iter++;
    while (Data::get_data()->getInterpreter()->interpret(condition)->calculate()) {
        iter -= execute_block(iter);
    }
    while (*iter != "}") {
        iter++;
        return_sum++;
    }
    iter++;
    return return_sum;
}
