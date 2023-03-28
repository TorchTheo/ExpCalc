/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-27 19:40:33
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 10:06:05
 */
#pragma once
#include <string>
#include <vector>
#include "Symbol.h"
class Expr {
private:
    std::string origin_exp;
    std::vector<std::string> inverse_polish_form;
public:
    Expr(std::string s);
    void transfer(SymbolTable* s_table);
    void printInverse() const;
    Number eval(SymbolTable* s_table);
    
};