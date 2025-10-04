// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_10_A: shortest path from 1 to n (Dijkstra)

#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <cstdlib>
#include <ctime>

namespace graph {
struct Edge {
    int32_t to; // 边的终点
    int32_t next; // 同一个起点的下一条边的索引
    int64_t weight; // 边的权重
};

class Graph {
public:
    std::vector<int32_t> head; // head[i] 存储顶点 i 的第一条边索引
    std::vector<Edge> edges; // 存储所有边
    int32_t edge_count; // 当前边数量

    Graph(int32_t num_nodes, int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(max_edges);
    }

    void add_edge(const int32_t u, const int32_t v, const int64_t w) {
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        edges[edge_count].next = head[u];
        head[u] = edge_count;
        ++edge_count;
    }
};
} // namespace graph

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_10_A {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;

static constexpr const char end{'\n'};

using input_type = std::vector<graph::Graph>;
using output_type = std::vector<int64_t>;

// Read input and construct graph(s).
// The problem statement describes a single test case with n and m on the first line.
static input_type read_all() {
    int32_t n = 0, m = 0;
    if (!(std::cin >> n >> m)) return {};
    input_type cases;
    cases.reserve(1);
    graph::Graph g(n, m);
    int32_t u = 0, v = 0;
    int64_t w = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    cases.push_back(std::move(g));
    return cases;
}

// Dijkstra for single graph, return -1 if unreachable
static int64_t dijkstra_shortest(const graph::Graph &g) {
    const size_t n = (g.head.size() > 0 ? g.head.size() - 1 : 0);
    if (n == 0) return -1;
    const int src = 1;
    const int dst = static_cast<int>(n);
    const int64_t INF = std::numeric_limits<int64_t>::max() / 4;
    std::vector<int64_t> dist(n + 1, INF);
    using P = std::pair<int64_t, int32_t>;
    std::priority_queue<P, std::vector<P>, std::greater<P> > pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        int64_t d;
        int32_t u;
        std::tie(d, u) = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        if (u == dst) break;
        for (int32_t ei = g.head[u]; ei != -1; ei = g.edges[static_cast<size_t>(ei)].next) {
            const auto &e = g.edges[static_cast<size_t>(ei)];
            const int32_t v = e.to;
            const int64_t nd = d + e.weight;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }
    if (dist[dst] >= INF / 2) return -1;
    return dist[dst];
}

// Compute outputs for all input graphs
static output_type cal(const input_type &inputs) {
    output_type outs;
    outs.reserve(inputs.size());
    for (const auto &g: inputs) {
        outs.push_back(dijkstra_shortest(g));
    }
    return outs;
}

// Print outputs one per line
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
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
