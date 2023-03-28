/*
 * @Author: TorchTheo 2961620012@qq.com
 * @Date: 2023-03-27 09:38:29
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:27:33
 * @FilePath: /ExpCalc/tests/test.cpp
 * @Description: test
 */
#include "../include/Var.h"
#include "../include/utils.h"
#include "../include/Expr.h"
#include "../include/Symbol.h"
#include <iostream>
#include <vector>

int main() {
    #ifdef NUMBER
    Number a(static_cast<long long>(100)), b(static_cast<long long>(3));
    std::cout << "100 + 3 = " << a + b << std::endl;
    std::cout << "100 - 3 = " << a - b << std::endl;
    std::cout << "100 * 3 = " << a * b << std::endl;
    std::cout << "100 / 3 = " << a / b << std::endl;
    Number c(static_cast<float>(2.0)), d(static_cast<float>(3.0));
    std::cout << "2.0 + 3.0 = " << c + d << std::endl;
    std::cout << "2.0 - 3.0 = " << c - d << std::endl;
    std::cout << "2.0 * 3.0 = " << c * d << std::endl;
    std::cout << "2.0 / 3.0 = " << c / d << std::endl;
    std::cout << "100 + 2.0 = " << a + c << std::endl;
    std::cout << "100 - 2.0 = " << a - c << std::endl;
    std::cout << "100 * 2.0 = " << a * c << std::endl;
    std::cout << "100 / 2.0 = " << a / c << std::endl;
    #endif
    #ifdef VAR
    Number a(static_cast<long long>(100)), b(static_cast<float>(4));
    Var *var_a = new Var("a", static_cast<long long>(100)), *var_b = new Var("b", static_cast<float>(3));
    std::cout << *var_a << std::endl << *var_b << std::endl;
    std::cout << var_a->getVarName() << " + 100 = " << (*var_a) + a << std::endl;
    std::cout << var_a->getVarName() << " - 100 = " << (*var_a) - a << std::endl;
    std::cout << var_a->getVarName() << " * 100 = " << (*var_a) * a << std::endl;
    std::cout << var_a->getVarName() << " / 100 = " << (*var_a) / a << std::endl;
    std::cout << var_b->getVarName() << " + 100 = " << (*var_b) + a << std::endl;
    std::cout << var_b->getVarName() << " - 100 = " << (*var_b) - a << std::endl;
    std::cout << var_b->getVarName() << " * 100 = " << (*var_b) * a << std::endl;
    std::cout << var_b->getVarName() << " / 100 = " << (*var_b) / a << std::endl;
    std::cout << var_a->getVarName() << " + 4.0 = " << (*var_a) + b << std::endl;
    std::cout << var_a->getVarName() << " - 4.0 = " << (*var_a) - b << std::endl;
    std::cout << var_a->getVarName() << " * 4.0 = " << (*var_a) * b << std::endl;
    std::cout << var_a->getVarName() << " / 4.0 = " << (*var_a) / b << std::endl;
    std::cout << var_b->getVarName() << " + 4.0 = " << (*var_b) + b << std::endl;
    std::cout << var_b->getVarName() << " - 4.0 = " << (*var_b) - b << std::endl;
    std::cout << var_b->getVarName() << " * 4.0 = " << (*var_b) * b << std::endl;
    std::cout << var_b->getVarName() << " / 4.0 = " << (*var_b) / b << std::endl;
    #endif
    #ifdef EXP
    SymbolTable * s_table = new SymbolTable();
    Var * a = new Var("a", static_cast<long long>(100)), * b = new Var("test_b", static_cast<float>(5));
    Expr * e = new Expr("-1 / (-2.5 + 3) * a - test_b");
    s_table->insert(a);
    s_table->insert(b);
    e->transfer(s_table);
    e->printInverse();
    std::cout << e->eval(s_table) << std::endl;
    #endif
    return 0;
}