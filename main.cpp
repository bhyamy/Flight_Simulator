#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    Lexer lexer;
    try {
        lexer.read_File();
        cout << lexer._vec << endl;
    } catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}
