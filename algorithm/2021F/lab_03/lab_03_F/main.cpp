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
#include <utility>
#include <functional>
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
namespace lab_03_F{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::pair;
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

using input_type = tuple<i32, i32, i32, vector<i64>, vector<i64>>; // n,p,q,h[],s[]
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
    i32 n; i32 p; i32 q;
    std::cin >> n >> p >> q;
    vector<i64> h(n), s(n);
    for (i32 i = 0; i < n; ++i) std::cin >> h[i] >> s[i];
    return std::make_tuple(n, p, q, h, s);
}

output_type cal(const input_type &data) {
    i32 n, p, q;
    vector<i64> h, s;
    tie(n, p, q, h, s) = data;
    i64 base = 0;
    vector<i64> g0(n);
    for (i32 i = 0; i < n; ++i) {
        base += s[i];
        g0[i] = std::max<i64>(h[i] - s[i], 0);
    }
    i32 cnt = std::min<i32>(q, n);
    // sort g0 descending with indices
    vector<pair<i64,int>> vec;
    vec.reserve(n);
    for (int i = 0; i < n; ++i) vec.emplace_back(g0[i], i);
    sort(vec.begin(), vec.end(), [](const pair<i64,int>&a, const pair<i64,int>&b){
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    vector<i64> gs(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        gs[i] = vec[i].first;
        pos[ vec[i].second ] = i;
    }
    vector<i64> pref(n+1, 0);
    for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + gs[i];

    i64 best = base + pref[cnt];

    // Precompute multiplier 2^p
    i64 mul = 1;
    for (int i = 0; i < p; ++i) mul <<= 1;

    for (int idx = 0; idx < n; ++idx) {
        // value if we apply all p F_h to idx
        i64 hi = h[idx] * mul;
        i64 g1 = std::max<i64>(hi - s[idx], 0);
        // compute insertion position in gs (descending)
        auto it = std::lower_bound(gs.begin(), gs.end(), g1, std::greater<i64>());
        int pos_insert = static_cast<int>(it - gs.begin());
        int orig_pos = pos[idx];
        int pos_excl = (pos_insert <= orig_pos) ? pos_insert : pos_insert - 1;

        // sum_top_excl: sum of top cnt values after removing original g0[idx]
        i64 sum_top_excl = 0;
        if (cnt == 0) {
            sum_top_excl = 0;
        } else if (orig_pos >= cnt) {
            sum_top_excl = pref[cnt];
        } else {
            // orig_pos < cnt
            sum_top_excl = pref[cnt] - gs[orig_pos];
            if (cnt < n) sum_top_excl += gs[cnt];
        }

        i64 total_gain_top = 0;
        if (pos_excl >= cnt) {
            total_gain_top = sum_top_excl;
        } else {
            // g1 enters top cnt, drop element at index cnt-1 of multiset_excl
            i64 drop = 0;
            if (cnt == 0) drop = 0;
            else if (orig_pos >= cnt) {
                drop = gs[cnt-1];
            } else {
                // orig_pos < cnt
                if (cnt < n) drop = gs[cnt]; else drop = 0;
            }
            total_gain_top = sum_top_excl + g1 - drop;
        }

        i64 candidate = base + total_gain_top;
        if (candidate > best) best = candidate;
    }

    return best;
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
