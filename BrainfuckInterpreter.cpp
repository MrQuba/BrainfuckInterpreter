#include <iostream>
#include "Interpreter.hpp"
#include "Typedefs.hpp";

using namespace std;
using namespace Types;

int main() {
    // Definition of size of the program array
    Size CODE_SIZE = 1024;
    // Definition of code to interpret
    Code code = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    // Definition of program array
    Program arr[CODE_SIZE] = { 0 };
    // Definition of pointer to program array;
    Pointer ptr = arr;
    // Definition of index
    Index index = 0;
    // Loop responsible for interpreting
    while (index < code.length()) {
        try {
            Interpreter::modifyArr(ptr, code, index);
        }
        catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
        index++;
    }
    return EXIT_SUCCESS;
}