// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <utility>
#include <queue>

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

// Use STL priority_queue as min-heap (via greater comparator)
struct MinComp {
    bool operator()(i64 l, i64 r) const { return l > r; }
};

// Solve: Huffman-style merging minimal total cost
ProblemOutput solve(const ProblemInput &in) {
    const i32 n = in.n;
    if (n <= 1) return 0;

    std::priority_queue<i64, std::vector<i64>, MinComp> heap;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
