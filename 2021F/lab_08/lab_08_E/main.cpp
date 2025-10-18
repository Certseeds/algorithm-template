// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>

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

// Use STL priority_queue for lower (max-heap) and upper (min-heap)
struct MaxComp {
    bool operator()(i64 l, i64 r) const { return l < r; } // max-heap
};
struct MinComp {
    bool operator()(i64 l, i64 r) const { return l > r; } // min-heap
};

ProblemOutput solve(const ProblemInput &in) {
    const i32 n = in.n;
    ProblemOutput res;
    res.reserve(static_cast<size_t>(n));

    std::priority_queue<i64, std::vector<i64>, MaxComp> lower; // max-heap
    std::priority_queue<i64, std::vector<i64>, MinComp> upper; // min-heap
    // reserve not available for priority_queue; underlying vector resizes as needed

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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
