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
namespace lab_08_C {
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
    i32 m;
    i32 k;
    std::vector<i64> a;
    std::vector<i64> b;
};

using ProblemOutput = std::vector<i64>;

// Forward declarations for three-stage main style
ProblemInput read_input();

ProblemOutput solve(const ProblemInput &in);

void write_output(const ProblemOutput &out);

int main() {
    const auto in = read_input();
    const auto out = solve(in);
    write_output(out);
    return 0;
}

// Read: parse N M K and arrays A and B
ProblemInput read_input() {
    ProblemInput in;
    std::cin >> in.n >> in.m >> in.k;
    in.a.assign(static_cast<size_t>(in.n), 0);
    in.b.assign(static_cast<size_t>(in.m), 0);
    for (i32 i = 0; i < in.n; ++i) std::cin >> in.a[static_cast<size_t>(i)];
    for (i32 j = 0; j < in.m; ++j) std::cin >> in.b[static_cast<size_t>(j)];
    return in;
}

// Custom lightweight min-heap for nodes (avoid using STL priority_queue per HINT)
struct HeapNode {
    i32 i; // index in A
    i32 j; // index in B
    i64 val; // product a[i]*b[j]
};

struct MinHeap {
    std::vector<HeapNode> data;

    inline bool empty() const { return data.empty(); }
    inline size_t size() const { return data.size(); }

    inline void push(const HeapNode &node) {
        data.push_back(node);
        sift_up(data.size() - 1);
    }

    inline HeapNode top() const { return data.front(); }

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
    static inline bool less_than(const HeapNode &l, const HeapNode &r) {
        if (l.val != r.val) return l.val < r.val;
        if (l.i != r.i) return l.i < r.i;
        return l.j < r.j;
    }

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

// Solve: compute first K smallest products of pairs from A and B
ProblemOutput solve(const ProblemInput &in) {
    const i32 n = in.n;
    const i32 m = in.m;
    const i32 k = in.k;

    // Copy and sort arrays to enable standard K-pairs enumeration
    auto a = in.a;
    auto b = in.b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    const i32 initial = std::min<i32>(n, k);
    MinHeap heap;
    heap.data.reserve(static_cast<size_t>(initial));

    // Push (i,0) for i in [0, initial)
    for (i32 i = 0; i < initial; ++i) {
        HeapNode node{i, 0, a[static_cast<size_t>(i)] * b[0]};
        heap.push(node);
    }

    ProblemOutput result;
    result.reserve(static_cast<size_t>(k));

    while (!heap.empty() && static_cast<i32>(result.size()) < k) {
        const auto cur = heap.top();
        heap.pop();
        result.push_back(cur.val);
        const i32 ci = cur.i;
        const i32 cj = cur.j + 1;
        if (cj < m) {
            HeapNode next{ci, cj, a[static_cast<size_t>(ci)] * b[static_cast<size_t>(cj)]};
            heap.push(next);
        }
    }

    return result;
}

// Write: output K numbers separated by spaces in ascending order
void write_output(const ProblemOutput &out) {
    const size_t sz = out.size();
    for (size_t idx = 0; idx < sz; ++idx) {
        if (idx) std::cout << ' ';
        std::cout << out[idx];
    }
    std::cout << end;
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
