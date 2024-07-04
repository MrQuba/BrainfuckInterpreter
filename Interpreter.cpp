#include "Interpreter.hpp"

void Interpreter::modifyArr(Pointer& ptr, Code& code, Index& index){
    switch (code[index]) {
    case '+':
        (*ptr)++;
        break;
    case '-':
        (*ptr)--;
        break;
    case '>':
        ptr++;
        break;
    case '<':
        ptr--;
        break;
    case '[':
        loopLogic(code, ptr, index);
        break;
    case '.':
        putchar(*ptr);
        break;
    case ',':
        (*ptr) = (int)getchar();
        break;
    default:
        throw std::runtime_error("[ERROR] There is an unknown character");
    }
}

void Interpreter::loopLogic(Code& code, Pointer& ptr, Index& index) {
    int loopStart = index;
    int loopEnd;
    try {
        loopEnd = findMatchingBracket(code, index);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    while (*ptr > 0) {
        int innerIndex = loopStart + 1;
        while (innerIndex < loopEnd) {
            try {
                modifyArr(ptr, code, innerIndex);
            }
            catch(const std::runtime_error& e){
                std::cerr << e.what() << std::endl;
            }
            innerIndex++;
        }
    }
    index = loopEnd;
}

Index Interpreter::findMatchingBracket(Code& code, Index startIndex) {
    Index counter = 1;
        for (Index i = startIndex + 1; i < code.length(); i++) {
            if (code[i] == '[') counter++;
            if (code[i] == ']') counter--;
            if (counter == 0) return i;
        }
        throw std::runtime_error("[ERROR] No matching closing bracket found.");
    }
