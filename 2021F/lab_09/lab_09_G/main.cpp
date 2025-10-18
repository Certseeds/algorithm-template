// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

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
namespace lab_09_G {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;
static constexpr const char end{'\n'};

static constexpr int64_t MOD_INF = std::numeric_limits<int64_t>::max() / 4;

struct TestCase {
    graph::Graph g;
    std::vector<int64_t> w;

    TestCase(int32_t n = 0, int32_t m = 0) : g(n, std::max<int32_t>(1, m * 2)), w(static_cast<size_t>(n) + 1, 0) {
    }
};

struct Answer {
    bool possible{true};
    int64_t min_removed{0};
    int64_t max_removed{0};
};

static TestCase read_all();

static Answer cal(const TestCase &tc);

static void output_all(const Answer &ans);

int main() {
    const auto tc = read_all();
    const auto ans = cal(tc);
    output_all(ans);
    return 0;
}

static TestCase read_all() {
    int32_t n = 0, m = 0;
    if (!(std::cin >> n >> m)) {
        return {};
    }
    TestCase tc(n, m);
    for (int32_t i = 1; i <= n; ++i) {
        int64_t wi = 0;
        std::cin >> wi;
        tc.w[static_cast<size_t>(i)] = wi;
    }
    int32_t u = 0, v = 0;
    int64_t c = 0;
    for (int32_t i = 0; i < m; ++i) {
        std::cin >> u >> v >> c;
        tc.g.add_undirected_edge(u, v, c);
    }
    return tc;
}

static Answer cal(const TestCase &tc) {
    const size_t n = tc.w.size() > 0 ? tc.w.size() - 1 : 0;
    Answer ans;
    if (n == 0) {
        ans.possible = true;
        ans.min_removed = 0;
        ans.max_removed = 0;
        return ans;
    }

    std::vector<int8_t> visited(n + 1, 0);
    std::vector<int32_t> parity(n + 1, 0);
    std::vector<int64_t> bias(n + 1, 0);

    int64_t total_w = 0;
    for (size_t i = 1; i <= n; ++i) {
        total_w += tc.w[i];
    }

    int64_t total_min_sum_x = 0;
    int64_t total_max_sum_x = 0;

    std::vector<int32_t> queue;
    queue.reserve(n);
    std::vector<int32_t> component;
    component.reserve(64);

    for (int32_t start = 1; static_cast<size_t>(start) <= n; ++start) {
        if (visited[static_cast<size_t>(start)]) continue;

        queue.clear();
        component.clear();

        visited[static_cast<size_t>(start)] = 1;
        parity[static_cast<size_t>(start)] = 1;
        bias[static_cast<size_t>(start)] = 0;
        queue.push_back(start);
        component.push_back(start);

        bool has_fixed_t = false;
        int64_t fixed_t = 0;

        size_t qhead = 0;
        while (qhead < queue.size()) {
            const int32_t u = queue[qhead++];
            for (int32_t ei = tc.g.head[static_cast<size_t>(u)]; ei != -1;
                 ei = tc.g.edges[static_cast<size_t>(ei)].next) {
                const int32_t v = tc.g.edges[static_cast<size_t>(ei)].to;
                const int64_t c = tc.g.edges[static_cast<size_t>(ei)].weight;
                const int32_t new_parity = -parity[static_cast<size_t>(u)];
                const int64_t new_bias = c - bias[static_cast<size_t>(u)];
                if (!visited[static_cast<size_t>(v)]) {
                    visited[static_cast<size_t>(v)] = 1;
                    parity[static_cast<size_t>(v)] = new_parity;
                    bias[static_cast<size_t>(v)] = new_bias;
                    queue.push_back(v);
                    component.push_back(v);
                } else {
                    if (parity[static_cast<size_t>(v)] == new_parity) {
                        if (bias[static_cast<size_t>(v)] != new_bias) {
                            ans.possible = false;
                            return ans;
                        }
                    } else {
                        const int64_t numerator = new_bias - bias[static_cast<size_t>(v)];
                        if ((numerator & 1LL) != 0) {
                            ans.possible = false;
                            return ans;
                        }
                        const int32_t denom = parity[static_cast<size_t>(v)] - new_parity; // ±2
                        const int64_t cand_t = numerator / denom;
                        if (!has_fixed_t) {
                            fixed_t = cand_t;
                            has_fixed_t = true;
                        } else if (fixed_t != cand_t) {
                            ans.possible = false;
                            return ans;
                        }
                    }
                }
            }
        }

        int64_t low = -MOD_INF;
        int64_t high = MOD_INF;
        int64_t sum_alpha = 0;
        int64_t sum_beta = 0;

        for (const int32_t node: component) {
            const int32_t alpha = parity[static_cast<size_t>(node)];
            const int64_t beta = bias[static_cast<size_t>(node)];
            const int64_t w = tc.w[static_cast<size_t>(node)];

            if (alpha == 1) {
                low = std::max(low, -beta);
                high = std::min(high, w - beta);
            } else {
                low = std::max(low, beta - w);
                high = std::min(high, beta);
            }
            if (low > high) {
                ans.possible = false;
                return ans;
            }
            sum_alpha += static_cast<int64_t>(alpha);
            sum_beta += beta;
        }

        if (has_fixed_t) {
            if (fixed_t < low || fixed_t > high) {
                ans.possible = false;
                return ans;
            }
            const int64_t sum_x = sum_alpha * fixed_t + sum_beta;
            total_min_sum_x += sum_x;
            total_max_sum_x += sum_x;
        } else {
            const int64_t sum_when_low = sum_alpha * low + sum_beta;
            const int64_t sum_when_high = sum_alpha * high + sum_beta;
            int64_t comp_min_sum = 0;
            int64_t comp_max_sum = 0;
            if (sum_alpha > 0) {
                comp_min_sum = sum_when_low;
                comp_max_sum = sum_when_high;
            } else if (sum_alpha < 0) {
                comp_min_sum = sum_when_high;
                comp_max_sum = sum_when_low;
            } else {
                comp_min_sum = sum_beta;
                comp_max_sum = sum_beta;
            }
            total_min_sum_x += comp_min_sum;
            total_max_sum_x += comp_max_sum;
        }
    }

    ans.min_removed = total_w - total_max_sum_x;
    ans.max_removed = total_w - total_min_sum_x;
    ans.possible = true;
    return ans;
}

static void output_all(const Answer &ans) {
    if (!ans.possible) {
        std::cout << "impossible" << end;
    } else {
        std::cout << ans.min_removed << ' ' << ans.max_removed << end;
    }
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
