/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-27 20:55:52
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:36:45
 */
#pragma once
#include <unordered_map>
#include <string>
#include "Var.h"
class SymbolTable {
private:
    std::unordered_map<std::string, Var*> s_table;
    int temp_cnt;
public:
    SymbolTable();
    bool insert(Var*);
    std::string insert(Number);
    Var* find(std::string);
};