// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <set>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_06_A{
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using std::set;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = std::string;
using output_type = num_t;

inline input_type read();

output_type cal(const input_type& data);

void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    input_type a;
    std::cin >> a;
    return a;
}

output_type cal(const input_type& data) {
   const int32_t n = static_cast<int32_t>(data.size());
    std::set<std::string> subs;
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t len = 1; i + len <= n; ++len) {
            subs.insert(data.substr(i, len));
        }
    }
    return static_cast<output_type>(subs.size());
}

void output(const output_type &data) {
    std::cout << data << end;
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
