//
// Created by iris on 31/12/2019.
//

#include "Data.h"
#include "PrintCommand.h"
#include "OpenServerCommand.h"
#include "SleepCommand.h"
#include "ConnectServerCommand.h"
#include "DefineVarCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "SetVarCommand.h"



//ctor
Data::Data() {
    _is_parser_done = false;
    make_command_map();
    make_sim_map();
    _interpreter = new Interpreter(_symbol_table);
}

void Data::setIsParserDone(bool isParserDone) {
    _is_parser_done = isParserDone;
}

Data* Data::_data = 0;

Data* Data::get_data() {
    if (_data == 0) {
        _data = new Data();
    }
    return _data;
}

//dtor
Data::~Data() {
    delete _data;
}

//this function initializes the command table command
void Data::make_command_map() {
    _command_table["Print"] = new PrintCommand();
    _command_table["openDataServer"] = new OpenServerCommand();
    _command_table["connectControlClient"]; new ConnectServerCommand();
    _command_table["Sleep"] = new SleepCommand();
    _command_table["while"] = new WhileCommand();
    _command_table["if"] = new IfCommand();
    _command_table["var"] = new DefineVarCommand();
    _command_table["="] = new SetVarCommand();
}

//this function creates and initializes the sim map variables
void Data::make_sim_map() {
    string sim1 = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    _sim_table[sim1] = new Variable("airspeed-indicator_indicated-speed-kt", sim1, "", 0);
    _index_table[0] = _sim_table.at(sim1);
    string sim2 = "/sim/time/warp";
    _sim_table[sim2] = new Variable("time_warp", sim2, "", 0);
    _index_table[1] = _sim_table.at(sim2);
    string sim3 = "/controls/switches/magnetos";
    _sim_table[sim3] = new Variable("switches_magnetos", sim3, "", 0);
    _index_table[2] = _sim_table.at(sim3);
    string sim4 = "/instrumentation/heading-indicator/offset-deg";
    _sim_table[sim4] = new Variable("heading-indicator_offset-deg", sim4, "", 0);
    _index_table[3] = _sim_table.at(sim4);
    string sim5 = "/instrumentation/altimeter/indicated-altitude-ft";
    _sim_table[sim5] = new Variable("altimeter_indicated-altitude-ft", sim5, "", 0);
    _index_table[4] = _sim_table.at(sim5);
    string sim6 = "/instrumentation/altimeter/pressure-alt-ft";
    _sim_table[sim6] = new Variable("altimeter_pressure-alt-ft", sim6, "", 0);
    _index_table[5] = _sim_table.at(sim6);
    string sim7 = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    _sim_table[sim7] = new Variable("attitude-indicator_indicated-pitch-deg", sim7, "", 0);
    _index_table[6] = _sim_table.at(sim7);
    string sim8 = "/instrumentation/attitude-indicator/indicated-roll-deg";
    _sim_table[sim8] = new Variable("attitude-indicator_indicated-roll-deg", sim8, "", 0);
    _index_table[7] = _sim_table.at(sim8);
    string sim9 = "/instrumentation/attitude-indicator/internal-pitch-deg";
    _sim_table[sim9] = new Variable("attitude-indicator_internal-pitch-deg", sim9, "", 0);
    _index_table[8] = _sim_table.at(sim9);
    string sim10 = "/instrumentation/attitude-indicator/internal-roll-deg";
    _sim_table[sim10] = new Variable("attitude-indicator_internal-roll-deg", sim10, "", 0);
    _index_table[9] = _sim_table.at(sim10);
    string sim11 = "/instrumentation/encoder/indicated-altitude-ft";
    _sim_table[sim11] = new Variable("encoder_indicated-altitude-ft", sim11, "", 0);
    _index_table[10] = _sim_table.at(sim11);
    string sim12 = "/instrumentation/encoder/pressure-alt-ft";
    _sim_table[sim12] = new Variable("encoder_pressure-alt-ft", sim12, "", 0);
    _index_table[11] = _sim_table.at(sim12);
    string sim13 = "/instrumentation/gps/indicated-altitude-ft";
    _sim_table[sim13] = new Variable("gps_indicated-altitude-ft", sim13, "", 0);
    _index_table[12] = _sim_table.at(sim13);
    string sim14 = "/instrumentation/gps/indicated-ground-speed-kt";
    _sim_table[sim14] = new Variable("gps_indicated-ground-speed-kt", sim14, "", 0);
    _index_table[13] = _sim_table.at(sim14);
    string sim15 = "/instrumentation/gps/indicated-vertical-speed";
    _sim_table[sim15] = new Variable("gps_indicated-vertical-speed", sim15, "", 0);
    _index_table[14] = _sim_table.at(sim15);
    string sim16 = "/instrumentation/heading-indicator/indicated-heading-deg";
    _sim_table[sim16] = new Variable("indicated-heading-deg", sim16, "", 0);
    _index_table[15] = _sim_table.at(sim16);
    string sim17 = "/instrumentation/magnetic-compass/indicated-heading-deg";
    _sim_table[sim17] = new Variable("magnetic-compass_indicated-heading-deg", sim17, "", 0);
    _index_table[16] = _sim_table.at(sim17);
    string sim18 = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    _sim_table[sim18] = new Variable("slip-skid-ball_indicated-slip-skid", sim18, "", 0);
    _index_table[17] = _sim_table.at(sim18);
    string sim19 = "/instrumentation/turn-indicator/indicated-turn-rate";
    _sim_table[sim19] = new Variable("turn-indicator_indicated-turn-rate", sim19, "", 0);
    _index_table[18] = _sim_table.at(sim19);
    string sim20 = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    _sim_table[sim20] = new Variable("vertical-speed-indicator_indicated-speed-fpm", sim20, "", 0);
    _index_table[19] = _sim_table.at(sim20);
    string sim21 = "/controls/flight/aileron";
    _sim_table[sim21] = new Variable("flight_aileron", sim21, "", 0);
    _index_table[20] = _sim_table.at(sim21);
    string sim22 = "/controls/flight/elevator";
    _sim_table[sim22] = new Variable("flight_elevator", sim22, "", 0);
    _index_table[21] = _sim_table.at(sim22);
    string sim23 = "/controls/flight/rudder";
    _sim_table[sim23] = new Variable("flight_rudder", sim23, "", 0);
    _index_table[22] = _sim_table.at(sim23);
    string sim24 = "/controls/flight/flaps";
    _sim_table[sim24] = new Variable("flight_flaps", sim24, "", 0);
    _index_table[23] = _sim_table.at(sim24);
    string sim25 = "/controls/engines/engine/throttle";
    _sim_table[sim25] = new Variable("engine_throttle", sim25, "", 0);
    _index_table[24] = _sim_table.at(sim25);
    string sim26 = "/controls/engines/current-engine/throttle";
    _sim_table[sim26] = new Variable("current-engine_throttle", sim26, "", 0);
    _index_table[25] = _sim_table.at(sim26);
    string sim27 = "/controls/switches/master-avionics";
    _sim_table[sim27] = new Variable("switches_master-avionics", sim27, "", 0);
    _index_table[26] = _sim_table.at(sim27);
    string sim28 = "/controls/switches/starter";
    _sim_table[sim28] = new Variable("switches_starter", sim28, "", 0);
    _index_table[27] = _sim_table.at(sim28);
    string sim29 = "/engines/active-engine/auto-start";
    _sim_table[sim29] = new Variable("active-engine_auto-start", sim29, "", 0);
    _index_table[28] = _sim_table.at(sim29);
    string sim30 = "/controls/flight/speedbrake";
    _sim_table[sim30] = new Variable("flight_speedbrake", sim30, "", 0);
    _index_table[29] = _sim_table.at(sim30);
    string sim31 = "/sim/model/c172p/brake-parking";
    _sim_table[sim31] = new Variable("c172p_brake-parking", sim31, "", 0);
    _index_table[30] = _sim_table.at(sim31);
    string sim32 = "/controls/engines/engine/primer";
    _sim_table[sim32] = new Variable("engine_primer", sim32, "", 0);
    _index_table[31] = _sim_table.at(sim32);
    string sim33 = "/controls/engines/current-engine/mixture";
    _sim_table[sim33] = new Variable("current-engine_mixture", sim33, "", 0);
    _index_table[32] = _sim_table.at(sim33);
    string sim34 = "/controls/switches/master-bat";
    _sim_table[sim34] = new Variable("switches_master-bat", sim34, "", 0);
    _index_table[33] = _sim_table.at(sim34);
    string sim35 = "/controls/switches/master-alt";
    _sim_table[sim35] = new Variable("switches_master-alt", sim35, "", 0);
    _index_table[34] = _sim_table.at(sim35);
    string sim36 = "/engines/engine/rpm";
    _sim_table[sim36] = new Variable("engine_rpm", sim36, "", 0);
    _index_table[35] = _sim_table.at(sim36);
}

unordered_map<string, Command*> &Data::getCommandTable() {
    //todo mutex
    return _command_table;
}

unordered_map<string, Variable*> &Data::getSimTable() {
    //todo mutex
    return _sim_table;
}

unordered_map<string, Variable*> &Data::getSymbolTable() {
    //todo mutex
    return _symbol_table;
}

unordered_map<int, Variable*> &Data::getIndexTable() {
    //todo mutex
    return _index_table;
}

Interpreter * Data::getInterpreter() {
    //todo mutex
    return _interpreter;
}

queue<string> &Data::getOutput() {
    //todo mutex
    return _output;
}

bool Data::isParserDone() {
    return _is_parser_done;
}
