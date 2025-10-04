// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_E {
#endif
using std::cin;
using std::cout;
using std::tie;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using i32 = int32_t;
using i64 = int64_t;

struct ProblemInput {
    i32 n;
    std::vector<i64> a;
};

using ProblemOutput = std::vector<i64>;

// Declarations for three-stage style
ProblemInput read_input();

ProblemOutput solve(const ProblemInput &in);

void write_output(const ProblemOutput &out);

int main() {
    const auto in = read_input();
    const auto out = solve(in);
    write_output(out);
    return 0;
}

ProblemInput read_input() {
    ProblemInput in;
    std::cin >> in.n;
    in.a.assign(static_cast<size_t>(in.n), 0);
    for (i32 i = 0; i < in.n; ++i) {
        std::cin >> in.a[static_cast<size_t>(i)];
    }
    return in;
}

// Custom max-heap for lower half
struct MaxHeap {
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
    static inline bool less_than(i64 l, i64 r) { return l > r; } // reverse for max-heap
    void sift_up(size_t idx) {
        while (idx > 0) {
            size_t p = (idx - 1) >> 1;
            if (!less_than(data[idx], data[p])) break;
            std::swap(data[idx], data[p]);
            idx = p;
        }
    }

    void sift_down(size_t idx) {
        const size_t n = data.size();
        while (true) {
            size_t l = idx * 2 + 1;
            size_t r = l + 1;
            size_t best = idx;
            if (l < n && less_than(data[l], data[best])) best = l;
            if (r < n && less_than(data[r], data[best])) best = r;
            if (best == idx) break;
            std::swap(data[idx], data[best]);
            idx = best;
        }
    }
};

// Custom min-heap for upper half
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
            size_t p = (idx - 1) >> 1;
            if (!less_than(data[idx], data[p])) break;
            std::swap(data[idx], data[p]);
            idx = p;
        }
    }

    void sift_down(size_t idx) {
        const size_t n = data.size();
        while (true) {
            size_t l = idx * 2 + 1;
            size_t r = l + 1;
            size_t best = idx;
            if (l < n && less_than(data[l], data[best])) best = l;
            if (r < n && less_than(data[r], data[best])) best = r;
            if (best == idx) break;
            std::swap(data[idx], data[best]);
            idx = best;
        }
    }
};

ProblemOutput solve(const ProblemInput &in) {
    const i32 n = in.n;
    ProblemOutput res;
    res.reserve(static_cast<size_t>(n));

    MaxHeap lower; // max-heap, contains the smaller half
    MinHeap upper; // min-heap, contains the larger half
    lower.data.reserve(static_cast<size_t>((n + 1) / 2));
    upper.data.reserve(static_cast<size_t>(n / 2));

    for (i32 idx = 0; idx < n; ++idx) {
        const i64 x = in.a[static_cast<size_t>(idx)];
        if (lower.empty() || x <= lower.top()) {
            lower.push(x);
        } else {
            upper.push(x);
        }

        // rebalance: ensure lower.size() >= upper.size() and difference <= 1
        if (static_cast<i32>(lower.size()) > static_cast<i32>(upper.size()) + 1) {
            const i64 v = lower.top();
            lower.pop();
            upper.push(v);
        } else if (static_cast<i32>(lower.size()) < static_cast<i32>(upper.size())) {
            const i64 v = upper.top();
            upper.pop();
            lower.push(v);
        }

        // median is top of lower (ceil(i/2)-th)
        res.push_back(lower.top());
    }

    return res;
}

void write_output(const ProblemOutput &out) {
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << out[i];
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
