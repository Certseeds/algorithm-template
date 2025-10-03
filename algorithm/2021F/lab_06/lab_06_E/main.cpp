// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_06_E{
#endif

using std::cin;
using std::cout;
using std::string;
using std::vector;

static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = std::tuple<string>;
using output_type = num_t;

inline input_type read();
output_type cal(const input_type &data);
void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    string s;
    std::cin >> s;
    return std::make_tuple(std::move(s));
}

// Manacher simplified via d1 (odd) and d2 (even) radii arrays
output_type cal(const input_type &data) {
    string s;
    std::tie(s) = data;
    const num_t n = static_cast<num_t>(s.size());
    if (n <= 0) return 0;

    vector<num_t> d1(n); // odd
    num_t l = 0, r = -1;
    for (num_t i = 0; i < n; ++i) {
        num_t k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    vector<num_t> d2(n); // even
    l = 0; r = -1;
    for (num_t i = 0; i < n; ++i) {
        num_t k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    num_t best = 1;
    for (num_t i = 0; i < n; ++i) {
        const num_t len1 = d1[i] * 2 - 1;
        if (len1 > best) best = len1;
        const num_t len2 = d2[i] * 2;
        if (len2 > best) best = len2;
    }
    return best;
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
