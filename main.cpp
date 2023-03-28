/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-28 11:06:22
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:46:27
 */
#include <iostream>
#include "include/Calc.h"
#include <string>

int main() {
    std::string line;
    Calc* c = new Calc();
    std::cout << ">> ";
    while (getline(std::cin, line)) {
        try {
            std::cout << c->parse(line) << std::endl;
        } catch (std::string s) {
            std::cerr << "\033[31m" << s << "\033[0m" << std::endl;
        }
        std::cout << ">> ";
    }
    return 0;
}