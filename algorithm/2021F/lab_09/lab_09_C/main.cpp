// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>

namespace graph {
struct Edge {
    int32_t to; // 边的终点
    int32_t next; // 同一个起点的下一条边的索引
    int64_t weight; // 边的权重
};

class Graph {
public:
    // 边的结构体定义
    std::vector<int32_t> head; // head[i] 存储顶点i的第一条边的索引
    std::vector<Edge> edges; // 存储所有边的数组
    int32_t edge_count; // 当前边的总数
public:
    /**
     * @brief 构造函数
     * @param num_nodes 顶点的数量 (假设顶点编号从 1 到 num_nodes)
     * @param max_edges 预估的最大边数 (对于无向图，一条无向边算两条有向边)
     */
    Graph(int32_t num_nodes, int32_t max_edges) : edge_count(0) {
        // 初始化头节点数组，大小为顶点数+1，方便1-based 索引
        // 所有顶点的初始头节点都设为-1，表示没有出边
        head.assign(num_nodes + 1, -1);
        // 预分配存储所有边的空间
        edges.resize(max_edges);
    }

    /**
     * @brief 添加一条有向边
     * @param u 起点
     * @param v 终点
     * @param w 权重
     */
    void add_edge(const int32_t u, const int32_t v, const int64_t w) {
        // 在边数组的末尾添加新边
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        // 新边的 next 指向原来以 u 为起点的第一条边
        edges[edge_count].next = head[u];
        // 更新以 u 为起点的第一条边为当前新添加的边
        head[u] = edge_count;
        // 边计数器加一
        edge_count++;
    }

    /**
     * @brief 添加一条无向边
     * @param u, v 顶点
     * @param w 权重
     */
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
namespace lab_09_C {
#endif
using std::cin;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

// We'll convert input into a Graph; store only the Graph (edges are in chain-forward-star)
struct GraphInput {
    graph::Graph g;

    GraphInput(int32_t n, int32_t m): g(n, m * 2) {
    }
};

using input_type = GraphInput;
using output_type = const char *;

static constexpr const char *STR_BAD = "Bad";
static constexpr const char *STR_GOOD = "Good";

// Read input and convert into graph::Graph + original edge list
static input_type read_input() {
    int32_t n = 0, m = 0;
    std::cin >> n >> m;
    input_type input(n, m);
    int32_t u = 0, v = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v;
        // add undirected edge to chain-forward-star Graph
        input.g.add_undirected_edge(u, v, 1);
    }
    return input;
}

// Disjoint set union (union-find)
struct DSU {
    std::vector<int32_t> parent;
    std::vector<int32_t> rank;

    explicit DSU(size_t n): parent(n + 1), rank(n + 1, 0) {
        for (size_t i = 0; i <= n; ++i) parent[i] = static_cast<int32_t>(i);
    }

    int32_t find(size_t x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(size_t a, size_t b) {
        const int32_t pa = find(a);
        const int32_t pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (
            rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
        return true;
    }
};

// Calculate whether graph has cycle: return "Bad" if cycle exists else "Good"
static output_type cal(const input_type &input) {
    const int32_t n = static_cast<int32_t>(input.g.head.size()) - 1;
    DSU dsu(static_cast<size_t>(n));
    // traverse chain-forward-star; each undirected edge appears twice (u->v and v->u)
    // process each undirected edge only once by requiring u < v
    for (int32_t u = 1; u <= n; ++u) {
        for (int32_t ei = input.g.head[static_cast<size_t>(u)]; ei != -1;
             ei = input.g.edges[static_cast<size_t>(ei)].next) {
            const int32_t v = input.g.edges[static_cast<size_t>(ei)].to;
            if (u < v) {
                if (dsu.find(u) == dsu.find(v)) return STR_BAD;
                dsu.unite(u, v);
            }
        }
    }
    return STR_GOOD;
}

static void output_result(output_type res) {
    std::cout << res << end;
}

int main() {
    const auto input_data = read_input();
    const auto output_data = cal(input_data);
    output_result(output_data);
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
