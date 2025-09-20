// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
/*
 * @题目描述
 * */
//@Tag DONE

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#endif

#include <tuple>
#include <stack>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_05_D{
#endif

using std::cin;
using std::cout;
using std::stack;
using std::tuple;
using std::string;
using std::vector;

static constexpr const char left{'('}, right{')'};
static constexpr const int32_t mod_num{514329};
using num_t = int32_t;
using input_type = string;
using output_type = int32_t;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int32_t main() {
    const auto input_data{read()};
    const auto output_data{cal(input_data)};
    output(output_data);
    return 0;
}

inline input_type read() {
    string buckets;
    std::cin >> buckets;
    return buckets;
}

output_type cal(const input_type &data) {
    stack<num_t> sta{{-1}};
    for (const auto &ele: data) {
        if (ele == left) {
            // 无论怎样,左括号都要压栈
            sta.push(-1);
        } else if (sta.top() != -1) {
            // 栈内有未清空的数字则累加, 注意,此时只可能为右括号
            num_t middle{0};
            do {
                middle += sta.top();
                middle %= mod_num;
                sta.pop();
            } while (sta.top() != -1);
            sta.pop();
            sta.push((middle * 2) % mod_num);
        } else {
            // 上一个是左括号,这一个是右括号
            sta.pop();
            sta.push(1);
        }
    }
    int32_t will_return{0};
    while (sta.top() != -1) {
        will_return += sta.top();
        will_return %= mod_num;
        sta.pop();
    }
    return will_return;
}

void output(const output_type &data) {
    std::cout << data;
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
