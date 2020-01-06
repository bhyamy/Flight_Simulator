//
// Created by bhyamy on 1/2/20.
//

#include "SetVarCommand.h"

//ctor
SetVarCommand::SetVarCommand() = default;

int SetVarCommand::execute(vector<string>::iterator iter) {
    iter--;
    auto var_iter = Data::get_data()->getSymbolTable().find(*iter);
    if (var_iter == Data::get_data()->getSymbolTable().end()) {
        throw ("Could not set variable, variable does not exist.");
    }
    Variable* var = var_iter->second;
    iter += 2;
    var->setValue(Data::get_data()->getInterpreter()->interpret(*iter)->calculate());
    if (var->getSimDirection() == "->") {
        Data::get_data()->getOutput().push("set " + var->getSimAddress() + to_string(var->getValue()));
        //TODO thread lock key for output is required
    }
    return 0; //TODO check if the inner iter ++ advance the outer iter - if not return 2
}
