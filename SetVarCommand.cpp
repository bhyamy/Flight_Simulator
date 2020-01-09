//
// Created by bhyamy on 1/2/20.
//

#include "SetVarCommand.h"

//ctor
SetVarCommand::SetVarCommand() = default;

//this function changes the value of the variable according to the data that was given
int SetVarCommand::execute(vector<string>::iterator iter) {
    iter -= 2;
    auto var_iter = Data::get_data()->getSymbolTable().find(*iter);
    if (var_iter == Data::get_data()->getSymbolTable().end()) {
        throw ("Could not set variable, variable does not exist.");
    }
    Variable* var = var_iter->second;
    iter += 2;
    var->setValue(Data::get_data()->getInterpreter()->interpret(*iter)->calculate());
    //in case a variable needs to update the simulator
    if (var->getSimDirection() == "->") {
        Data::get_data()->getOutput().push("set " + var->getSimAddress() + " " + to_string(var->getValue()) + "\r\n");
    }
    return 1;
}

//dtor
SetVarCommand::~SetVarCommand() {}
