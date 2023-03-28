/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-28 10:33:31
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:55:01
 */
/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-28 10:33:31
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:31:35
 */
#include "include/Calc.h"
#include "include/Constant.h"

#include <regex>

std::regex var("[_a-zA-Z][0-9_a-zA-Z]*");

Calc::Calc() {
    s_table = new SymbolTable();
}

Number Calc::parse(std::string line) {
    if (line.find('=') != -1) {
        try {
            return processAssign(line);
        } catch (std::string s) {
            throw s;
        }
    } else {
        return processExpression(line);
    }
}

Number Calc::processAssign(std::string stmt) {
    std::string var_name;
    int i = 0;
    for (; i < stmt.size(); i++) {
        if (stmt[i] == ' ' || stmt[i] == '=')
            break;
        var_name.push_back(stmt[i]);
    }
    if (!std::regex_match(var_name, var))
        throw ILLEGAL_VARNAME;
    while (stmt[i] == '=' || stmt[i] == ' ')
        i++;
    Expr e(stmt.substr(i));
    try {
        Number num = e.eval(s_table);
        Var *v = nullptr;
        v = new Var(var_name, num);
        s_table->insert(v);
        return num;
    } catch (const std::string &s) {
        throw s;
    }
}

Number Calc::processExpression(std::string exp) {
    Expr e(exp);
    try {
        return e.eval(s_table);
    } catch (const std::string& s) {
        throw s;
    }
}