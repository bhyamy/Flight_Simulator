//
// Created by bhyamy on 1/3/20.
//

#include "Parser.h"


Parser::Parser() = default;

void Parser::run_commands(Lexer lexer) {
    bool checking_for_set = true;
    auto iter = lexer._vec->begin();
    while (iter != lexer._vec->end()) {
        auto cmd_iter = Data::get_data()._command_table.find(*iter);
        if (cmd_iter == Data::get_data()._command_table.end()) {
            if (checking_for_set) {
                iter++;
                checking_for_set = false;
                continue;
            }
            throw ("Parser could not find command");
        }
        iter += cmd_iter->second->execute(iter);
        checking_for_set = true;
    }

    //todo add joins to the threads and end the threads of the server and client
}
