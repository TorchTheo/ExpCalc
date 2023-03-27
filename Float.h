/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-26 19:38:56
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-27 08:01:21
 */
#pragma once
#include "Number.h"
#include "Integer.h"
class Float {
private:
    float val;
public:
    Float() = delete;
    Float(float _val) : val(_val) {}
    Float operator+(const Integer& a) const;
    Float operator-(const Integer& a) const;
    Float operator*(const Integer& a) const;
    Float operator/(const Integer& a) const;
    Float operator+(const Float& a) const;
    Float operator-(const Float& a) const;
    Float operator*(const Float& a) const;
    Float operator/(const Float& a) const;

    Float getVal() const;
};