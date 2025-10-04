// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_09_E: shortest path with edge weights 1 or 2

#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <tuple>

namespace graph {
struct Edge {
    int32_t to;
    int32_t next;
    int64_t weight;
};

class Graph {
public:
    std::vector<int32_t> head; // 1-based
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
};
}
#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_09_E {
#endif
using std::cin;
using std::cout;
using std::int32_t;
using std::int64_t;
using std::tie;
using std::tuple;
using std::vector;
using size_type = std::size_t;
static constexpr const char end{'\n'};

// Input container
struct Input {
    graph::Graph g;
    int32_t n;
    int32_t m;

    explicit Input(int32_t n_, int32_t m_) : g(n_, m_), n(n_), m(m_) {
    }
};

using input_type = Input;
using output_type = int64_t;

// Read single test case: n m, then m lines u v w
static input_type read_input() {
    int32_t n = 0, m = 0;
    if (!(std::cin >> n >> m)) {
        return Input(0, 0);
    }
    input_type input(n, m);
    int32_t u = 0, v = 0;
    int64_t w = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            input.g.add_edge(u, v, w);
        }
    }
    return input;
}

// Dijkstra from 1 to n using chain-forward-star
static output_type cal(const input_type &input) {
    const int32_t n = input.n;
    if (n <= 0) return -1;
    constexpr int64_t INF = std::numeric_limits<int64_t>::max() / 4;
    std::vector<int64_t> dist(static_cast<size_type>(n + 1), INF);
    using Pair = std::pair<int64_t, int32_t>; // dist, node
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair> > pq;

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        int64_t d;
        int32_t u;
        std::tie(d, u) = pq.top();
        pq.pop();
        if (d != dist[static_cast<size_type>(u)]) continue;
        if (u == n) break; // early exit
        for (int32_t ei = input.g.head[static_cast<size_type>(u)]; ei != -1;
             ei = input.g.edges[static_cast<size_type>(ei)].next) {
            const int32_t v = input.g.edges[static_cast<size_type>(ei)].to;
            const int64_t w = input.g.edges[static_cast<size_type>(ei)].weight;
            if (dist[static_cast<size_type>(v)] > d + w) {
                dist[static_cast<size_type>(v)] = d + w;
                pq.emplace(dist[static_cast<size_type>(v)], v);
            }
        }
    }

    if (dist[static_cast<size_type>(n)] >= INF / 2) {
        return -1;
    }
    return dist[static_cast<size_type>(n)];
}

static void output_result(const output_type &res) {
    std::cout << res << end;
}

int main() {
    const auto input = read_input();
    const auto ans = cal(input);
    output_result(ans);
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
