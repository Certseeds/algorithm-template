// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// lab_09_A: adjacency matrix output

#include <cstdint>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
namespace graph {
struct Edge {
    int32_t to;      // 边的终点
    int32_t next;    // 同一个起点的下一条边的索引
    int64_t weight;  // 边的权重
};

class Graph {
   public:
    // 边的结构体定义
    std::vector<int32_t> head;  // head[i] 存储顶点i的第一条边的索引
    std::vector<Edge> edges;    // 存储所有边的数组
    int32_t edge_count;         // 当前边的总数
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
namespace lab_09_A {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;
static constexpr const char end{'\n'};

using matrix = std::vector<std::vector<int32_t>>;
using input_type = std::vector<graph::Graph>;
using output_type = std::vector<matrix>;

// Read all test cases and build graph objects
static input_type read_all() {
    int32_t T = 0;
    if (!(std::cin >> T)) return {};
    input_type cases;
    cases.reserve(static_cast<size_t>(T));

    for (int32_t tc = 0; tc < T; ++tc) {
        int32_t n = 0, m = 0;
        std::cin >> n >> m;
        // construct graph with n nodes and reserve m edges
        graph::Graph g(n, m);
        int32_t u = 0, v = 0;
        for (int32_t i = 0; i < m; ++i) {
            std::cin >> u >> v;
            g.add_edge(u, v, 1);
        }
        cases.push_back(std::move(g));
    }
    return cases;
}

// Build adjacency matrix by traversing graph::Graph's internal edge list
static matrix build_matrix(const graph::Graph &g) {
    // Graph stores head array of size n+1 (1-based nodes)
    const size_t n = (g.head.size() > 0 ? g.head.size() - 1 : 0);
    matrix A(n, std::vector<int32_t>(n, 0));
    for (size_t u = 1; u <= n; ++u) {
        for (int32_t ei = g.head[u]; ei != -1; ei = g.edges[static_cast<size_t>(ei)].next) {
            const int32_t v = g.edges[static_cast<size_t>(ei)].to;
            if (v >= 1 && static_cast<size_t>(v) <= n) {
                A[u - 1][static_cast<size_t>(v - 1)]++;
            }
        }
    }
    return A;
}

// Compute outputs for all graphs
static output_type cal(const input_type &inputs) {
    output_type outputs;
    outputs.reserve(inputs.size());
    for (const auto &g : inputs) {
        outputs.push_back(build_matrix(g));
    }
    return outputs;
}

// Print matrices to stdout
static void output_all(const output_type &outs) {
    for (const auto &mat : outs) {
        const size_t n = mat.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (j) {
                    std::cout << ' ';
                }
                std::cout << mat[i][j];
            }
            std::cout << end;
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
