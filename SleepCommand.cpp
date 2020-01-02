//
// Created by iris on 31/12/2019.
//

#include "SleepCommand.h"
#include <thread>

using namespace std;

//ctor
SleepCommand::SleepCommand() {}

//sends the thread to sleep
int SleepCommand::execute(vector<string>::iterator iter) {
    double sleeper = Data::get_data()._interpreter.interpret(*iter)->calculate();
    this_thread::sleep_for(chrono::milliseconds((int)sleeper));
    return 1;
}


