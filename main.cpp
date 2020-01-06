#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Data.h"

using namespace std;

int main() {
    Data::get_data();
    Lexer lexer;
    Parser parser;
    try {
        lexer.read_File();
        parser.run_commands(lexer);
    } catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}
