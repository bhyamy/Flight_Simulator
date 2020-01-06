//
// Created by bhyamy on 1/2/20.
//

#include "IfCommand.h"

//ctor
IfCommand::IfCommand() {}

int IfCommand::execute(vector<string>::iterator iter) {
    string condition = *iter;
    iter++;
    if (Data::get_data()->getInterpreter()->interpret(condition)->calculate()) {
        iter += execute_block(iter);
    } else {
        while (*iter != "}")
            iter++;
    }
    iter++;
}
