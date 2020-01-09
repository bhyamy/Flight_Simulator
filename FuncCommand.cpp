//
// Created by bhyamy on 1/9/20.
//

#include "FuncCommand.h"

FuncCommand::FuncCommand() {}

FuncCommand::~FuncCommand() {

}

int FuncCommand::execute(vector<string>::iterator iter) {
    auto func_iter = Data::get_data()->getFuncTable().find(*(--iter));
    if (func_iter == Data::get_data()->getFuncTable().end())
        throw ("could not find function.");
    auto block_iter = func_iter->second;
    block_iter++;
    string name = *(++block_iter);
    double value = Data::get_data()->getInterpreter()->interpret(*(++iter))->calculate();
    Data::get_data()->getSymbolTable()[name] = new Variable(name, value);
    execute_block(block_iter);
    Data::get_data()->getSymbolTable().erase(name);
    return 1;
}
