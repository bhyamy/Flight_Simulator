//
// Created by bhyamy on 1/5/20.
//

#include "BlockCommand.h"

BlockCommand::BlockCommand() = default;

int BlockCommand::execute_block(vector<string>::iterator iter) {
    int return_sum = 1, temp;
    bool checking_for_set = true;
    iter++; // starting after the '{'
    while (*iter != "}") {
        auto cmd_iter = Data::get_data()._command_table.find(*iter);
        if (cmd_iter == Data::get_data()._command_table.end()) {
            if (checking_for_set) {
                iter++;
                checking_for_set = false;
                continue;
            }
            throw ("Parser could not find command");
        }
        temp = cmd_iter->second->execute(iter);
        iter += temp;
        return_sum += temp;
        checking_for_set = true;
    }
    return return_sum;
}
