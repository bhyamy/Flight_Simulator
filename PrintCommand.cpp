//
// Created by bhyamy on 12/31/19.
//

#include "PrintCommand.h"

//ctor
PrintCommand::PrintCommand() {}

//this function prints the given string
int PrintCommand::execute(vector<string>::iterator iter) {
    string str = *iter;
    if (str.front() == '\"') {
        str.pop_back();
        cout << str.substr(1) << endl;
    } else {
        cout << Data::get_data()->getInterpreter()->interpret(*iter)->calculate() << endl;
    }
    return 1;
}

//dtor
PrintCommand::~PrintCommand() {}


