/*
 * @Description: ExpressionCalculator
 * @version: 1.0
 * @Author: Pang_wkym
 * @Date: 2023-03-27 21:49:26
 * @LastEditors: Pang_wkym
 * @LastEditTime: 2023-03-28 11:42:55
 */
#include "include/utils.h"
#include <sstream>
#include <iostream>
std::vector<std::string> splitString(std::string str) {
    std::vector<std::string> ret;
    std::stringstream ss(str);
    std::string temp;
    while (ss >> temp) {
        ret.emplace_back(temp);
    }
    return ret;
}