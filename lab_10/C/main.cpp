// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

namespace graph {
struct Edge {
    int32_t u, v;
    int64_t w;
};

class Graph {
public:
    std::vector<Edge> edges;
    int32_t n, m;

    Graph(int32_t num_nodes, int32_t max_edges) : n(num_nodes), m(0) {
        edges.reserve(static_cast<size_t>(max_edges));
    }

    void add_undirected_edge(const int32_t u, const int32_t v, const int64_t w) {
        edges.push_back({u, v, w});
        ++m;
    }
};
}

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_10_C {
#endif
using std::cin;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

struct Case {
    graph::Graph g;

    Case(int32_t n, int32_t m): g(n, m) {
    }
};

using input_type = std::vector<Case>;
using output_type = std::vector<int64_t>;

// 读取输入
static input_type read_all() {
    int32_t n = 0, m = 0;
    if (!(cin >> n >> m)) return {};
    input_type cases;
    cases.reserve(1);
    Case cs(n, m);
    for (int32_t i = 0; i < m; ++i) {
        int32_t u = 0, v = 0;
        int64_t w = 0;
        cin >> u >> v >> w;
        cs.g.add_undirected_edge(u, v, w);
    }
    cases.push_back(std::move(cs));
    return cases;
}

// Kruskal MST
static int64_t kruskal_mst(const graph::Graph &g) {
    const int32_t n = g.n;
    std::vector<int32_t> fa(n + 1);
    for (int32_t i = 1; i <= n; ++i) fa[i] = i;
    auto find = [&](int32_t x) {
        while (fa[x] != x) x = fa[x] = fa[fa[x]];
        return x;
    };
    int64_t total = 0;
    int32_t cnt = 0;
    std::vector<graph::Edge> edges = g.edges;
    std::sort(edges.begin(), edges.end(), [](const graph::Edge &a, const graph::Edge &b) {
        return a.w < b.w;
    });
    for (const auto &e: edges) {
        int32_t fu = find(e.u), fv = find(e.v);
        if (fu != fv) {
            fa[fu] = fv;
            total += e.w;
            ++cnt;
            if (cnt == n - 1) break;
        }
    }
    return total;
}

// 计算所有用例的结果
static output_type cal(const input_type &inputs) {
    output_type outs;
    outs.reserve(inputs.size());
    for (const auto &cs: inputs) {
        outs.push_back(kruskal_mst(cs.g));
    }
    return outs;
}

// 输出结果
static void output_all(const output_type &outs) {
    for (const auto &v: outs) {
        cout << v << end;
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
