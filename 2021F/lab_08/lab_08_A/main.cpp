// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_A {
#endif
// 以下严格遵守 AGENTS.md 中的代码风格与三段式（read/process/write）
using int32 = std::int32_t;
using int64 = std::int64_t;

static constexpr char NL{'\n'};

struct Input {
    int32 n;
    std::vector<int64> a;
};

struct Output {
    std::vector<int32> swaps;
};

// 读取阶段：读取输入并返回 Input 结构
Input read_input() {
    Input in{};
    std::cin >> in.n;
    in.a.resize(in.n);
    for (int32 i = 0; i < in.n; ++i) {
        std::cin >> in.a[i];
    }
    return in;
}

// 处理阶段：计算每次插入堆时的上浮次数
Output solve(const Input &in) {
    Output out{};
    out.swaps.reserve(in.n);

    // 使用 1-based 完全二叉堆数组表示
    std::vector<int64> heap;
    heap.reserve(in.n + 1);
    heap.push_back(0); // 0 号位不使用，方便 1-based

    for (int32 i = 0; i < in.n; ++i) {
        const auto val = in.a[i];
        heap.push_back(val);
        int32 pos = static_cast<int32>(heap.size() - 1);
        int32 cnt = 0;

        // 上浮：如果父节点更小则交换
        while (pos > 1) {
            const int32 parent = pos / 2;
            if (heap[parent] >= heap[pos]) break;
            std::swap(heap[parent], heap[pos]);
            pos = parent;
            ++cnt;
        }
        out.swaps.push_back(cnt);
    }

    return out;
}

// 输出阶段：将结果写回 stdout
void write_output(const Output &out) {
    const auto &v = out.swaps;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << NL;
}

int main() {
    const auto input = read_input();
    const auto result = solve(input);
    write_output(result);
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
