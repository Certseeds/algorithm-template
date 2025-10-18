// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_09_D: select non-adjacent numbers (8-connected) maximize sum

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

namespace graph {
struct Edge {
    int32_t to;
    int32_t next;
    int64_t weight;
};

class Graph {
public:
    std::vector<int32_t> head;
    std::vector<Edge> edges;
    size_t edge_count;

public:
    Graph(int32_t num_nodes, int32_t max_edges) : edge_count(0) {
        head.assign(static_cast<size_t>(num_nodes) + 1, -1);
        edges.resize(static_cast<size_t>(max_edges));
    }

    void add_edge(const int32_t u, const int32_t v, const int64_t w) {
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        edges[edge_count].next = head[static_cast<size_t>(u)];
        head[static_cast<size_t>(u)] = edge_count;
        ++edge_count;
    }

    void add_undirected_edge(const int32_t u, const int32_t v, const int64_t w) {
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
};
}
#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_09_D {
#endif

using std::int32_t;
using std::int64_t;
using size_type = std::size_t;
static constexpr char end = '\n';

struct TestCase {
    int32_t n;
    int32_t m;
    std::vector<std::vector<int64_t> > a; // values
};

using input_type = std::vector<TestCase>;
using output_type = std::vector<int64_t>;

// Read all test cases
static input_type read_all() {
    int32_t T = 0;
    if (!(std::cin >> T)) return {};
    input_type cases;
    cases.reserve(static_cast<size_type>(T));
    for (int32_t tc = 0; tc < T; ++tc) {
        TestCase c{};
        std::cin >> c.n >> c.m;
        c.a.assign(static_cast<size_type>(c.n), std::vector<int64_t>(static_cast<size_type>(c.m), 0));
        for (int32_t i = 0; i < c.n; ++i) {
            for (int32_t j = 0; j < c.m; ++j) {
                std::cin >> c.a[static_cast<size_type>(i)][static_cast<size_type>(j)];
            }
        }
        cases.push_back(std::move(c));
    }
    return cases;
}

// For each test case compute answer using mask DP over rows
static output_type cal(const input_type &inputs) {
    output_type outputs;
    outputs.reserve(inputs.size());
    for (const auto &tc: inputs) {
        const int32_t n = tc.n;
        const int32_t m = tc.m;

        // Build graph representation (kept for compatibility)
        const int32_t nodes = n * m;
        graph::Graph g(nodes, nodes * 8);
        constexpr int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        constexpr int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                const int u = r * m + c + 1;
                for (int k = 0; k < 8; ++k) {
                    const int nr = r + dr[k];
                    const int nc = c + dc[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        const int v = nr * m + nc + 1;
                        g.add_edge(u, v, 0);
                    }
                }
            }
        }

        // Precompute valid masks and row sums
        const int max_mask = 1 << m;
        std::vector<int64_t> row_sum(max_mask, 0);
        std::vector<char> valid_mask(max_mask, 0);
        for (int mask = 0; mask < max_mask; ++mask) {
            if (mask & (mask << 1)) {
                // adjacent in row
                valid_mask[mask] = 0;
                continue;
            }
            valid_mask[mask] = 1;
        }

        // dp over rows: prev -> curr
        constexpr int64_t NEG = std::numeric_limits<int64_t>::min() / 4;
        std::vector<int64_t> dp_prev(max_mask, NEG), dp_curr(max_mask, NEG);

        // initialize for row 0
        for (int mask = 0; mask < max_mask; ++mask) {
            if (!valid_mask[mask]) {
                continue;
            }
            int64_t s = 0;
            for (int col = 0; col < m; ++col)
                if (mask & (1 << col)) {
                    {
                        s += tc.a[0][static_cast<size_type>(col)];
                    }
                }
            dp_prev[mask] = s;
        }

        // process remaining rows
        for (int row = 1; row < n; ++row) {
            std::fill(dp_curr.begin(), dp_curr.end(), NEG);
            for (int mask = 0; mask < max_mask; ++mask) {
                if (!valid_mask[mask]) {
                    continue;
                }
                // compute row sum
                int64_t s = 0;
                for (int col = 0; col < m; ++col) {
                    if (mask & (1 << col)) {
                        s += tc.a[static_cast<size_type>(row)][static_cast<size_type>(col)];
                    }
                }
                // transition from prev_mask
                for (int pm = 0; pm < max_mask; ++pm) {
                    if (!valid_mask[pm]) {
                        continue;
                    }
                    // no vertical conflict and no diagonal conflict
                    if ((mask & pm) != 0) {
                        continue;
                    }
                    if (((mask << 1) & pm) != 0) {
                        continue;
                    }
                    if (((mask >> 1) & pm) != 0) {
                        continue;
                    }
                    dp_curr[mask] = std::max(dp_curr[mask], dp_prev[pm] + s);
                }
            }
            dp_prev.swap(dp_curr);
        }

        int64_t ans = 0;
        for (int mask = 0; mask < max_mask; ++mask) {
            if (valid_mask[mask]) {
                ans = std::max(ans, dp_prev[mask]);
            }
        }
        outputs.push_back(ans);
    }
    return outputs;
}

// Output answers
static void output_all(const output_type &outs) {
    for (const auto &v: outs) {
        std::cout << v << end;
    }
}

int main() {
    const auto inputs = read_all();
    const auto results = cal(inputs);
    output_all(results);
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
