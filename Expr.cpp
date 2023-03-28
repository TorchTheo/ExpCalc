/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-27 19:40:33
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:35:37
 */
#include "include/Expr.h"
#include "include/Constant.h"
#include <stack>

Expr::Expr(std::string s) {
    int i = 0;
    std::string _s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            continue;
        _s.push_back(s[i]);
    }
    std::string temp;
    char pre = '(';
    while (i < _s.size()) {
        if (_s[i] == '-' && (pre == '+' || pre == '-' || pre == '*' || pre == '/' || pre == '(' || pre == ')')) {
            temp.append("(0-");
            i++;
            while (_s[i] != '+' && _s[i] != '-' && _s[i] != '*' && _s[i] != '/' && i < s.size()) {
                temp.push_back(_s[i]);
                i++;
            }
            temp.push_back(')');
        }
        if (i >= _s.size())
            break;
        temp.push_back(_s[i]);
        pre = _s[i];
        i++;
    }
    origin_exp = temp;
}

void Expr::transfer(SymbolTable* s_table) {
    std::stack<char> s;
    int i = 0;
    while (i < origin_exp.size()) {
        switch (origin_exp[i]) {
            case '(':
                s.push(origin_exp[i]);
                i++;
                break;
            case ')': {
                while (s.top() != '(') {
                    inverse_polish_form.emplace_back(std::string(1, s.top()));
                    s.pop();
                }
                s.pop();
                i++;
                break;
            }
            case '+': case '-': {
                while (!s.empty() && s.top() != '(') {
                    inverse_polish_form.emplace_back(std::string(1, s.top()));
                    s.pop();
                }
                s.push(origin_exp[i]);
                i++;
                break;
            }
            case '*': case '/': {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    inverse_polish_form.emplace_back(std::string(1, s.top()));
                    s.pop();
                }
                s.push(origin_exp[i]);
                i++;
                break;
            }
            case ' ':
                i++;
                break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
                std::string val;
                bool is_float = false;
                while ((origin_exp[i] >= '0' && origin_exp[i] <= '9') || origin_exp[i] == '.') {
                    if (origin_exp[i] == '.')
                        is_float = true;
                    val.push_back(origin_exp[i]);
                    i++;
                }
                std::string temp_name;
                if (is_float) {
                    float _v = std::stof(val);
                    Number temp(_v);
                    temp_name = s_table->insert(temp);
                } else {
                    long long _v = 0;
                    for (int i = 0; i < val.size(); i++)
                        _v = _v * 10 + val[i] - '0';
                    Number temp(_v);
                    temp_name = s_table->insert(temp);
                }
                inverse_polish_form.emplace_back(temp_name);
                break;
            }
            default: {
                std::string var_name;
                while (origin_exp[i] != ' ' && origin_exp[i] != '+' && origin_exp[i] != '-' && origin_exp[i] != '*' && origin_exp[i] != '/' && origin_exp[i] != '(' && origin_exp[i] != ')' && i < origin_exp.size()) {
                    var_name.push_back(origin_exp[i]);
                    i++;
                }
                if (s_table->find(var_name) == nullptr) {
                    std::string msg = UNKOWN_VAR;
                    msg.append(var_name);
                    throw msg;
                } else {
                    inverse_polish_form.emplace_back(var_name);
                }
                break;
            }
        }
    }
    while (!s.empty()) {
        inverse_polish_form.emplace_back(std::string(1, s.top()));
        s.pop();
    }
}

void Expr::printInverse() const {
    for (auto token : inverse_polish_form)
        std::cout << token << " ";
    std::cout << std::endl;
}

Number Expr::eval(SymbolTable* s_table) {
    try
    {
        transfer(s_table);
    }
    catch(const std::string e)
    {
        throw e;
    }
    
    std::stack<Number> s;
    for (const auto &var : inverse_polish_form) {
        if (var == "+" || var == "-" || var == "*" || var == "/") {
            if (s.empty())
                throw EXP_ERROR;
            Number v_b = s.top();
            s.pop();
            if (s.empty())
                throw EXP_ERROR;
            Number v_a = s.top();
            s.pop();
            if (var == "+")
                s.push(v_a + v_b);
            else if (var == "-")
                s.push(v_a - v_b);
            else if (var == "*")
                s.push(v_a * v_b);
            else {
                try
                {
                    s.push(v_a / v_b);
                }
                catch(const std::string& e)
                {
                    throw e;
                }
                
            }
        } else {
            auto v = s_table->find(var);
            if (v == nullptr) {
                std::string msg = UNKOWN_VAR;
                msg.append(var);
                throw msg;
            }
            else
                s.push(v->getVal());
        }
    }
    if (s.size() != 1)
        throw EXP_ERROR;
    return s.top();
}