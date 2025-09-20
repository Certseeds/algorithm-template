/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-04-16 00:49:57
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:24:35
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
//look at
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
namespace question1 {
using namespace std;

int32_t readNumber() {
    int32_t input_num{0};
    std::cin >> input_num;
    return input_num;
}

int32_t count(int32_t inputNumber) {
    int32_t sum{0};
    for (int32_t begin{0}; begin <= inputNumber; begin += 5) {
        int32_t bedivide{begin}, count{0};
        while (bedivide % 5 == 0 && bedivide != 0) {
            count++;
            bedivide /= 5;
        }
        sum += count;
    }
    return sum;
}

void output(int32_t num) {
    std::cout << num << std::endl;
}

int main() {
    int32_t number{readNumber()};
    int32_t will_return{count(number)};
    output(will_return);
    return 0;
}
}
#ifndef CS205_C_CPP_MIDTERM_2021SPRING

int main() {
    return question1::main();
}

#endif
