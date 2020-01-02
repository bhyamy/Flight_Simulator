//
// Created by iris on 31/12/2019.
//

#include "SleepCommand.h"
#include <thread>
#include <string>
#include <iostream>
using namespace std;

int SleepCommand::execute(string *str) {
    int sleeper = stoi(*str);
    this_thread::sleep_for(chrono::milliseconds(sleeper));
}
