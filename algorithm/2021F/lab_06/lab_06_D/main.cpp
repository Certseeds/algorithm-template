// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")
#else
namespace lab_06_D {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using std::string;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = tuple<string, string>;
using output_type = string;

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
    string s, t;
    // read two whitespace-separated strings (works for single-line or two-line inputs)
    std::cin >> s >> t;
    return std::make_tuple(std::move(s), std::move(t));
}

// KMP prefix (lps) computation
static vector<num_t> build_lps(const string &pat) {
    const num_t n = static_cast<num_t>(pat.size());
    vector<num_t> lps(n, 0);
    num_t len = 0;
    for (num_t i = 1; i < n; ++i) {
        while (len > 0 && pat[i] != pat[len]) {
            len = lps[len - 1];
        }
        if (pat[i] == pat[len]) {
            ++len;
            lps[i] = len;
        }
    }
    return lps;
}

// KMP search: returns true if pattern exists in text
static bool kmp_search(const string &text, const string &pat) {
    if (pat.empty()) return true;
    const num_t n = static_cast<num_t>(text.size());
    const num_t m = static_cast<num_t>(pat.size());
    if (m > n) return false;
    const auto lps = build_lps(pat);
    num_t j = 0; // index in pat
    for (num_t i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pat[j]) j = lps[j - 1];
        if (text[i] == pat[j]) {
            ++j;
            if (j == m) return true;
        }
    }
    return false;
}

static constexpr char *const YES{"Yes"};
static constexpr char *const NO{"No"};

output_type cal(const input_type &data) {
    string s, t;
    tie(s, t) = data;
    // If lengths differ, cannot be rotations
    if (s.size() != t.size()) return NO;
    // Quick equality check
    if (s == t) return YES;
    // Check if t is a substring of s+s using KMP
    string doubled = s + s;
    bool ok = kmp_search(doubled, t);
    return ok ? YES : NO;
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
