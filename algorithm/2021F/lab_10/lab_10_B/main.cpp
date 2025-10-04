// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

namespace graph {
struct Edge {
    int32_t to; // 终点
    int32_t next; // 下一条边索引
    int64_t weight; // 权重 (未使用)
};

class Graph {
public:
    std::vector<int32_t> head; // head[i] 为顶点 i 的第一条边索引
    std::vector<Edge> edges; // 存储所有边
    int32_t edge_count;

    Graph(int32_t num_nodes, int32_t max_edges) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(max_edges);
    }

    void add_edge(const int32_t u, const int32_t v, const int64_t w = 0) {
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        edges[edge_count].next = head[u];
        head[u] = edge_count;
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
namespace lab_10_B {
#endif

using std::cin;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

// Each case stores both forward and reverse graphs
struct Case {
    graph::Graph forward;
    graph::Graph reverse;

    Case(int32_t n, int32_t m): forward(n, m), reverse(n, m) {
    }
};

using input_type = std::vector<Case>;
using output_type = std::vector<int64_t>;

// Read input: single test case with n m then m directed edges (u v)
static input_type read_all() {
    int32_t n = 0, m = 0;
    if (!(cin >> n >> m)) return {};
    input_type cases;
    cases.reserve(1);
    Case cs(n, m);
    int32_t u = 0, v = 0;
    for (int32_t i = 0; i < m; ++i) {
        cin >> u >> v;
        cs.forward.add_edge(u, v, 0);
        cs.reverse.add_edge(v, u, 0);
    }
    cases.push_back(std::move(cs));
    return cases;
}

// Check whether first k edges make the directed graph strongly connected
static bool prefix_strongly_connected(const int32_t n, const graph::Graph &forward, const graph::Graph &reverse,
                                      const int32_t k) {
    if (n <= 1) {
        return true;
    }
    std::vector<char> vis(n + 1, 0);
    std::vector<int32_t> stk;
    stk.reserve(n);
    stk.push_back(1);
    vis[1] = 1;
    int32_t cnt = 0;
    while (!stk.empty()) {
        const int32_t u = stk.back();
        stk.pop_back();
        ++cnt;
        for (int32_t ei = forward.head[static_cast<size_t>(u)]; ei != -1;
             ei = forward.edges[static_cast<size_t>(ei)].next) {
            if (ei >= k) continue;
            int32_t v = forward.edges[static_cast<size_t>(ei)].to;
            if (!vis[v]) {
                vis[v] = 1;
                stk.push_back(v);
            }
        }
    }
    if (cnt != n) return false;
    // Reverse DFS
    vis.assign(n + 1, 0);
    cnt = 0;
    stk.clear();
    stk.push_back(1);
    vis[1] = 1;
    while (!stk.empty()) {
        const int32_t u = stk.back();
        stk.pop_back();
        ++cnt;
        for (int32_t ei = reverse.head[static_cast<size_t>(u)]; ei != -1;
             ei = reverse.edges[static_cast<size_t>(ei)].next) {
            if (ei >= k) continue;
            int32_t v = reverse.edges[static_cast<size_t>(ei)].to;
            if (!vis[v]) {
                vis[v] = 1;
                stk.push_back(v);
            }
        }
    }
    return cnt == n;
}

// For each case compute minimal prefix length to be strongly connected, or -1
static output_type cal(const input_type &inputs) {
    output_type outs;
    outs.reserve(inputs.size());
    for (const auto &cs: inputs) {
        const auto n = static_cast<int32_t>(cs.forward.head.size() > 0 ? cs.forward.head.size() - 1 : 0);
        const auto m = static_cast<int32_t>(cs.forward.edge_count);
        if (n <= 1) {
            outs.push_back(0);
            continue;
        }
        int32_t l = 1, r = m, ans = -1;
        while (l <= r) {
            const int32_t mid = l + ((r - l) >> 1);
            if (prefix_strongly_connected(n, cs.forward, cs.reverse, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == -1) outs.push_back(-1);
        else outs.push_back(ans);
    }
    return outs;
}

// Output results
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
