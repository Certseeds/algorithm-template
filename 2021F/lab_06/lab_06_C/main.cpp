// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <iostream>
#include <string>
#include <vector>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_06_C {
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

auto solve() -> void {
    string pattern;
    std::cin >> pattern;
    const auto next = compute_next(pattern);
    for (const auto &val : next) {
        std::cout << val << '\n';
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
