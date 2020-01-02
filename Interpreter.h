#include <iostream>
#include "Expression.h"
#include <map>
#include <regex>
#include <queue>
#include <stack>


using namespace std;
#ifndef EX1IRIS_INTERPRETER_H
#define EX1IRIS_INTERPRETER_H


class Interpreter {
    map<string, double>* values;
public:
    Interpreter();
    void setVariables(const string& variables);
    Expression* interpret(string e);
    virtual ~Interpreter();

};


#endif //EX1IRIS_INTERPRETER_H
