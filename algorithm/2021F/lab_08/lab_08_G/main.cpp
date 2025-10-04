// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ctime>
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
    i64 total_weight;
};

using ProblemOutput = i64;

ProblemInput read_input();
ProblemOutput solve(const ProblemInput &in);
void write_output(const ProblemOutput &out);
static bool can_form_paths(const ProblemInput &in, const i64 limit);

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
    in.total_weight = 0;
    for (i32 i = 0; i < in.n - 1; ++i) {
        std::cin >> u >> v >> w;
        in.graph->add_undirected_edge(u, v, w);
        in.total_weight += w;
    }
    return in;
}


ProblemOutput solve(const ProblemInput &in) {
    i64 left = 0;
    i64 right = in.total_weight;
    i64 answer = 0;
    while (left <= right) {
        const auto mid = (left + right) >> 1;
        if (can_form_paths(in, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

void write_output(const ProblemOutput &out) {
    std::cout << out << end;
}

static bool can_form_paths(const ProblemInput &in, const i64 limit) {
    if (limit <= 0) return true;
    const auto &graph = *in.graph;
    const auto n = in.n;
    std::vector<int32_t> parent(static_cast<size_t>(n + 1), 0);
    std::vector<int32_t> order;
    order.reserve(static_cast<size_t>(n));
    std::vector<int32_t> stack;
    stack.reserve(static_cast<size_t>(n));
    stack.push_back(1);
    parent[1] = 0;
    while (!stack.empty()) {
        const auto u = stack.back();
        stack.pop_back();
        order.push_back(u);
        for (auto ei = graph.head[static_cast<size_t>(u)]; ei != -1; ei = graph.edges[static_cast<size_t>(ei)].next) {
            const auto &edge = graph.edges[static_cast<size_t>(ei)];
            if (edge.to == parent[static_cast<size_t>(u)]) continue;
            parent[static_cast<size_t>(edge.to)] = u;
            stack.push_back(edge.to);
        }
    }
    std::vector<i64> dp(static_cast<size_t>(n + 1), 0);
    int32_t formed = 0;
    std::vector<i64> lengths;
    std::vector<bool> used;

    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        const auto u = *it;
        lengths.clear();
        for (auto ei = graph.head[static_cast<size_t>(u)]; ei != -1; ei = graph.edges[static_cast<size_t>(ei)].next) {
            const auto &edge = graph.edges[static_cast<size_t>(ei)];
            if (parent[static_cast<size_t>(u)] == edge.to) continue;
            lengths.push_back(dp[static_cast<size_t>(edge.to)] + edge.weight);
        }

        std::sort(lengths.rbegin(), lengths.rend());

        used.assign(lengths.size(), false);
        int32_t l = 0;
        int32_t r = static_cast<int32_t>(lengths.size()) - 1;

        while (l < r) {
            if (used[l]) {
                l++;
                continue;
            }
            while (l < r && (used[r] || lengths[l] + lengths[r] < limit)) {
                r--;
            }
            if (l < r) {
                formed++;
                used[l] = used[r] = true;
                l++;
                r--;
            }
        }

        i64 carry = 0;
        for(size_t i = 0; i < lengths.size(); ++i) {
            if (!used[i]) {
                if (lengths[i] >= limit) {
                    formed++;
                    used[i] = true;
                } else {
                    carry = std::max(carry, lengths[i]);
                }
            }
        }
        dp[static_cast<size_t>(u)] = carry;
    }
    return formed >= in.m;
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
