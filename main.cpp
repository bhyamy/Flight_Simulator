#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Data.h"

using namespace std;

int main(int argc, char** argv) {
    (void)argc;
    Lexer lexer;
    Data::get_data();
    try {
        lexer.read_File(argv[1]);
        Parser::run_commands(lexer);
    } catch (const char* e) {
        cout << e << endl;
    }
    Data::get_data()->setIsParserDone(true);
    return 0;
}
