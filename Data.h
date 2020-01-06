//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H
#include <unordered_map>
#include <queue>
#include <string>
#include "ex1.h"
#include "Command.h"
#include "Interpreter.h"
#include "PrintCommand.h"
#include "OpenServerCommand.h"
#include "SleepCommand.h"
#include "ConnectServerCommand.h"
#include "DefineVarCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "SetVarCommand.h"

//this is a singleton class
using namespace std;

class Data {
    //ctor
    Data();

    //private methods
    void make_command_map();
    void make_sim_map();


public:
    unordered_map<string, Command*> _command_table;
    unordered_map<string, Variable*> _sim_table;
    unordered_map<string, Variable*> _symbol_table;
    ununordered_map<int, VaVariable*> _index_table;
    Interpreter _interpreter;
    queue<Variable*> _output;

    static Data& get_data() {
        static Data data;
        return data;
    }

    virtual ~Data();

    Data(Data const&) = delete;
    void operator=(Data const&) = delete;
};


#endif //PROJECT_DATA_H
