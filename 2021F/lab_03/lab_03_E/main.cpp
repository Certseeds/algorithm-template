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

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_03_E{
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

using i32 = int32_t;
using i64 = int64_t;

using input_type = std::pair<i32, vector<i64>>;
using output_type = i64;

inline input_type read_input();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    const auto input_data = read_input();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read_input() {
    i32 n{0};
    std::cin >> n;
    vector<i64> a;
    a.resize(n);
    for (i32 i = 0; i < n; ++i) std::cin >> a[i];
    return {n, a};
}

// Fenwick tree for counts
struct Fenwick {
    int n;
    vector<i32> bit;
    Fenwick(int _n = 0) { init(_n); }
    void init(int _n) { n = _n; bit.assign(n+1, 0); }
    void add(int idx, i32 val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    i32 sumPrefix(int idx) const {
        i32 r = 0;
        for (; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
};

output_type cal(const input_type &data) {
    const i32 n = data.first;
    const auto &a = data.second;
    if (n <= 1) return 0;
    // coordinate compression
    vector<i64> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    Fenwick fw(static_cast<int>(vals.size()));
    i64 ans = 0;
    for (i32 i = 0; i < n; ++i) {
        int rk = static_cast<int>(std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1; // 1-based
        i32 leq = fw.sumPrefix(rk); // number of previous <= a[i]
        i32 prev = i; // number of previous elements
        i32 greater = prev - leq; // previous elements > a[i]
        ans += a[i] * static_cast<i64>(greater);
        fw.add(rk, 1);
    }
    return ans;
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
