//
// Created by bhyamy on 12/31/19.
//

#include "PrintCommand.h"

int PrintCommand::execute(string *str) {
    string first = str[0];
    if (first.front() == '\"') {
        first.pop_back();
        first = first.substr(1);
        cout << first << endl;
    } else {

    }

    return 1;
}
