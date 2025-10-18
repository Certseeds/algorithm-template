// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>

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
namespace lab_09_F {
#endif
using std::int32_t;
using std::int64_t;
using std::size_t;
using std::vector;
static constexpr const char end{'\n'};

static constexpr int64_t MOD = 1000000007LL;

// Test case container: keep Graph, arrays a and b, and indegree for topo
struct TestCase {
    graph::Graph g;
    std::vector<int64_t> a;      // 1-based
    std::vector<int64_t> b;      // 1-based
    std::vector<int32_t> indeg;  // 1-based
    TestCase(int32_t n = 0, int32_t m = 0) : g(n, m), a(n + 1), b(n + 1), indeg(n + 1, 0) {}
};

using input_type = std::vector<TestCase>;
using output_type = std::vector<int64_t>;

// Read all test cases
static input_type read_all() {
    int32_t T = 0;
    if (!(std::cin >> T)) return {};
    input_type cases;
    cases.reserve(static_cast<size_t>(T));
    for (int32_t tc = 0; tc < T; ++tc) {
        int32_t n = 0, m = 0;
        std::cin >> n >> m;
        TestCase tcse(n, m);
        for (int32_t i = 1; i <= n; ++i) {
            int64_t ai = 0, bi = 0;
            std::cin >> ai >> bi;
            tcse.a[i] = ((ai % MOD) + MOD) % MOD;
            tcse.b[i] = ((bi % MOD) + MOD) % MOD;
        }
        for (int32_t i = 0; i < m; ++i) {
            int32_t u = 0, v = 0;
            std::cin >> u >> v;
            tcse.g.add_edge(u, v, 0);
            // record indegree
            if (v >= 1 && static_cast<size_t>(v) < tcse.indeg.size()) tcse.indeg[v]++;
        }
        cases.push_back(std::move(tcse));
    }
    return cases;
}

// Solve one test case using topo DP: g_u = sum_{u->v}(b_v + g_v)
static int64_t solve_one(TestCase const &tc) {
    const size_t n = tc.g.head.size() > 0 ? tc.g.head.size() - 1 : 0;
    // copy indegree because we will mutate it
    std::vector<int32_t> indeg = tc.indeg;
    std::vector<int32_t> topo;
    topo.reserve(n);
    std::vector<int32_t> q;
    q.reserve(n);
    // push nodes with indeg==0
    for (size_t i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push_back(static_cast<int32_t>(i));
    // simple queue via index
    size_t qhead = 0;
    while (qhead < q.size()) {
        int32_t u = q[qhead++];
        topo.push_back(u);
        for (int32_t ei = tc.g.head[u]; ei != -1; ei = tc.g.edges[static_cast<size_t>(ei)].next) {
            int32_t v = tc.g.edges[static_cast<size_t>(ei)].to;
            if (--indeg[static_cast<size_t>(v)] == 0) q.push_back(v);
        }
    }
    // If topo.size() != n, graph wasn't a DAG, but problem guarantees DAG. We'll proceed anyway.
    std::vector<int64_t> gval(n + 1, 0);
    // process in reverse topo
    for (auto it = topo.rbegin(); it != topo.rend(); ++it) {
        const int32_t u = *it;
        int64_t sum = 0;
        for (int32_t ei = tc.g.head[u]; ei != -1; ei = tc.g.edges[static_cast<size_t>(ei)].next) {
            const int32_t v = tc.g.edges[static_cast<size_t>(ei)].to;
            sum += tc.b[static_cast<size_t>(v)];
            if (sum >= MOD) sum -= MOD;
            sum += gval[static_cast<size_t>(v)];
            if (sum >= MOD) sum -= MOD;
        }
        gval[static_cast<size_t>(u)] = sum % MOD;
    }
    int64_t ans = 0;
    for (size_t i = 1; i <= n; ++i) {
        ans = (ans + (tc.a[i] * gval[i]) % MOD) % MOD;
    }
    return ans;
}

static output_type cal(const input_type &cases) {
    output_type outs;
    outs.reserve(cases.size());
    for (const auto &tc : cases) {
        outs.push_back(solve_one(tc));
    }
    return outs;
}

static void output_all(const output_type &outs) {
    for (const auto &v : outs) {
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
