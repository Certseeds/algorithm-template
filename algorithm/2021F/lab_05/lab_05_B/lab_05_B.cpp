// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
/*
 * @题目描述
 * TODO
 * */
//@Tag DONE

#ifndef CS203_DSAA_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#endif

#include <tuple>
#include <queue>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_05_B{
#endif

using std::cin;
using std::cout;
using std::tuple;
using std::queue;
using std::string;
using std::vector;

static constexpr const char end{'\n'}, space{' '};

using num_t = int32_t;
using input_type = std::tuple<std::queue<num_t>, std::queue<num_t>>;
using output_type = vector<num_t>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int32_t main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t nu{0}, phi{0}, rho{0};
    std::cin >> nu >> phi >> rho;
    queue<num_t> first{}, second{};
    num_t value{0};
    for (num_t i{0}; i < phi; ++i) {
        std::cin >> value;
        first.push(value);
    }
    for (num_t i{0}; i < rho; ++i) {
        std::cin >> value;
        second.push(value);
    }
    return std::make_tuple(first, second);
}

output_type cal(const input_type &data) {
    queue<num_t> first{}, second{};
    std::tie(first, second) = data;
    vector<num_t> time(std::max(first.size(), second.size()) + 1, -1);
    num_t count{1};
    const auto while_func = [&time](queue<num_t> &q) {
        num_t order{0};
        if (q.empty()) {
            return order;
        }
        do {
            order = q.front();
            q.pop();
        } while (time[order] != -1 && !q.empty());
        return order;
    };
    const auto if_func = [&time, &count](num_t order) {
        if (time[order] == -1) {
            time[order] = count;
        }
    };
    for (; !first.empty() && !second.empty(); count++) {
        const auto fir{while_func(first)},
                sec{while_func(second)};
        if (fir == sec) {
            time[fir] = count;
        } else {
            if_func(fir);
            if_func(sec);
        }
    }
    for (; !first.empty(); count++) {
        const auto fir{while_func(first)};
        if_func(fir);
    }
    for (; !second.empty(); count++) {
        const auto sec{while_func(second)};
        if_func(sec);
    }
    return time;
}

void output(const output_type &data) {
    for (auto iter{data.cbegin() + 1}; iter != data.cend() - 1; ++iter) {
        std::cout << (*iter) << space;
    }
    std::cout << *(data.cend() - 1);
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
