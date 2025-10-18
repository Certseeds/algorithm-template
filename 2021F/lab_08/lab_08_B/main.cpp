// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_B {
#endif
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using int32 = std::int32_t;
using int64 = std::int64_t;

static constexpr char NL{'\n'};

// 常量字符串：避免在代码多处硬编码字面量
static constexpr const char *const kMax = "Max";
static constexpr const char *const kMin = "Min";
static constexpr const char *const kNeither = "Neither";

struct Input {
    int32 n;
    std::vector<int64> a;
};

struct Output {
    std::string ans;
};

// 读取阶段
Input read_input() {
    Input in{};
    std::cin >> in.n;
    in.a.resize(in.n + 1); // 1-based for convenience
    for (int32 i = 1; i <= in.n; ++i) {
        std::cin >> in.a[i];
    }
    return in;
}

// 处理阶段：判断 Max / Min / Neither
Output solve(const Input &in) {
    Output out{};
    if (in.n <= 1) {
        out.ans = kMax;
        return out;
    }

    bool isMax = true;
    bool isMin = true;

    for (int32 i = 2; i <= in.n; ++i) {
        int32 p = i / 2;
        if (in.a[p] < in.a[i]) isMax = false;
        if (in.a[p] > in.a[i]) isMin = false;
        if (!isMax && !isMin) break;
    }

    if (isMax) {
        out.ans = kMax;
    } else if (isMin) {
        out.ans = kMin;
    } else {
        out.ans = kNeither;
    }
    return out;
}

// 输出阶段
void write_output(const Output &out) {
    std::cout << out.ans << NL;
}

int main() {
    const auto in = read_input();
    const auto res = solve(in);
    write_output(res);
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
