// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

namespace tree {
struct Edge {
    int32_t to;
    int32_t next;
};

class Graph {
public:
    std::vector<int32_t> head;
    std::vector<Edge> edges;
    int32_t edge_count;

    Graph(int32_t num_nodes = 0, int32_t max_edges = 0) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(max_edges);
    }

    void reset(int32_t num_nodes, int32_t max_edges) {
        head.assign(num_nodes + 1, -1);
        edges.clear();
        edges.resize(max_edges);
        edge_count = 0;
    }

    void add_edge(const int32_t u, const int32_t v) {
        edges[edge_count].to = v;
        edges[edge_count].next = head[u];
        head[u] = edge_count++;
    }

    void add_undirected_edge(const int32_t u, const int32_t v) {
        add_edge(u, v);
        add_edge(v, u);
    }
};
}

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("native")
#else
namespace lab_07_G {
#endif

using int32 = std::int32_t;

static constexpr int32_t LOG = 19;

struct Input {
    int32 n;
    tree::Graph g;
};

struct Output {
    std::vector<std::vector<int32> > answers;
};

// 三段式: 读取 -> 计算 -> 输出
Input read_input() {
    Input in;
    int32 n = 0;
    if (!(std::cin >> n)) {
        in.n = 0;
        return in;
    }
    in.n = n;
    in.g.reset(n, (n - 1) * 2 + 5);
    for (int32 i = 0; i < n - 1; ++i) {
        int32 u = 0;
        int32 v = 0;
        std::cin >> u >> v;
        in.g.add_undirected_edge(u, v);
    }
    return in;
}

Output solve(const Input &in) {
    Output out;
    const int32 n = in.n;
    if (n == 0) {
        return out;
    }
    const auto &g = in.g;

    std::vector<int32> parent(n + 1, 0);
    std::vector<int32> depth(n + 1, 0);
    std::vector<int32> order;
    order.reserve(n);
    order.push_back(1);
    parent[1] = 0;
    depth[1] = 0;

    std::vector<std::vector<int32> > children(n + 1);

    for (size_t idx = 0; idx < order.size(); ++idx) {
        const int32 u = order[idx];
        for (int32 ei = g.head[u]; ei != -1; ei = g.edges[ei].next) {
            const int32 v = g.edges[ei].to;
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
            children[u].push_back(v);
        }
    }

    std::vector<int32> subtree_size(n + 1, 1);
    std::vector<int32> max_child(n + 1, 0);
    std::vector<int32> heavy_child(n + 1, 0);
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        const int32 u = *it;
        int32 best = 0;
        for (const int32 v: children[u]) {
            subtree_size[u] += subtree_size[v];
            if (subtree_size[v] > max_child[u]) {
                max_child[u] = subtree_size[v];
            }
            if (best == 0 || subtree_size[v] > subtree_size[best]) {
                best = v;
            }
        }
        heavy_child[u] = best;
    }

    std::vector<std::array<int32, LOG> > heavy_jump(n + 1);
    for (int32 u = 1; u <= n; ++u) {
        heavy_jump[u].fill(0);
        heavy_jump[u][0] = heavy_child[u];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int32 u = 1; u <= n; ++u) {
            const int32 mid = heavy_jump[u][j - 1];
            heavy_jump[u][j] = (mid == 0) ? 0 : heavy_jump[mid][j - 1];
        }
    }

    std::vector<int32> tin(n + 1, 0);
    std::vector<int32> tout(n + 1, 0);
    int32 timer = 0;
    std::vector<std::pair<int32, size_t> > stack;
    stack.reserve(n);
    stack.emplace_back(1, 0);
    while (!stack.empty()) {
        auto &top = stack.back();
        const int32 u = top.first;
        size_t &idx = top.second;
        if (idx == 0) {
            tin[u] = ++timer;
        }
        if (idx < children[u].size()) {
            const int32 v = children[u][idx++];
            stack.emplace_back(v, 0);
        } else {
            tout[u] = timer;
            stack.pop_back();
        }
    }

    out.answers.assign(n + 1, {});
    std::vector<int32> buffer;
    buffer.reserve(2);

    for (const int32 u: order) {
        const int32 total = subtree_size[u];
        const int32 limit = total / 2;
        int32 cur = u;
        for (int j = LOG - 1; j >= 0; --j) {
            const int32 nxt = heavy_jump[cur][j];
            if (nxt != 0 && subtree_size[nxt] > limit) {
                cur = nxt;
            }
        }
        buffer.clear();
        const auto check = [&](const int32 node) -> bool {
            if (node == 0) {
                return false;
            }
            int32 largest = max_child[node];
            const int32 rest = total - subtree_size[node];
            if (rest > largest) {
                largest = rest;
            }
            return largest <= limit;
        };
        if (check(cur)) {
            buffer.push_back(cur);
        }
        const int32 candidate = heavy_child[cur];
        if (candidate != 0 && subtree_size[candidate] * 2 == total && check(candidate)) {
            buffer.push_back(candidate);
        }
        std::sort(buffer.begin(), buffer.end());
        out.answers[u] = buffer;
    }

    return out;
}

void write_output(const Output &out) {
    const auto &ans = out.answers;
    const int32 n = static_cast<int32>(ans.size()) - 1;
    for (int32 i = 1; i <= n; ++i) {
        const auto &row = ans[i];
        for (size_t j = 0; j < row.size(); ++j) {
            if (j != 0) {
                std::cout << ' ';
            }
            std::cout << row[j];
        }
        std::cout << '\n';
    }
}

int main() {
    const auto input = read_input();
    const auto result = solve(input);
    write_output(result);
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
