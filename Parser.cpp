//
// Created by bhyamy on 1/3/20.
//

#include "Parser.h"

//ctor
Parser::Parser() = default;

//this function iterates through the lexers string vector, identifies commands and executes them
void Parser::run_commands(Lexer lexer) {
    bool checking_for_set = true;
    bool first_paren;
    int paren_count;
    auto iter = lexer._vec->begin();
    while (iter != lexer._vec->end()) {
        auto cmd_iter = Data::get_data()->getCommandTable().find(*iter);
        if (cmd_iter == Data::get_data()->getCommandTable().end()) {
            auto func_iter = Data::get_data()->getFuncTable().find(*iter);
            if (func_iter == Data::get_data()->getFuncTable().end()) {
                iter++;
                if (*iter == "var") {
                    iter--;
                    Data::get_data()->getFuncTable()[*iter] = (iter++);
                    //skip over the function block
                    paren_count = 1;
                    first_paren = true;
                    while (paren_count) {
                        if (*iter == "{") {
                            if (first_paren) {
                                first_paren = false;
                                paren_count--;
                            }
                            paren_count++;
                        } else if (*iter == "}")
                            paren_count--;
                        iter++;
                    }
                    continue;
                } else {
                    if (checking_for_set) {
                        checking_for_set = false;
                        continue;
                    }
                    throw ("Parser could not find command");
                }
            } else {
               //found it - activate funcCommand
                cmd_iter = Data::get_data()->getCommandTable().find("func");
            }
        }
        iter++;
        iter += cmd_iter->second->execute(iter);
        checking_for_set = true;
    }
}

//dtor
Parser::~Parser() {}
