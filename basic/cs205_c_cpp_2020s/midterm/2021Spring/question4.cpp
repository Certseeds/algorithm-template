/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-04-16 00:50:08
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:24:50
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
//一道很常见的01背包问题
// https://leetcode-cn.com/problems/partition-equal-subset-sum/
namespace question4 {
using namespace std;
using input_type = std::tuple<vector < int32_t>, vector <int32_t>, int32_t>;
using output_type = int32_t;

input_type readNumber() {
    int32_t input_num{0};
    vector <int32_t> distance{}, ele{};

    std::string buffer;
    std::getline(std::cin, buffer);
    std::istringstream iss(buffer);
    while (iss >> input_num) {
        distance.push_back(input_num);
    }
    std::getline(std::cin, buffer);
    std::istringstream iss2(buffer);
    while (iss2 >> input_num) {
        ele.push_back(input_num);
    }
    int32_t max_distance;
    std::cin >> max_distance;
    return std::make_tuple(distance, ele, max_distance);
}

output_type count(const input_type &input) {
    const auto&[distance, ele, max_distance] = input;
    size_t size_of_distance{distance.size()};
    vector <vector<int32_t>> dp(1 + size_of_distance, vector<int32_t>(1 + max_distance, 0));
    // dp[x][y],前x个子项中挑选总距离<=y的物体的最高总价值.
    for (size_t i{1}; i <= size_of_distance; i++) {
        for (int32_t j{1}; j <= max_distance; ++j) {
            const auto &no_choice = dp[i - 1][j];
            int32_t choice = -0x3f3f3f3f;
            if (j >= distance[i - 1]) {
                choice = dp[i - 1][j - distance[i - 1]] + ele[i - 1];
            }
            dp[i][j] = std::max(no_choice, choice);
        }
    }
    return dp.back().back();
}

void output(int32_t num) {
    std::cout << num << std::endl;
}

int main() {
    input_type number{readNumber()};
    output_type will_return{count(number)};
    output(will_return);
    return 0;
}
}
#ifndef CS205_C_CPP_MIDTERM_2021SPRING

int main() {
    return question4::main();
}

#endif
