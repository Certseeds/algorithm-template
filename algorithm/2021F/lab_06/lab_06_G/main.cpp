// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_06_G{
#endif
using std::cin;
using std::cout;
using std::string;
using std::vector;
static constexpr const char end{'\n'};
using output_type = string;

inline string read_input();

output_type cal(const string& s);

void output(const output_type &data);

int main() {
    const auto s = read_input();
    const auto ans = cal(s);
    output(ans);
    return 0;
}

inline string read_input() {
    string s;
    std::cin >> s;
    return s;
}

output_type cal(const string& s) {
    const int n = static_cast<int>(s.size());
    if (n <= 2) return string("Just a legend");
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    int len = pi[n-1];
    // Check if this len appears in the prefix function except at last position
    while (len > 0) {
        bool found = false;
        for (int i = 0; i < n-1; ++i) {
            if (pi[i] == len) { found = true; break; }
        }
        if (found) return s.substr(0, len);
        len = pi[len-1];
    }
    return string("Just a legend");
}

void output(const output_type &data) {
    cout << data << end;
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
