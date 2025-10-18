// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_10_D: minimum spanning tree on hexagonal grid
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

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

    Graph(const int32_t num_nodes, const int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(static_cast<size_t>(max_edges));
    }

    void add_edge(const int32_t u, const int32_t v, const int64_t w) {
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        edges[edge_count].next = head[u];
        head[u] = edge_count;
        ++edge_count;
    }

    void add_undirected_edge(const int32_t u, const int32_t v, const int64_t w) {
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
};
} // namespace graph

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_10_D {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;

static constexpr const char end{'\n'};

using input_type = std::vector<graph::Graph>;
using output_type = std::vector<int64_t>;

static graph::Graph build_graph_from_input(const int32_t n);

static input_type read_all();

static int64_t minimum_spanning_tree(const graph::Graph &g);

static output_type cal(const input_type &inputs);

static void output_all(const output_type &outs);

int main() {
    const auto inputs = read_all();
    const auto outs = cal(inputs);
    output_all(outs);
    return 0;
}

static graph::Graph build_graph_from_input(const int32_t n) {
    const auto node_count = static_cast<int32_t>(3 * n * n + 3 * n + 1);
    const int64_t raw_edge_count = 9LL * n * n + 3LL * n;
    const auto max_edges = static_cast<int32_t>(raw_edge_count * 2 + 8);
    graph::Graph g(node_count, max_edges);
    const auto rows = static_cast<int32_t>(2 * n + 1);
    std::vector<int32_t> q_min(rows, 0);
    std::vector<int32_t> q_max(rows, 0);
    std::vector<int32_t> row_len(rows, 0);
    std::vector<std::vector<int32_t> > index(rows);
    std::vector<int64_t> weights(static_cast<size_t>(node_count + 1), 0);
    int32_t current = 0;
    for (int32_t i = 0; i < rows; ++i) {
        const int32_t r = i - n;
        const int32_t min_q = std::max(-n, -n - r);
        const int32_t max_q = std::min(n, n - r);
        q_min[i] = min_q;
        q_max[i] = max_q;
        const int32_t len = max_q - min_q + 1;
        row_len[i] = len;
        index[i].resize(static_cast<size_t>(len));
        for (int32_t j = 0; j < len; ++j) {
            int64_t w = 0;
            std::cin >> w;
            ++current;
            weights[static_cast<size_t>(current)] = w;
            index[i][j] = current;
        }
    }

    for (int32_t i = 0; i < rows; ++i) {
        const int32_t r = i - n;
        for (int32_t j = 0; j < row_len[i]; ++j) {
            const int32_t u = index[i][j];
            const int32_t q = q_min[i] + j;
            if (j + 1 < row_len[i]) {
                const int32_t v = index[i][static_cast<size_t>(j + 1)];
                const int64_t weight = weights[u] * weights[v];
                g.add_undirected_edge(u, v, weight);
            }
            const int32_t next_row = r + 1;
            if (next_row <= n) {
                const int32_t i2 = next_row + n;
                const int32_t q_cur = q;
                if (q_cur >= q_min[i2] && q_cur <= q_max[i2]) {
                    const int32_t v = index[i2][static_cast<size_t>(q_cur - q_min[i2])];
                    const int64_t weight = weights[u] * weights[v];
                    g.add_undirected_edge(u, v, weight);
                }
                const int32_t q_left = q_cur - 1;
                if (q_left >= q_min[i2] && q_left <= q_max[i2]) {
                    const int32_t v = index[i2][static_cast<size_t>(
                        q_left - q_min[i2])];
                    const int64_t weight = weights[u] * weights[v];
                    g.add_undirected_edge(u, v, weight);
                }
            }
        }
    }

    g.edges.resize(static_cast<size_t>(g.edge_count));
    return g;
}

static input_type read_all() {
    int32_t n = 0;
    if (!(std::cin >> n)) return {};
    input_type cases;
    cases.reserve(1);
    cases.emplace_back(build_graph_from_input(n));
    return cases;
}

static int64_t minimum_spanning_tree(const graph::Graph &g) {
    const size_t n = g.head.size() > 0 ? g.head.size() - 1 : 0;
    if (n == 0) return 0;
    constexpr int64_t INF = std::numeric_limits<int64_t>::max();
    std::vector<int64_t> min_weight(n + 1, INF);
    std::vector<bool> used(n + 1, false);
    using Item = std::pair<int64_t, int32_t>;
    std::priority_queue<Item, std::vector<Item>, std::greater<Item> > pq;
    min_weight[1] = 0;
    pq.emplace(0, 1);
    int32_t visited = 0;
    int64_t result = 0;
    while (!pq.empty() && visited < static_cast<int32_t>(n)) {
        const Item current = pq.top();
        pq.pop();
        const int64_t weight = current.first;
        const int32_t node = current.second;
        if (used[static_cast<size_t>(node)]) continue;
        used[static_cast<size_t>(node)] = true;
        ++visited;
        result += weight;
        for (int32_t ei = g.head[static_cast<size_t>(node)]; ei != -1; ei = g.edges[static_cast<size_t>(ei)].next) {
            const auto &edge = g.edges[static_cast<size_t>(ei)];
            if (!used[static_cast<size_t>(edge.to)] && edge.weight < min_weight[static_cast<size_t>(edge.to)]) {
                min_weight[static_cast<size_t>(edge.to)] = edge.weight;
                pq.emplace(edge.weight, edge.to);
            }
        }
    }
    return result;
}

static output_type cal(const input_type &inputs) {
    output_type outs;
    outs.reserve(inputs.size());
    for (const auto &g: inputs) {
        outs.push_back(minimum_spanning_tree(g));
    }
    return outs;
}

static void output_all(const output_type &outs) {
    for (const auto &value: outs) {
        std::cout << value << end;
    }
}

static const auto faster_streams = [] {
    std::srand(std::time(nullptr));
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
