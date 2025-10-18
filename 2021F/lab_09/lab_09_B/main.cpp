// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <tuple>

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
namespace lab_09_B {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;
static constexpr const char end{'\n'};

// Input: for each test case we will store the knight graph and the start/end
struct TestCase {
    int32_t s;
    int32_t t;
};

using input_type = std::vector<TestCase>;
using output_type = std::vector<int32_t>;

// Convert chess notation like "f6" to 1-based index (1..64)
static int32_t chess_to_index(const std::string &pos) {
    if (pos.size() < 2) return -1;
    const char file = pos[0];
    const char rank = pos[1];
    const int32_t x = file - 'a'; // 0..7
    const int32_t y = rank - '1'; // 0..7
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return -1;
    return y * 8 + x + 1; // 1-based
}

// Build knight moves graph for 8x8 board using graph::Graph (1-based nodes)
static graph::Graph build_knight_graph() {
    constexpr int32_t n = 64;
    constexpr int32_t max_edges = 64 * 8; // upper bound
    graph::Graph g(n, max_edges);
    constexpr int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    constexpr int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            const int u = r * 8 + c + 1;
            for (int k = 0; k < 8; ++k) {
                const int nr = r + dy[k];
                const int nc = c + dx[k];
                if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                    const int v = nr * 8 + nc + 1;
                    g.add_edge(u, v, 1);
                }
            }
        }
    }
    return g;
}

static const auto static_graph = build_knight_graph();
// Read all test cases
static input_type read_all() {
    int32_t T = 0;
    if (!(std::cin >> T)) return {};
    input_type inputs;
    inputs.reserve(static_cast<size_t>(T));
    for (int32_t i = 0; i < T; ++i) {
        std::string a, b;
        std::cin >> a >> b;
        const int32_t ai = chess_to_index(a);
        const int32_t bi = chess_to_index(b);
        // build a knight graph per test case (as requested)
        inputs.push_back(TestCase{ai, bi});
    }
    return inputs;
}

// BFS on graph::Graph to compute minimum steps from s to t
static int32_t bfs_shortest(int32_t s, int32_t t) {
    if (s == t) return 0;
    const int32_t n = static_cast<int32_t>(static_graph.head.size()) - 1;
    std::vector<int32_t> dist(static_cast<size_t>(n + 1), -1);
    std::queue<int32_t> q;
    dist[static_cast<size_t>(s)] = 0;
    q.push(s);
    while (!q.empty()) {
        const int32_t u = q.front();
        q.pop();
        for (int32_t ei = static_graph.head[static_cast<size_t>(u)];
             ei != -1;
             ei = static_graph.edges[static_cast<size_t>(ei)].next) {
            const int32_t v = static_graph.edges[static_cast<size_t>(ei)].to;
            if (dist[static_cast<size_t>(v)] == -1) {
                dist[static_cast<size_t>(v)] = dist[static_cast<size_t>(u)] + 1;
                if (v == t) return dist[static_cast<size_t>(v)];
                q.push(v);
            }
        }
    }
    return -1;
}

// Compute outputs for all input pairs
static output_type cal(const input_type &inputs) {
    output_type outputs;
    outputs.reserve(inputs.size());
    for (const auto &gt: inputs) {
        outputs.push_back(bfs_shortest(gt.s, gt.t));
    }
    return outputs;
}

// Print results
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
