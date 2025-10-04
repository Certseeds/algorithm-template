// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <cstdint>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
#include <utility>
#include <algorithm>
#include <memory>

namespace tree {
struct Edge {
    int32_t to;
    int32_t next;
    int64_t weight;
};

class Graph {
public:
    std::vector<int32_t> head;
    std::vector<Edge> edges;
    int32_t edge_count;

    Graph(int32_t num_nodes = 0, int32_t max_edges = 0) : edge_count(0) {
        head.assign(num_nodes + 1, -1);
        edges.resize(max_edges);
    }

    void reset(int32_t num_nodes, int32_t max_edges) {
        head.assign(num_nodes + 1, -1);
        edges.clear();
        edges.resize(max_edges);
        edge_count = 0;
    }

    void add_edge(int32_t u, int32_t v, int64_t w = 0) {
        edges[edge_count].to = v;
        edges[edge_count].weight = w;
        edges[edge_count].next = head[u];
        head[u] = edge_count;
        ++edge_count;
    }

    void add_undirected_edge(int32_t u, int32_t v) {
        add_edge(u, v, 1);
        add_edge(v, u, 1);
    }
};
}
#ifndef ALGORITHM_TEST_MACRO
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("tune=native")
#else
namespace lab_07_F {
#endif

using std::cin;
using std::cout;
using std::vector;
using std::tuple;
using std::get;
using num_t = int32_t;
using answer_t = int32_t;

struct TestCase {
    int n;
    int k;
    std::shared_ptr<tree::Graph> graph; // 图在读取阶段构建
    vector<int> marked;
};

vector<TestCase> read_all() {
    int T;
    if (!(cin >> T)) return {};
    vector<TestCase> tests;
    tests.reserve(T);
    for (int tc = 0; tc < T; ++tc) {
        TestCase t;
        cin >> t.n >> t.k;
        // create graph and build edges immediately
        t.graph = std::make_shared<tree::Graph>(t.n, (t.n - 1) * 2 + 5);
        for (int i = 0; i < t.n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            t.graph->add_undirected_edge(a, b);
        }
        t.marked.resize(t.k);
        for (int i = 0; i < t.k; ++i) {
            cin >> t.marked[i];
        }
        tests.push_back(std::move(t));
    }
    return tests;
}

// BFS on tree stored as forward-star. returns distances (1-based nodes)
vector<int> bfs_distance(const tree::Graph &g, int src, int n) {
    vector<int> dist(n + 1, -1);
    std::queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        for (int ei = g.head[u]; ei != -1; ei = g.edges[ei].next) {
            const int v = g.edges[ei].to;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

vector<answer_t> cal_all(const vector<TestCase> &tests) {
    vector<answer_t> answers;
    answers.reserve(tests.size());
    for (const auto &t: tests) {
        if (t.k <= 1) {
            answers.push_back(0);
            continue;
        }
        auto &gptr = t.graph;
        // pick an arbitrary marked node
        int s = t.marked[0];
        auto dist1 = bfs_distance(*gptr, s, t.n);
        // find farthest marked from s
        int far = s;
        int bestd = -1;
        for (int m: t.marked) {
            if (dist1[m] > bestd) {
                bestd = dist1[m];
                far = m;
            }
        }
        // BFS from far
        auto dist2 = bfs_distance(*gptr, far, t.n);
        int diameter = 0;
        for (int m: t.marked) diameter = std::max(diameter, dist2[m]);
        // minimal meeting time is ceil(diameter / 2.0)
        answers.push_back((diameter + 1) / 2);
    }
    return answers;
}

void output_all(const vector<answer_t> &answers) {
    for (auto a: answers) cout << a << '\n';
}

int main() {
    const auto tests = read_all();
    const auto ans = cal_all(tests);
    output_all(ans);
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
