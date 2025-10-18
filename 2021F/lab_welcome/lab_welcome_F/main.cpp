// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_F{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'};
//TODO

using input_type = std::vector<std::string>;
using output_type = std::vector<std::string>;

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    int t = 0;
    if (!(std::cin >> t)) return {};
    input_type v;
    v.reserve(t);
    for (int i = 0; i < t; ++i) {
        std::string s;
        std::cin >> s;
        v.push_back(std::move(s));
    }
    return v;
}

output_type cal(input_type data) {
    output_type res;
    res.reserve(data.size());
    for (const auto &s : data) {
        if (s == "0") { res.push_back("yes"); continue; }
        bool converges = true;
        size_t pos = 0;
        while (pos < s.size()) {
            size_t nxt = s.find('+', pos);
            std::string token = (nxt == std::string::npos) ? s.substr(pos) : s.substr(pos, nxt - pos);
            pos = (nxt == std::string::npos) ? s.size() : nxt + 1;

            // parse leading coefficient digits
            size_t p = 0;
            while (p < token.size() && std::isdigit((unsigned char)token[p])) ++p;
            if (p == 0) { converges = false; break; }
            std::string coef_str = token.substr(0, p);
            unsigned long long C = 0ULL;
            try { C = std::stoull(coef_str); } catch (...) { C = 1ULL; }
            if (C != 0ULL) { converges = false; break; }
        }
        res.push_back(converges ? "yes" : "no");
    }
    return res;
}

void output(const output_type &data) {
    for (const auto &line : data) std::cout << line << end;
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
