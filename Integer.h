/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-26 19:37:39
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-26 19:48:00
 */
#pragma once
#include "Number.h"
#include "Float.h"
class Integer: public Number {
private:
    long long val;
public:
    Integer() = delete;
    Integer(long long _val) : val(_val) {}
    Integer operator+(const Integer& a) const;
    Integer operator-(const Integer& a) const;
    Integer operator*(const Integer& a) const;
    Integer operator/(const Integer& a) const;
    Float operator+(const Float& a) const;
    Float operator-(const Float& a) const;
    Float operator*(const Float& a) const;
    Float operator/(const Float& a) const;
    long long getVal() const;
};