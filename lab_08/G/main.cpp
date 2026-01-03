// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2020-2026 Certseeds
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_08_G {
#endif

using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'};

using num_t = int32_t;

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

using input_type = tuple<int, int, Graph>;
using output_type = num_t;

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    int n, m;
    cin >> n >> m;
    Graph adj(n, (n - 1) * 2);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.add_undirected_edge(u, v, w);
    }
    return std::make_tuple(n, m, adj);
}

namespace {
struct Solver {
    int n, m;
    const Graph &adj;
    int cnt;
    int mid;

    Solver(const int n, const int m, const Graph &adj) : n(n), m(m), adj(adj), cnt(0), mid(0) {
    }

    int dfs(const int u, const int p) {
        vector<int> vec;
        for (int i = adj.head[u]; i != -1; i = adj.edges[i].next) {
            const auto &e = adj.edges[i];
            if (e.to == p) {
                continue;
            }
            const int len = dfs(e.to, u) + e.weight;
            if (len >= mid) {
                cnt++;
            } else {
                vec.push_back(len);
            }
        }
        sort(vec.begin(), vec.end());

        auto calc = [&](int skip) {
            int c = 0;
            int l = 0, r = (int) vec.size() - 1;
            while (l < r) {
                if (l == skip) {
                    l++;
                    continue;
                }
                if (r == skip) {
                    r--;
                    continue;
                }
                if (vec[l] + vec[r] >= mid) {
                    c++;
                    l++;
                    r--;
                } else {
                    l++;
                }
            }
            return c;
        };

        const int base = calc(-1);
        cnt += base;

        int l = 0, r = (int) vec.size() - 1;
        int ans_idx = -1;
        while (l <= r) {
            const int mid_idx = l + (r - l) / 2;
            if (calc(mid_idx) == base) {
                ans_idx = mid_idx;
                l = mid_idx + 1;
            } else {
                r = mid_idx - 1;
            }
        }

        if (ans_idx != -1) return vec[ans_idx];
        return 0;
    }

    bool check(int k) {
        mid = k;
        cnt = 0;
        dfs(1, 0);
        return cnt >= m;
    }
};
}

output_type cal(input_type data) {
    const int n = std::get<0>(data);
    const int m = std::get<1>(data);
    const Graph &adj = std::get<2>(data);
    Solver solver(n, m, adj);
    int l = 1, r = 500000000;
    int ans = 0;
    while (l <= r) {
        const int mid = l + (r - l) / 2;
        if (solver.check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void output(const output_type &data) {
    cout << data << end;
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
