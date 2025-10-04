// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_10_F: minimum edges to strongly connect directed graph
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
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
    std::vector<int32_t> head;
    std::vector<Edge> edges;
    int32_t edge_count;

    Graph(const int32_t num_nodes, const int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(static_cast<size_t>(max_edges + 5));
    }

    void add_edge(const int32_t u, const int32_t v, const int64_t w) {
        edges[static_cast<size_t>(edge_count)].to = v;
        edges[static_cast<size_t>(edge_count)].weight = w;
        edges[static_cast<size_t>(edge_count)].next = head[static_cast<size_t>(u)];
        head[static_cast<size_t>(u)] = edge_count;
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
namespace lab_10_F {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;
using std::vector;

static constexpr const char end{'\n'};

struct Case {
    graph::Graph graph;
    int32_t n;

    Case(const int32_t nodes, const int32_t edges) : graph(nodes, edges), n(nodes) {
    }
};

using input_type = vector<Case>;
using output_type = vector<int32_t>;

static input_type read_all();

static output_type cal(const input_type &cases);

static void output_all(const output_type &outs);

static int32_t tarjan_scc(const graph::Graph &g, vector<int32_t> &comp);

static int32_t solve_case(const Case &cs);

int main() {
    const auto cases = read_all();
    const auto outs = cal(cases);
    output_all(outs);
    return 0;
}

static input_type read_all() {
    int32_t n = 0;
    int32_t m = 0;
    if (!(std::cin >> n >> m)) return {};
    Case cs(n, m);
    int32_t u = 0;
    int32_t v = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v;
        cs.graph.add_edge(u, v, 0);
    }
    input_type cases;
    cases.reserve(1);
    cases.push_back(std::move(cs));
    return cases;
}

static int32_t tarjan_scc(const graph::Graph &g, vector<int32_t> &comp) {
    const int32_t n = static_cast<int32_t>(g.head.size()) - 1;
    vector<int32_t> dfn(static_cast<size_t>(n + 1), 0);
    vector<int32_t> low(static_cast<size_t>(n + 1), 0);
    vector<uint8_t> in_stack(static_cast<size_t>(n + 1), 0);
    vector<int32_t> node_stack;
    node_stack.reserve(static_cast<size_t>(n));
    struct Frame {
        int32_t node;
        int32_t edge;
        int32_t child;
    };
    vector<Frame> dfs_stack;
    dfs_stack.reserve(static_cast<size_t>(n));
    int32_t timer = 0;
    int32_t comp_cnt = 0;
    for (int32_t start = 1; start <= n; ++start) {
        if (dfn[static_cast<size_t>(start)] != 0) continue;
        dfs_stack.push_back(Frame{start, g.head[static_cast<size_t>(start)], -1});
        dfn[static_cast<size_t>(start)] = low[static_cast<size_t>(start)] = ++timer;
        in_stack[static_cast<size_t>(start)] = 1;
        node_stack.push_back(start);
        while (!dfs_stack.empty()) {
            Frame &frame = dfs_stack.back();
            const int32_t u = frame.node;
            if (frame.child != -1) {
                const int32_t child = frame.child;
                if (low[static_cast<size_t>(child)] < low[static_cast<size_t>(u)]) {
                    low[static_cast<size_t>(u)] = low[static_cast<size_t>(child)];
                }
                frame.child = -1;
            }
            if (frame.edge == -1) {
                dfs_stack.pop_back();
                if (low[static_cast<size_t>(u)] == dfn[static_cast<size_t>(u)]) {
                    ++comp_cnt;
                    while (true) {
                        const int32_t x = node_stack.back();
                        node_stack.pop_back();
                        in_stack[static_cast<size_t>(x)] = 0;
                        comp[static_cast<size_t>(x)] = comp_cnt;
                        if (x == u) break;
                    }
                }
                continue;
            }
            const int32_t ei = frame.edge;
            frame.edge = g.edges[static_cast<size_t>(ei)].next;
            const int32_t v = g.edges[static_cast<size_t>(ei)].to;
            if (dfn[static_cast<size_t>(v)] == 0) {
                dfs_stack.push_back(Frame{v, g.head[static_cast<size_t>(v)], -1});
                dfn[static_cast<size_t>(v)] = low[static_cast<size_t>(v)] = ++timer;
                in_stack[static_cast<size_t>(v)] = 1;
                node_stack.push_back(v);
                frame.child = v;
                continue;
            }
            if (in_stack[static_cast<size_t>(v)] && dfn[static_cast<size_t>(v)] < low[static_cast<size_t>(u)]) {
                low[static_cast<size_t>(u)] = dfn[static_cast<size_t>(v)];
            }
        }
    }
    return comp_cnt;
}

static int32_t solve_case(const Case &cs) {
    const int32_t n = cs.n;
    vector<int32_t> component(static_cast<size_t>(n + 1), 0);
    const int32_t comp_cnt = tarjan_scc(cs.graph, component);
    if (comp_cnt == 1) return 0;
    vector<int32_t> indeg(static_cast<size_t>(comp_cnt + 1), 0);
    vector<int32_t> outdeg(static_cast<size_t>(comp_cnt + 1), 0);
    for (int32_t u = 1; u <= n; ++u) {
        const int32_t cu = component[static_cast<size_t>(u)];
        for (int32_t ei = cs.graph.head[static_cast<size_t>(u)]; ei != -1;
             ei = cs.graph.edges[static_cast<size_t>(ei)].next) {
            const int32_t v = cs.graph.edges[static_cast<size_t>(ei)].to;
            const int32_t cv = component[static_cast<size_t>(v)];
            if (cu != cv) {
                ++outdeg[static_cast<size_t>(cu)];
                ++indeg[static_cast<size_t>(cv)];
            }
        }
    }
    int32_t zero_in = 0;
    int32_t zero_out = 0;
    for (int32_t id = 1; id <= comp_cnt; ++id) {
        if (indeg[static_cast<size_t>(id)] == 0) ++zero_in;
        if (outdeg[static_cast<size_t>(id)] == 0) ++zero_out;
    }
    return std::max(zero_in, zero_out);
}

static output_type cal(const input_type &cases) {
    output_type outs;
    outs.reserve(cases.size());
    for (const auto &cs: cases) {
        outs.push_back(solve_case(cs));
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
