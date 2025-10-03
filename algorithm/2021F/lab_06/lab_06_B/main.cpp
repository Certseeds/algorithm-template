// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <iostream>
#include <string>
#include <vector>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_06_B {
#endif

using std::string;
using std::vector;

// Function to compute the KMP next array (prefix function)
auto compute_next(const string &pattern) -> vector<int32_t> {
    const int32_t m = pattern.length();
    vector<int32_t> next(m, 0);
    for (int32_t i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

// Function to compute the FSA transition function
auto compute_transition_function(const string &pattern)
    -> vector<vector<int32_t>> {
    const int32_t m = pattern.length();
    const auto next = compute_next(pattern);
    vector<vector<int32_t>> delta(m, vector<int32_t>(26));

    for (int32_t q = 0; q < m; ++q) {
        for (char c_char = 'a'; c_char <= 'z'; ++c_char) {
            const int32_t c_idx = c_char - 'a';
            if (c_char == pattern[q]) {
                // On matching character, move to q+1 (may equal m)
                delta[q][c_idx] = q + 1;
            } else {
                if (q > 0) {
                    delta[q][c_idx] = delta[next[q - 1]][c_idx];
                } else {
                    delta[q][c_idx] = 0;
                }
            }
        }
    }
    return delta;
}

auto solve() -> void {
    string pattern;
    std::cin >> pattern;
    const auto delta = compute_transition_function(pattern);
    for (const auto &row : delta) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i] << (i == row.size() - 1 ? "" : " ");
        }
        std::cout << '\n';
    }
}

int main() {
    solve();
    return 0;
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
