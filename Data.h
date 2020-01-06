//
// Created by iris on 31/12/2019.
//

#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H
#include <unordered_map>
#include <queue>
#include <string>
#include "ex1.h"
#include "Interpreter.h"
#include "Command.h"


//this is a singleton class
using namespace std;

class Data {
    //ctor
    static Data* _data;
    Data();


    //private methods
    void make_command_map();
    void make_sim_map();
    // data members
    unordered_map<string, Command*> _command_table;
    unordered_map<string, Variable*> _sim_table;
    unordered_map<string, Variable*> _symbol_table;
    unordered_map<int, Variable*> _index_table;
    Interpreter* _interpreter;
    queue<string> _output;
    bool _is_parser_done;


public:
    static Data* get_data();

    virtual ~Data();

    Data(Data const&) = delete;
    void operator=(Data const&) = delete;

    unordered_map<string, Command*> &getCommandTable();

    unordered_map<string, Variable*> &getSimTable();

    unordered_map<string, Variable*> &getSymbolTable();

    unordered_map<int, Variable*> &getIndexTable();

    Interpreter * getInterpreter();

    queue<string> &getOutput();

    void setIsParserDone(bool isParserDone);

    bool isParserDone();

};


#endif //PROJECT_DATA_H
