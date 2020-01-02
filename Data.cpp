//
// Created by iris on 31/12/2019.
//

#include "Data.h"

Data::Data() {
    make_command_map();
    make_sim_map();
    _interpreter = Interpreter(&_symbol_table);
}

Data::~Data() {}

void Data::make_command_map() {

}

void Data::make_sim_map() {

}
