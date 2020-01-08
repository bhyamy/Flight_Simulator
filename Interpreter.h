


#ifndef EX1IRIS_INTERPRETER_H
#define EX1IRIS_INTERPRETER_H
#include <iostream>
#include "Expression.h"
#include <unordered_map>
#include <regex>
#include <queue>
#include <stack>
#include "ex1.h"
using namespace std;

class Interpreter {
    unordered_map<string, Variable*> *values;
public:
    Interpreter(unordered_map<string, Variable *> *values1);

    Interpreter();

    void setVariables(const string& variables);
    Expression* interpret(string e);

    virtual ~Interpreter();

};


#endif //EX1IRIS_INTERPRETER_H
