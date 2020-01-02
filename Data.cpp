//
// Created by iris on 31/12/2019.
//

#include "Data.h"

//ctor
Data::Data() {
    make_command_map();
    make_sim_map();
    _interpreter = Interpreter(&_symbol_table);
}

//dtor
Data::~Data() {}

//this function initalizes the command table commands
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
    string sim2 = "/sim/time/warp";
    _sim_table[sim2] = new Variable("time_warp", sim2, "", 0);
    string sim3 = "/controls/switches/magnetos";
    _sim_table[sim3] = new Variable("switches_magnetos", sim3, "", 0);
    string sim4 = "/instrumentation/heading-indicator/offset-deg";
    _sim_table[sim4] = new Variable("heading-indicator_offset-deg", sim4, "", 0);
    string sim5 = "/instrumentation/altimeter/indicated-altitude-ft";
    _sim_table[sim5] = new Variable("altimeter_indicated-altitude-ft", sim5, "", 0);
    string sim6 = "/instrumentation/altimeter/pressure-alt-ft";
    _sim_table[sim6] = new Variable("altimeter_pressure-alt-ft", sim6, "", 0);
    string sim7 = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    _sim_table[sim7] = new Variable("attitude-indicator_indicated-pitch-deg", sim7, "", 0);
    string sim8 = "/instrumentation/attitude-indicator/indicated-roll-deg";
    _sim_table[sim8] = new Variable("attitude-indicator_indicated-roll-deg", sim8, "", 0);
    string sim9 = "/instrumentation/attitude-indicator/internal-pitch-deg";
    _sim_table[sim9] = new Variable("attitude-indicator_internal-pitch-deg", sim9, "", 0);
    string sim10 = "/instrumentation/attitude-indicator/internal-roll-deg";
    _sim_table[sim10] = new Variable("attitude-indicator_internal-roll-deg", sim10, "", 0);
    string sim11 = "/instrumentation/encoder/indicated-altitude-ft";
    _sim_table[sim11] = new Variable("encoder_indicated-altitude-ft", sim11, "", 0);
    string sim12 = "/instrumentation/encoder/pressure-alt-ft";
    _sim_table[sim12] = new Variable("encoder_pressure-alt-ft", sim12, "", 0);
    string sim13 = "/instrumentation/gps/indicated-altitude-ft";
    _sim_table[sim13] = new Variable("gps_indicated-altitude-ft", sim13, "", 0);
    string sim14 = "/instrumentation/gps/indicated-ground-speed-kt";
    _sim_table[sim14] = new Variable("gps_indicated-ground-speed-kt", sim14, "", 0);
    string sim15 = "/instrumentation/gps/indicated-vertical-speed";
    _sim_table[sim15] = new Variable("gps_indicated-vertical-speed", sim15, "", 0);
    string sim16 = "/instrumentation/heading-indicator/indicated-heading-deg";
    _sim_table[sim16] = new Variable("indicated-heading-deg", sim16, "", 0);
    string sim17 = "/instrumentation/magnetic-compass/indicated-heading-deg";
    _sim_table[sim17] = new Variable("magnetic-compass_indicated-heading-deg", sim17, "", 0);
    string sim18 = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    _sim_table[sim18] = new Variable("slip-skid-ball_indicated-slip-skid", sim18, "", 0);
    string sim19 = "/instrumentation/turn-indicator/indicated-turn-rate";
    _sim_table[sim19] = new Variable("turn-indicator_indicated-turn-rate", sim19, "", 0);
    string sim20 = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    _sim_table[sim20] = new Variable("vertical-speed-indicator_indicated-speed-fpm", sim20, "", 0);
    string sim21 = "/controls/flight/aileron";
    _sim_table[sim21] = new Variable("flight_aileron", sim21, "", 0);
    string sim22 = "/controls/flight/elevator";
    _sim_table[sim22] = new Variable("flight_elevator", sim22, "", 0);
    string sim23 = "/controls/flight/rudder";
    _sim_table[sim23] = new Variable("flight_rudder", sim23, "", 0);
    string sim24 = "/controls/flight/flaps";
    _sim_table[sim24] = new Variable("flight_flaps", sim24, "", 0);
    string sim25 = "/controls/engines/engine/throttle";
    _sim_table[sim25] = new Variable("engine_throttle", sim25, "", 0);
    string sim26 = "/controls/engines/current-engine/throttle";
    _sim_table[sim26] = new Variable("current-engine_throttle", sim26, "", 0);
    string sim27 = "/controls/switches/master-avionics";
    _sim_table[sim27] = new Variable("switches_master-avionics", sim27, "", 0);
    string sim28 = "/controls/switches/starter";
    _sim_table[sim28] = new Variable("switches_starter", sim28, "", 0);
    string sim29 = "/engines/active-engine/auto-start";
    _sim_table[sim29] = new Variable("active-engine_auto-start", sim29, "", 0);
    string sim30 = "/controls/flight/speedbrake";
    _sim_table[sim30] = new Variable("flight_speedbrake", sim30, "", 0);
    string sim31 = "/sim/model/c172p/brake-parking";
    _sim_table[sim31] = new Variable("c172p_brake-parking", sim31, "", 0);
    string sim32 = "/controls/engines/engine/primer";
    _sim_table[sim32] = new Variable("engine_primer", sim32, "", 0);
    string sim33 = "/controls/engines/current-engine/mixture";
    _sim_table[sim33] = new Variable("current-engine_mixture", sim33, "", 0);
    string sim34 = "/controls/switches/master-bat";
    _sim_table[sim34] = new Variable("switches_master-bat", sim34, "", 0);
    string sim35 = "/controls/switches/master-alt";
    _sim_table[sim35] = new Variable("switches_master-alt", sim35, "", 0);
    string sim36 = "/engines/engine/rpm";
    _sim_table[sim36] = new Variable("engine_rpm", sim36, "", 0);
}
