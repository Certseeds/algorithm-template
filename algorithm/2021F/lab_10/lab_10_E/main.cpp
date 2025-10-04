// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

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
    int32_t edge_count;

    Graph(const int32_t num_nodes, const int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(static_cast<size_t>(max_edges + 5));
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
namespace lab_10_E {
#endif

using std::int32_t;
using std::int64_t;
using std::size_t;
using std::vector;
static constexpr const char end{'\n'};

struct Case {
    graph::Graph roads;
    graph::Graph portals;
    int32_t original_n;
    int32_t k;
    int32_t S;
    int32_t T;

    Case(const int32_t n_, const int32_t max_roads, const int32_t max_portals)
        : roads(n_, max_roads), portals(n_, max_portals), original_n(n_), k(0), S(0), T(0) {
    }
};

using input_type = vector<Case>;
using output_type = vector<int64_t>;

// Read input and build base graphs for roads and portals
static input_type read_all() {
    int32_t n = 0, m = 0, p = 0, k = 0;
    if (!(std::cin >> n >> m >> p >> k)) return {};
    input_type cases;
    cases.reserve(1);
    Case cs(n, m, p);
    cs.k = k;
    int32_t u = 0;
    int32_t v = 0;
    int64_t w = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        cs.roads.add_edge(u, v, w);
    }
    for (int32_t i = 0; i < p; ++i) {
        std::cin >> u >> v;
        cs.portals.add_edge(u, v, 0);
    }
    std::cin >> cs.S >> cs.T;
    cases.push_back(std::move(cs));
    return cases;
}

// Compute shortest distance with at most k portals
static int64_t solve(const Case &cs) {
    const int32_t n = cs.original_n;
    const int32_t layers = cs.k + 1;
    const int32_t total_nodes = layers * n;
    constexpr int64_t INF = std::numeric_limits<int64_t>::max() / 4;
    vector<int64_t> dist(static_cast<size_t>(total_nodes + 1), INF);
    using Item = std::pair<int64_t, int32_t>;
    std::priority_queue<Item, vector<Item>, std::greater<Item> > pq;
    const auto encode = [n](const int32_t layer, const int32_t node) -> int32_t {
        return layer * n + node;
    };
    const int32_t start_idx = encode(0, cs.S);
    dist[static_cast<size_t>(start_idx)] = 0;
    pq.emplace(0, start_idx);
    while (!pq.empty()) {
        const Item current = pq.top();
        pq.pop();
        const int64_t d = current.first;
        const int32_t idx = current.second;
        if (d != dist[static_cast<size_t>(idx)]) continue;
        const int32_t layer = (idx - 1) / n;
        const int32_t node = idx - layer * n;
        if (node == cs.T) return d;
        for (int32_t ei = cs.roads.head[static_cast<size_t>(node)]; ei != -1;
             ei = cs.roads.edges[static_cast<size_t>(ei)].next) {
            const auto &edge = cs.roads.edges[static_cast<size_t>(ei)];
            const int32_t next_idx = encode(layer, edge.to);
            const int64_t nd = d + edge.weight;
            if (nd < dist[static_cast<size_t>(next_idx)]) {
                dist[static_cast<size_t>(next_idx)] = nd;
                pq.emplace(nd, next_idx);
            }
        }
        if (layer < cs.k) {
            for (int32_t ei = cs.portals.head[static_cast<size_t>(node)]; ei != -1;
                 ei = cs.portals.edges[static_cast<size_t>(ei)].next) {
                const auto &edge = cs.portals.edges[static_cast<size_t>(ei)];
                const int32_t next_idx = encode(layer + 1, edge.to);
                if (d < dist[static_cast<size_t>(next_idx)]) {
                    dist[static_cast<size_t>(next_idx)] = d;
                    pq.emplace(d, next_idx);
                }
            }
        }
    }
    int64_t ans = INF;
    for (int32_t layer = 0; layer <= cs.k; ++layer) {
        const int32_t idx = encode(layer, cs.T);
        ans = std::min(ans, dist[static_cast<size_t>(idx)]);
    }
    return ans;
}

// Process all cases
static output_type cal(const input_type &cases) {
    output_type outs;
    outs.reserve(cases.size());
    for (const auto &cs: cases) {
        outs.push_back(solve(cs));
    }
    return outs;
}

// Output each result
static void output_all(const output_type &outs) {
    for (const auto &v: outs)
        std::cout << v << end;
}

int main() {
    const auto cases = read_all();
    const auto results = cal(cases);
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
