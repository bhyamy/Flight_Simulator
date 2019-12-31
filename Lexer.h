//
// Created by iris on 26/12/2019.
//

#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H
#include <vector>
#include <iostream>
using namespace std;


class Lexer {
    void manage_String(string string1);
public:
    Lexer();
    vector<string>* _vec;
    void read_File();
};


#endif //PROJECT_LEXER_H
