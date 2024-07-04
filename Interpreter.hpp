#include <iostream>
#include "Typedefs.hpp"
#pragma once
using namespace Types;
class Interpreter {
public:
    /// <summary>
    /// Modifies array
    /// </summary>
    /// <param name="ptr">Pointer to array</param>
    /// <param name="code">Code of program</param>
    /// <param name="index">Index of code</param>
    static void modifyArr(Pointer& ptr, Code& code, Index& index);
private:
    /// <summary>
    /// Logic for loops
    /// </summary>
    /// <param name="code">Code of program</param>
    /// <param name="ptr">Pointer to array</param>
    /// <param name="index">Index of code</param>
    static void loopLogic(Code& code, Pointer& ptr, Index& index);
    /// <summary>
    /// Searches for closing bracket
    /// </summary>
    /// <param name="code">Code of program</param>
    /// <param name="startIndex">Index of bracket</param>
    /// <returns>Index of bracket</returns>
    static Index findMatchingBracket(Code& code, Index startIndex);
};