// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

namespace tree {
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
#pragma GCC target("native")
#else
namespace lab_07_A {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

// reuse tree::Edge defined above in namespace tree

// Input / Processing / Output three-stage implementation

// using num_t alias already declared above
struct Input {
    int32_t n{0};
    int64_t target{0};
    tree::Graph graph; // constructed during read
    // Default constructor must initialize graph to avoid deleted default
    Input(): graph(0, 0) {
    }
};

using output_type = int64_t;

// Read: parse input into Input struct
static Input read_input() {
    Input in{};
    if (!(cin >> in.n >> in.target)) {
        return in;
    }
    const int32_t max_edges = std::max(1, (in.n - 1) * 2);
    in.graph = tree::Graph(in.n, max_edges);
    int32_t u, v, w;
    for (int32_t i = 0; i < in.n - 1; ++i) {
        cin >> u >> v >> w;
        in.graph.add_undirected_edge(u, v, w);
    }
    return in;
}

// Process: compute number of root-to-leaf paths whose edge-weight sum == target
static output_type solve(const Input &in) {
    const auto n = in.n;
    const auto target = in.target;
    const auto graph = in.graph;

    // iterative DFS from root=1 to compute parent and path sums using graph.head & graph.edges
    std::vector<int32_t> parent(n + 1, -1);
    std::vector<int64_t> path_sum(n + 1, 0);
    parent[1] = 0;
    std::vector<int> st;
    st.reserve(n);
    st.push_back(1);
    while (!st.empty()) {
        const auto u = st.back();
        st.pop_back();
        for (int32_t ei = graph.head[u]; ei != -1; ei = graph.edges[ei].next) {
            const auto v = graph.edges[ei].to;
            const auto w = graph.edges[ei].weight;
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            path_sum[v] = path_sum[u] + w;
            st.push_back(v);
        }
    }

    // count leaves whose path_sum equals target
    int64_t ans = 0;
    for (int32_t u = 1; u <= n; ++u) {
        bool is_leaf = true;
        for (int32_t ei = graph.head[u]; ei != -1; ei = graph.edges[ei].next) {
            const auto v = graph.edges[ei].to;
            if (v == parent[u]) continue;
            is_leaf = false;
            break;
        }
        if (is_leaf && path_sum[u] == target) ++ans;
    }
    return ans;
}

// Output: print result
static void write_output(const output_type &out) {
    cout << out << end;
}

int main() {
    // faster_streams static initializer handles ios sync and ties
    const auto input = read_input();
    // if no valid input (e.g., empty), exit
    if (input.n <= 0) { return 0; }
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
