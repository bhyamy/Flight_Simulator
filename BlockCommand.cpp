//
// Created by bhyamy on 1/5/20.
//

#include "BlockCommand.h"

//ctor
BlockCommand::BlockCommand() {}

//this function executes command block and stops once it recognizes "}"
int BlockCommand::execute_block(vector<string>::iterator iter) {
    int return_sum = 0, temp;
    bool checking_for_set = true;
    iter++; // starting after the '{'
    while (*iter != "}") {
        auto cmd_iter = Data::get_data()->getCommandTable().find(*iter);
        if (cmd_iter == Data::get_data()->getCommandTable().end()) {
            if (checking_for_set) {
                iter++;
                checking_for_set = false;
                continue;
            }
            throw ("Parser could not find command");
        }
        iter++;
        temp = cmd_iter->second->execute(iter);
        iter += temp;
        return_sum += temp;
        checking_for_set = true;
    }
    return return_sum;
}

//dtor
BlockCommand::~BlockCommand() {}
