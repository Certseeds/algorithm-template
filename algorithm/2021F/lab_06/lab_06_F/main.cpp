// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <utility>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_06_F{
#endif
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::array;
using std::pair;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = pair<array<char,26>, string>;
using output_type = num_t;

inline input_type read_input();

output_type cal(const input_type& data);

void output(const output_type &data);

int main() {
    const auto input_data = read_input();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read_input() {
    array<char,26> mp{};
    for (int i = 0; i < 26; ++i) {
        cin >> mp[i];
    }
    string s;
    cin >> s;
    return {mp, s};
}

output_type cal(const input_type& data) {
    const auto& mp = data.first;
    const string& s = data.second;
    // Build f(s) where f is the provided substitution mapping
    int n = static_cast<int>(s.size());
    string fs;
    fs.resize(n);
    for (int i = 0; i < n; ++i) {
        fs[i] = mp[s[i] - 'a'];
    }
    // KMP prefix function for pattern = s
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    // Match pattern s over text fs; after processing whole text, j is the
    // length of the longest prefix of s that is a suffix of fs
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && fs[i] != s[j]) j = pi[j-1];
        if (fs[i] == s[j]) ++j;
        if (j == n) { // full match, move j to proper border
            j = pi[j-1];
        }
    }
    int max_p = j;
    int half = n / 2;
    if (max_p > half) max_p = half;
    return static_cast<num_t>(n - max_p);
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
