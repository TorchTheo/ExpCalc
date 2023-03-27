/*
 * @Author: TorchTheo 2961620012@qq.com
 * @Date: 2023-03-27 18:21:25
 * @LastEditors: TorchTheo 2961620012@qq.com
 * @LastEditTime: 2023-03-27 19:04:26
 * @FilePath: /ExpCalc/include/Number.h
 * @Description: Number类
 */
#pragma once
#include <iostream>
#include <iomanip>

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
    Number operator-(const Number& a) const;
    Number operator+(const Number& a) const;
    Number operator*(const Number& a) const;
    Number operator/(const Number& a) const;
    friend std::ostream& operator<<(std::ostream& output, const Number& a) {
        if (a.type == Number::INT)
            output << a.val.i;
        else 
            output << std::fixed << std::setprecision(4) << a.val.f;
        return output;
    }
};