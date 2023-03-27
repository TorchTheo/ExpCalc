/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-26 19:41:57
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-26 19:44:06
 */
#include <bits/stdc++.h>

class Base {};
class Child: public Base {};

int main() {
    Base b = Child();
    std::cout << (typeid(b) == typeid(Base)) << std::endl;
    return 0;
}