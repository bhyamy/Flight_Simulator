//
// Created by bhyamy on 1/3/20.
//

#ifndef AP_PROJECT_PARSER_H
#define AP_PROJECT_PARSER_H

#include "Data.h"
#include "Lexer.h"

class Parser {

public:
    Parser();
    static void run_commands(Lexer lexer);
};


#endif //AP_PROJECT_PARSER_H
