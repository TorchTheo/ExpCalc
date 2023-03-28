#pragma

#include "Expr.h"
#include "Symbol.h"
#include "Var.h"
#include <string>

class Calc {
public:
    Calc();

    Number parse(std::string line);
    Number processAssign(std::string stmt);
    Number processExpression(std::string exp);

    SymbolTable* s_table;
};