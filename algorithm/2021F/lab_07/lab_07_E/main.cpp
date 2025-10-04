// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <tuple>
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <limits>
#include <unordered_map>

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
#pragma GCC target("tune=native")
#else
namespace lab_07_E {
#endif
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'};

struct Input {
    int n{0};
    std::shared_ptr<tree::Graph> graph;
    std::vector<int> order; // desired leaf visit order
};

using output_type = std::vector<int>;

static Input read_input() {
    Input in{};
    if (!(cin >> in.n)) return in;
    const int max_edges = std::max(1, (in.n - 1) * 2);
    in.graph = std::make_shared<tree::Graph>(in.n, max_edges);
    for (int i = 0; i < in.n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        in.graph->add_undirected_edge(u, v, 0);
    }
    // read remaining integers as the leaf order
    int x;
    while (cin >> x) in.order.push_back(x);
    return in;
}

// compute subtree leaf counts and min/max positions; return false if invalid
static bool compute_intervals(int u, const std::vector<std::vector<int> > &children,
                              const std::vector<int> &pos, std::vector<int> &leaf_cnt,
                              std::vector<int> &minPos, std::vector<int> &maxPos) {
    const int INF = std::numeric_limits<int>::max() / 4;
    if (children[u].empty()) {
        // leaf
        leaf_cnt[u] = 1;
        minPos[u] = maxPos[u] = pos[u];
        return pos[u] != -1; // must appear in sequence
    }
    int cnt = 0;
    int mn = INF, mx = -INF;
    for (const int v: children[u]) {
        if (!compute_intervals(v, children, pos, leaf_cnt, minPos, maxPos)) {
            return false;
        }
        cnt += leaf_cnt[v];
        mn = std::min(mn, minPos[v]);
        mx = std::max(mx, maxPos[v]);
    }
    leaf_cnt[u] = cnt;
    minPos[u] = mn;
    maxPos[u] = mx;
    // check contiguous block property
    if (mx - mn + 1 != cnt) {
        return false;
    }
    return true;
}

static output_type solve(const Input &in) {
    const int n = in.n;
    const auto &graph = *in.graph;
    output_type empty;
    if (n <= 0) return empty;

    // build rooted tree at 1
    std::vector<int> parent(n + 1, -1);
    std::vector<std::vector<int> > children(n + 1);
    parent[1] = 0;
    std::vector<int> st;
    st.reserve(n);
    st.push_back(1);
    while (!st.empty()) {
        const int u = st.back();
        st.pop_back();
        for (int ei = graph.head[u]; ei != -1; ei = graph.edges[ei].next) {
            int v = graph.edges[ei].to;
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            children[u].push_back(v);
            st.push_back(v);
        }
    }

    // identify leaves
    std::vector<int> leaves;
    for (int u = 1; u <= n; ++u) {
        if (children[u].empty()) {
            leaves.push_back(u);
        }
    }

    // check order size matches leaves
    if ((int) in.order.size() != (int) leaves.size()) return {-1};

    // map leaf -> position
    std::vector<int> pos(n + 1, -1);
    for (int i = 0; i < (int) in.order.size(); ++i) pos[in.order[i]] = i;
    // ensure order contains exactly all leaves
    for (const int leaf: leaves) {
        if (pos[leaf] == -1) {
            return {-1};
        }
    }

    // compute intervals
    std::vector<int> leaf_cnt(n + 1, 0), minPos(n + 1, 0), maxPos(n + 1, 0);
    // use recursion from root; if fails, impossible
    if (!compute_intervals(1, children, pos, leaf_cnt, minPos, maxPos)) {
        return {-1};
    }

    // reorder children by minPos
    for (int u = 1; u <= n; ++u) {
        std::sort(children[u].begin(), children[u].end(), [&](const int a, const int b) {
            return minPos[a] < minPos[b];
        });
    }

    // build Euler tour (iterative to avoid recursion/std::function)
    std::vector<int> tour;
    tour.reserve(2 * n - 1);
    std::vector<std::pair<int, int> > stack; // node, next child idx
    stack.emplace_back(1, 0);
    while (!stack.empty()) {
        auto &top = stack.back();
        int u = top.first;
        int &idx = top.second;
        if (idx == 0) {
            tour.push_back(u);
        }
        if (idx < (int) children[u].size()) {
            int v = children[u][idx++];
            stack.emplace_back(v, 0);
        } else {
            stack.pop_back();
            if (!stack.empty()) tour.push_back(stack.back().first);
        }
    }
    if ((int) tour.size() != 2 * n - 1) {
        return {-1};
    }
    return tour;
}

static void write_output(const output_type &outv) {
    if (outv.size() == 1 && outv[0] == -1) {
        cout << -1 << end;
        return;
    }
    for (size_t i = 0; i < outv.size(); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << outv[i];
    }
    cout << end;
}

int main() {
    const auto in = read_input();
    if (in.n <= 0) {
        return 0;
    }
    const auto outv = solve(in);
    write_output(outv);
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
