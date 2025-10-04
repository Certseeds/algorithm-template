// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

namespace tree {
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
namespace lab_08_G {
#endif
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

using i32 = int32_t;
using i64 = int64_t;
struct ProblemInput {
    i32 n;
    i32 m;
    std::shared_ptr<tree::Graph> graph;
};

using ProblemOutput = i64;

ProblemInput read_input();
ProblemOutput solve(const ProblemInput &in);
void write_output(const ProblemOutput &out);

int main() {
    const auto in = read_input();
    const auto out = solve(in);
    write_output(out);
    return 0;
}

ProblemInput read_input() {
    ProblemInput in;
    std::cin >> in.n >> in.m;
    int32_t u;
    int32_t v;
    int64_t w;
    in.graph = std::make_shared<tree::Graph>(in.n, static_cast<int32_t>((in.n - 1) * 2));
    for (i32 i = 0; i < in.n - 1; ++i) {
        std::cin >> u >> v >> w;
        in.graph->add_undirected_edge(u,v,w);
    }
    return in;
}


ProblemOutput solve(const ProblemInput &in) {
}

void write_output(const ProblemOutput &out) {
    std::cout << out << end;
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
