// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
// Input / Process / Output three-stage implementation
#include <memory>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("native")
#else
namespace lab_07_C {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

struct Input {
    int64_t T{0};
    std::vector<uint64_t> nums; // values up to 1e18
};

using output_type = std::vector<uint64_t>;

static Input read_input() {
    Input in{};
    if (!(cin >> in.T)) return in;
    in.nums.reserve(static_cast<size_t>(in.T));
    for (int64_t i = 0; i < in.T; ++i) {
        uint64_t x;
        cin >> x;
        in.nums.push_back(x);
    }
    return in;
}

// compute height = floor(log2(n)) + 1
static inline uint64_t compute_height(uint64_t n) {
    if (n == 0) return 0; // undefined but guard
    uint64_t h = 0;
    while (n > 0) {
        ++h;
        n >>= 1;
    }
    return h;
}

static output_type solve(const Input &in) {
    output_type out;
    out.reserve(in.nums.size());
    for (const auto &x: in.nums) out.push_back(compute_height(x));
    return out;
}

static void write_output(const output_type &outv) {
    for (const auto &v: outv) cout << v << end;
}

int main() {
    const auto in = read_input();
    if (in.T <= 0) return 0;
    const auto outv = solve(in);
    write_output(outv);
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
