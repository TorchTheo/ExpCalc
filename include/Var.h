/*
 * @Author: TorchTheo 2961620012@qq.com
 * @Date: 2023-03-27 19:18:37
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 10:10:23
 * @FilePath: /ExpCalc/include/Var.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Number;
class Var;

class Number {
public:
    enum TYPE {
        INT,
        FLOAT,
    };
    union {
        long long i;
        float f;
    } val;
    TYPE type;
    Number() = delete;
    Number(long long a);
    Number(float f);
    Number(TYPE t);
    Number(const Number& t);
    Number operator-(const Number& a) const;
    Number operator+(const Number& a) const;
    Number operator*(const Number& a) const;
    Number operator/(const Number& a) const;
    Number operator+(const Var& var) const;
    Number operator-(const Var& var) const;
    Number operator*(const Var& var) const;
    Number operator/(const Var& var) const;
    friend std::ostream& operator<<(std::ostream& output, const Number& a) {
        if (a.type == Number::INT)
            output << a.val.i;
        else 
            output << std::fixed << std::setprecision(4) << a.val.f;
        return output;
    }
};

class Var {
private:
    std::string var_name;
    Number val;
public:
    Var(std::string _var_name, long long a);
    Var(std::string _var_name, float a);
    Var(std::string _var_name, Number _val);
    Number getVal() const;
    std::string getVarName() const;
    Number operator-(const Number& a) const;
    Number operator+(const Number& a) const;
    Number operator*(const Number& a) const;
    Number operator/(const Number& a) const;
    Number operator+(const Var& var) const;
    Number operator-(const Var& var) const;
    Number operator*(const Var& var) const;
    Number operator/(const Var& var) const;
    friend std::ostream& operator<<(std::ostream& output, const Var& a) {
        output << a.getVarName() << " = " << a.getVal();
        return output;
    }
};