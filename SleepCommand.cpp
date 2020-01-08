//
// Created by iris on 31/12/2019.
//

#include "SleepCommand.h"


using namespace std;

//ctor
SleepCommand::SleepCommand() {}

//this function sends the thread to sleep
int SleepCommand::execute(vector<string>::iterator iter) {
    double sleeper = Data::get_data()->getInterpreter()->interpret(*iter)->calculate();
    this_thread::sleep_for(chrono::milliseconds((int)sleeper));
    return 1;
}

//dtor
SleepCommand::~SleepCommand() {}


