// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <utility>
#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_D {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using i32 = int32_t;
using i64 = int64_t;

struct ProblemInput {
    i32 n;
    std::vector<i64> a;
};

using ProblemOutput = i64;

// Three-stage function declarations
ProblemInput read_input();

ProblemOutput solve(const ProblemInput &in);

void write_output(const ProblemOutput &out);

int main() {
    const auto in = read_input();
    const auto out = solve(in);
    write_output(out);
    return 0;
}

// Read: N and array A
ProblemInput read_input() {
    ProblemInput in;
    std::cin >> in.n;
    in.a.assign(static_cast<size_t>(in.n), 0);
    for (i32 i = 0; i < in.n; ++i) std::cin >> in.a[static_cast<size_t>(i)];
    return in;
}

// Lightweight min-heap for i64 values (avoid STL priority_queue per HINT)
struct MinHeap {
    std::vector<i64> data;

    inline bool empty() const { return data.empty(); }
    inline size_t size() const { return data.size(); }

    inline void push(i64 v) {
        data.push_back(v);
        sift_up(data.size() - 1);
    }

    inline i64 top() const { return data.front(); }

    inline void pop() {
        if (data.size() <= 1) {
            data.pop_back();
            return;
        }
        data[0] = data.back();
        data.pop_back();
        sift_down(0);
    }

private:
    static inline bool less_than(i64 l, i64 r) { return l < r; }

    void sift_up(size_t idx) {
        while (idx > 0) {
            size_t parent = (idx - 1) >> 1;
            if (!less_than(data[idx], data[parent])) break;
            std::swap(data[idx], data[parent]);
            idx = parent;
        }
    }

    void sift_down(size_t idx) {
        const size_t n = data.size();
        while (true) {
            size_t l = idx * 2 + 1;
            size_t r = l + 1;
            size_t smallest = idx;
            if (l < n && less_than(data[l], data[smallest])) smallest = l;
            if (r < n && less_than(data[r], data[smallest])) smallest = r;
            if (smallest == idx) break;
            std::swap(data[idx], data[smallest]);
            idx = smallest;
        }
    }
};

// Solve: Huffman-style merging minimal total cost
ProblemOutput solve(const ProblemInput &in) {
    const i32 n = in.n;
    if (n <= 1) return 0;

    MinHeap heap;
    heap.data.reserve(static_cast<size_t>(n));
    for (i32 i = 0; i < n; ++i) heap.push(in.a[static_cast<size_t>(i)]);

    i64 total = 0;
    while (heap.size() > 1) {
        const i64 x = heap.top();
        heap.pop();
        const i64 y = heap.top();
        heap.pop();
        const i64 s = x + y;
        total += s;
        heap.push(s);
    }
    return total;
}

// Write: single integer result
void write_output(const ProblemOutput &out) {
    std::cout << out << end;
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
