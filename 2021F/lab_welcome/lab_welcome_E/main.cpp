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
#include <limits>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <ctime>
#include <cstdlib>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_E{
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

using ull = unsigned long long;

static vector<string> strobogrammatic(int n, int total) {
    if (n == 0) return {""};
    if (n == 1) return {"0", "1", "8"};
    auto prev = strobogrammatic(n - 2, total);
    vector<std::pair<string,string>> pairs = {{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
    vector<string> res;
    for (const auto &mid: prev) {
        for (const auto &p: pairs) {
            if (p.first == "0" && n == total) continue; // no leading zero
            res.push_back(p.first + mid + p.second);
        }
    }
    return res;
}

static void solve_one(ull L, ull R) {
    string sL = std::to_string(L);
    string sR = std::to_string(R);
    int lenL = (int)sL.length();
    int lenR = (int)sR.length();

    ull minv = std::numeric_limits<ull>::max();
    ull maxv = 0;

    for (int len = lenL; len <= lenR; ++len) {
        auto list = strobogrammatic(len, len);
        for (const auto &s: list) {
            // skip numbers with leading zeros (already avoided for outermost) but double check
            if (s.length() > 1 && s[0] == '0') continue;
            // convert
            ull val = 0;
            for (char c: s) {
                val = val * 10 + (c - '0');
            }
            if (val < L || val > R) continue;
            if (val < minv) minv = val;
            if (val > maxv) maxv = val;
        }
    }

    // per problem statement, at least one exists
    cout << minv << ' ' << maxv << end;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long L, R;
    // read until EOF
    while ( (std::cin >> L >> R) ) {
        solve_one(L, R);
    }
    return 0;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
