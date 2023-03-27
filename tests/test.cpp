/*
 * @Author: TorchTheo 2961620012@qq.com
 * @Date: 2023-03-27 09:38:29
 * @LastEditors: TorchTheo 2961620012@qq.com
 * @LastEditTime: 2023-03-27 19:07:59
 * @FilePath: /ExpCalc/tests/test.cpp
 * @Description: test
 */
#include "../include/Number.h"
#include <iostream>

int main() {
    #ifdef NUMBER
    Number a(static_cast<long long>(100)), b(static_cast<long long>(3));
    std::cout << "100 + 3 = " << a + b << std::endl;
    std::cout << "100 - 3 = " << a - b << std::endl;
    std::cout << "100 * 3 = " << a * b << std::endl;
    std::cout << "100 / 3 = " << a / b << std::endl;
    Number c(static_cast<float>(2.0)), d(static_cast<float>(3.0));
    std::cout << "2.0 + 3.0 = " << c + d << std::endl;
    std::cout << "2.0 - 3.0 = " << c - d << std::endl;
    std::cout << "2.0 * 3.0 = " << c * d << std::endl;
    std::cout << "2.0 / 3.0 = " << c / d << std::endl;
    std::cout << "100 + 2.0 = " << a + c << std::endl;
    std::cout << "100 - 2.0 = " << a - c << std::endl;
    std::cout << "100 * 2.0 = " << a * c << std::endl;
    std::cout << "100 / 2.0 = " << a / c << std::endl;
    #endif
    #ifdef RELEASE
    std::cout << "No test info...\n";
    #endif
    return 0;
}