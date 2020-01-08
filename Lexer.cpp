//
// Created by iris on 26/12/2019.
//

#include "Lexer.h"

//ctor
Lexer::Lexer() {
    _vec = new vector<string>;
}

//this method reads the given file, checks specific tokens and handles them accordingly
void Lexer::read_File(string file_name) {
    ifstream file;
    string line;
    int curr, temp;
    string last_Token = " ";
    file.open(file_name);
    //checking that the file opening succeed
    if (!file.is_open()) {
        throw "Could not open file";
    }
    //read each line from the file
    while (getline(file, line)) {
        curr = 0;
        string str;
        bool first_In_Line = true;
        bool remember_If_While = false;
        while (line.size() > curr) {
            if (first_In_Line) {
                str = line.substr(curr, temp = (line.find_first_of(" ", curr) - curr));
                if (str == "while" || str == "if") {
                    remember_If_While = true;
                }
                if (str != "var" && str != "while" && str != "if" && str != "}") {
                    if (remember_If_While) {
                        str = line.substr(curr, temp = (line.find_first_of("({", curr) - curr));
                        remember_If_While = false;
                    } else {
                        str = line.substr(curr, temp = (line.find_first_of(",(-<=\"{", curr) - curr));
                    }
                    first_In_Line = false;
                }
                curr += temp;
                manage_String(str);
            } else if (last_Token == "\"") {
                str = line.substr(curr - 1, (temp = line.find_first_of("\"", curr) - curr) + 1);
                curr += temp;
                _vec->push_back(str);
            } else if (last_Token == "=") {
                _vec->push_back(last_Token);
                str = line.substr(curr);
                curr += str.size();
                manage_String(str);
            } else if (last_Token == "(") {
                int last_P = line.find_last_of(")");
                //run until the end of the parenthesis
                while (curr < last_P) {
                    int first_Q =  line.find_first_of("\"", curr);
                    int first_C =  line.find_first_of(",", curr);
                    //if there is no comma or quote
                    if (first_C == first_Q) {
                        str = line.substr(curr, last_P - curr);
                        curr = last_P;
                        manage_String(str);
                        //if there is no comma, or there is a quote before a comma
                    } else if (first_C == string::npos || (first_Q < first_C && first_Q != string::npos)) {
                        str = line.substr(first_Q, (temp = line.find_first_of("\"", first_Q + 1) - first_Q) + 1);
                        curr += temp;
                        _vec->push_back(str);
                        curr++;
                        //if there is no quote, or there is a comma before a quote
                    } else if (first_Q == string::npos || first_C < first_Q) {
                        str = line.substr(curr, first_C - curr);
                        curr += first_C;
                        manage_String(str);
                        curr++;
                    }
                    curr++;
                }
            } else if (last_Token == "->" || last_Token == "<-") {
                _vec->push_back(last_Token);
                str = line.substr(curr, temp = (line.find_first_of(",(-<=\"", curr) - curr));
                curr += temp;
                manage_String(str);
            } else {
                throw "-1";
            }
            if (curr < line.size()) {
                last_Token = line.substr(curr, 1);
                if (last_Token == "-" || last_Token == "<") {
                    last_Token = line.substr(curr, 2);
                    curr++;
                }
                if (last_Token == "{") {
                    _vec->push_back(last_Token);
                }
                curr++;
            }
        }
    }
    file.close();
}

/*this method receives the string as an argument, trims the trailing spaces
 and tabs, then adds the string into the vector*/
void Lexer::manage_String(string string1) {
    if (!string1.empty()) {
        std::replace(string1.begin(), string1.end(), '\t', ' ');
        string::iterator end_pos = remove(string1.begin(), string1.end(), ' ');
        string1.erase(end_pos, string1.end());
        _vec->push_back(string1);
    }
}

//dtor
Lexer::~Lexer() {}
