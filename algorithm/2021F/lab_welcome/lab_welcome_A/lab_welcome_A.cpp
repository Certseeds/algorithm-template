// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
/*
 * 题目描述
Given two arrays A with length n and B with length T. We want to know whether each element in array B is in array A or not.
给两个数组,数组A的长度为n ,数组B长度为T, 我们想要知道B中的每一个元素是否在Ａ内
输入
The 1st line is a positive integer n ∈[1,1000]

The 2nd line contains n integers: $a_1$,$a_2$,...,$a_n$.For each $a_i$, ∈[1,10^9]

The 3rd line contains a positive integer T [1,1000]

The 4th line contains T integers b1,b2,...,bT.For each bi∈[1,10^9]
 * */
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_welcome_A{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::array;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_set;
static constexpr const char end{'\n'};
enum class TRUE_FALSE : bool {
    NO = false,
    YES = true,
};
using num_t = int32_t;
using input_type = tuple<std::unordered_set<num_t>, vector<num_t>>;
using output_type = vector<TRUE_FALSE>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t n{0}, T{0}, temp{0};
    std::cin >> n;
    std::unordered_set<num_t> A{};
    for (int i{0}; i < n; ++i) {
        std::cin >> temp;
        A.insert(temp);
    }
    std::cin >> T;
    vector<num_t> B(T);
    for (auto &num: B) {
        std::cin >> num;
    }
    return std::make_tuple(A, B);
}

output_type cal(const input_type &data) {
    std::unordered_set<num_t> A{};
    vector<num_t> B{};
    tie(A, B) = data;
    vector<TRUE_FALSE> result{};
    for (auto &&i: B) {
        if (A.find(i) == A.end()) {
            result.push_back(TRUE_FALSE::NO);
        } else {
            result.push_back(TRUE_FALSE::YES);
        }
    }
    return result;
}

void output(const output_type &data) {
    for (auto &&result: data) {
        if (result == output_type::value_type::NO) {
            cout << "no" << std::endl;
        } else {
            cout << "yes" << std::endl;
        }
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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
