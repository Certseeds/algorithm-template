// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

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
    int32_t edge_count;

    Graph(int32_t num_nodes, int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(static_cast<size_t>(max_edges));
    }

    void add_edge(int32_t u, int32_t v, int64_t w = 0) {
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
namespace lab_10_G {
#endif
using std::int32_t;
using std::int64_t;
using std::vector;
static constexpr const char end{'\n'};

struct Case {
    graph::Graph g;
    vector<int64_t> cost;
    int32_t n;

    Case(int32_t n_, int32_t m_, int32_t j_): g(n_, m_), cost(n_ + 1, -1), n(n_) {
    }
};

static constexpr int64_t INF_COST = (int64_t) 4e18;

struct Answer {
    bool ok;
    int64_t val;
};

using input_type = vector<Case>;
using output_type = vector<Answer>;

// Read all input (single case expected)
static input_type read_all() {
    int32_t n = 0;
    if (!(std::cin >> n)) return {};
    int32_t j = 0;
    std::cin >> j;
    Case cs(n, 0, j); // temp zero edges, will resize later
    // store costs
    for (int32_t i = 0; i < j; ++i) {
        int32_t b;
        int64_t w;
        std::cin >> b >> w;
        cs.cost[b] = w;
    }
    int32_t k = 0;
    std::cin >> k;
    cs.g = graph::Graph(n, k); // re-init graph with edge capacity k
    for (int32_t i = 0; i < k; ++i) {
        int32_t u, v;
        std::cin >> u >> v;
        cs.g.add_edge(u, v, 0);
    }
    input_type cases;
    cases.reserve(1);
    cases.push_back(std::move(cs));
    return cases;
}

// Tarjan SCC
struct TarjanData {
    vector<int32_t> dfn, low, comp, stack;
    vector<char> in_st;
    int32_t timer{0}, comp_cnt{0};
};

static void tarjan_dfs(int32_t u, const graph::Graph &g, TarjanData &td) {
    td.dfn[u] = td.low[u] = ++td.timer;
    td.stack.push_back(u);
    td.in_st[u] = 1;
    for (int32_t ei = g.head[u]; ei != -1; ei = g.edges[ei].next) {
        int32_t v = g.edges[ei].to;
        if (!td.dfn[v]) {
            tarjan_dfs(v, g, td);
            if (td.low[v] < td.low[u]) td.low[u] = td.low[v];
        } else if (td.in_st[v] && td.dfn[v] < td.low[u]) {
            td.low[u] = td.dfn[v];
        }
    }
    if (td.low[u] == td.dfn[u]) {
        ++td.comp_cnt;
        while (true) {
            int32_t x = td.stack.back();
            td.stack.pop_back();
            td.in_st[x] = 0;
            td.comp[x] = td.comp_cnt;
            if (x == u) break;
        }
    }
}

static Answer solve(const Case &cs) {
    const int32_t n = cs.n;
    TarjanData td;
    td.dfn.assign(n + 1, 0);
    td.low.assign(n + 1, 0);
    td.comp.assign(n + 1, 0);
    td.in_st.assign(n + 1, 0);
    td.stack.reserve(n);
    for (int32_t i = 1; i <= n; ++i) if (!td.dfn[i]) tarjan_dfs(i, cs.g, td);
    const int32_t C = td.comp_cnt;
    vector<int32_t> indeg(C + 1, 0);
    vector<int64_t> min_cost(C + 1, INF_COST);
    vector<int32_t> comp_min_id(C + 1, 0);
    // gather per component data
    for (int32_t u = 1; u <= n; ++u) {
        int32_t cu = td.comp[u];
        if (comp_min_id[cu] == 0 || u < comp_min_id[cu]) comp_min_id[cu] = u;
        if (cs.cost[u] >= 0 && cs.cost[u] < min_cost[cu]) min_cost[cu] = cs.cost[u];
        for (int32_t ei = cs.g.head[u]; ei != -1; ei = cs.g.edges[ei].next) {
            int32_t v = cs.g.edges[ei].to;
            int32_t cv = td.comp[v];
            if (cu != cv) ++indeg[cv];
        }
    }
    int64_t total = 0;
    int32_t bad_min = 0;
    for (int32_t c = 1; c <= C; ++c) {
        if (indeg[c] == 0) {
            if (min_cost[c] >= INF_COST) {
                // need but not available
                int32_t cand = comp_min_id[c];
                if (bad_min == 0 || cand < bad_min) bad_min = cand;
            } else {
                total += min_cost[c];
            }
        }
    }
    if (bad_min != 0) return {false, bad_min};
    return {true, total};
}

static output_type cal(const input_type &inputs) {
    output_type outs;
    outs.reserve(inputs.size());
    for (const auto &cs: inputs) { outs.push_back(solve(cs)); }
    return outs;
}

static void output_all(const output_type &outs) {
    for (const auto &ans: outs) {
        if (ans.ok) {
            std::cout << "YES" << end << ans.val << end;
        } else {
            std::cout << "NO" << end << ans.val << end;
        }
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
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
