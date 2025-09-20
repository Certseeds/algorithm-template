/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-04-16 00:50:04
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:24:45
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <array>
#include <iostream>
#include <unordered_map>
// 打表题
// 这题排版真够差劲的
namespace question3 {
using namespace std;
using input_type = int32_t;
using output_type = int32_t;

input_type readNumber() {
    int32_t input_num{0};
    std::cin >> input_num;
    return input_num;
}

int32_t count(input_type inputNumber) {
    const static unordered_map<input_type, output_type> umap
            {{{1, 5}, {2, 5}, // 1元5个
              {3, 8}, {4, 8},// 1元5个 + 2元3个
              {5, 11}, {6, 11},//1元5个 + 2元3个+ 2元3个
              {7, 13}, {8, 13}, {9, 13},//1元5个 + 2元3个+ 2元3个 + 2元2个
              {10, 14}, {11, 14},      //1元5个 + 2元3个+ 2元3个 + 2元2个 + 3元1个
              {12, 17}, {13, 17}, {14, 17},//1元5个 + 2元3个+ 2元3个 + 2元2个 + 5元3个
              {15, 18}//1元5个 + 2元3个+ 2元3个 + 2元2个 + 5元3个 + 3元1个
             }};
    std::array<int32_t, 16> umap2{-1, 5, 5, 8, 8, 11, 11, 13, 13, 13, 14, 14, 17, 17, 17, 18};
    return umap2[inputNumber];
    // return umap.at(inputNumber);
}


void output(output_type num) {
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
    return question3::main();
}

#endif
