//
// Created by bhyamy on 1/2/20.
//

#include "DefineVarCommand.h"

//ctor
DefineVarCommand::DefineVarCommand() {}

int DefineVarCommand::execute(vector<string>::iterator iter) {
    string name = *iter;
    iter++;
    string  sign = *iter;
    iter++;
    string value = *iter;
    iter++;
    if (sign == "=") {
        Data::get_data()._symbol_table[name] =
                new Variable(name, Data::get_data()._interpreter.interpret(value)->calculate());
        return 0; //TODO check if the inner iter ++ advance the outer iter - if not return 3
    }
    if (sign == "->" || sign == "<-") {
        string sim = *iter;
        iter++; //TODO check if the inner iter ++ advance the outer iter - if not delete this line
        auto sim_iter = Data::get_data()._sim_table.find(sim);
        if (sim_iter == Data::get_data()._sim_table.end()) {
            throw ("Could not find sim address in current table");
        }
        Variable* var = sim_iter->second;
        var->setSimDirection(sign);
        Data::get_data()._symbol_table[name] = var;
        return 0; //TODO check if the inner iter ++ advance the outer iter - if not return 4
    }
    throw ("ERROR - could not define variable.");
}