// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
/*
 *题目描述
Suppose in CS203, the number system only has three values 2,3,6. It holds 2<3<6. Given an integer n, please find the n-th smallest number in CS203 number system.
排除废话版
The number system only has three values 2,3,6. It holds 2<3<6. Given an integer n, please find the n-th smallest number in CS203 number system.
输入
The 1st line contains an integer T [1,1000], the number of test cases.

Next T lines, each line contains an integer an integer n,[1,10^9]
Example:
Input:
 2
 1
 6
Output:
 2
 26
解析:
 第一个是2
 2,3,6,22,23,26
 因此第六个是26
 * */
#include <array>
#include <stack>
#include <tuple>
#include <string>
#include <vector>

#include <iostream>
#include <algorithm>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_C{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::array;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
static constexpr const char end{'\n'};
using num_t = int32_t;
static constexpr num_t SYSTEM_NUM_NUMBER = 3;
static constexpr array<char, SYSTEM_NUM_NUMBER> NUMBERS{'2', '3', '6'};
using input_type = vector<num_t>;
using output_type = vector<string>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t T{0};
    std::cin >> T;
    vector<num_t> nums(T);
    for (auto &num: nums) {
        std::cin >> num;
    }
    return nums;
}

static constexpr const int32_t max_circle = 20;

static const array<num_t, max_circle> &calcaute() {
    static array<num_t, max_circle> will_return{0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 2; i < max_circle; ++i) {
        will_return[i] = will_return[i - 1] * 3 + 3;
    }
    return will_return;
}

static const auto CIRCLE_NUMBERS = calcaute();

std::string cal_detail(num_t num) {
    stack<char> bits;
    int32_t length{-1};
    for (auto iter = max_circle - 1; iter >= 0; iter--) {
        if (num > CIRCLE_NUMBERS[iter]) {
            length = std::max(iter + 1, length);
            break;
        }
    }
    for (int i = 0; i < length; ++i) {
        num_t last = (num - 1) % SYSTEM_NUM_NUMBER;
        bits.push(NUMBERS[last]);
        num = (num - 1) / SYSTEM_NUM_NUMBER;
    }
    string result;
    while (!bits.empty()) {
        result.append({bits.top()});
        bits.pop();
    }
    return result;
}

output_type cal(const input_type &data) {
    vector<std::string> result;
    for (auto &&num: data) {
        result.push_back(cal_detail(num));
    }
    return result;
}

void output(const output_type &data) {
    for (const auto &iter: data) {
        std::cout << iter << std::endl;
    }
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
