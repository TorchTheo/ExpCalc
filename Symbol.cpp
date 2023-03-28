/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-27 20:55:58
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:41:55
 */
#include "include/Symbol.h"

SymbolTable::SymbolTable() {
    temp_cnt = 1;
    s_table.clear();
    s_table.insert({"@TEMP0", new Var("@TEMP0", Number(static_cast<long long>(0)))});
}

bool SymbolTable::insert(Var* v) {
    if (v == nullptr)
        return false;
    if (s_table.find(v->getVarName()) != s_table.end())
        s_table[v->getVarName()] = v;
    else
        s_table.insert({v->getVarName(), v});
    return true;
}

std::string SymbolTable::insert(Number num) {
    if (num.type == Number::INT && num.val.i == 0)
        return "@TEMP0";
    std::string _temp = "@TEMP";
    _temp.append(std::to_string(temp_cnt));
    temp_cnt++;
    Var *var = new Var(_temp, num);
    s_table.insert({_temp, var});
    return _temp;
}

Var* SymbolTable::find(std::string name) {
    if (s_table.find(name) == s_table.end())
        return nullptr;
    return s_table[name];
}