// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos


*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DFS_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DFS_HPP

#include "build_graph.hpp"
#include <queue>

namespace graph {
namespace dfs {
using std::vector;
using std::queue;
enum class STATE {
    WHITE,
    GRAY,
    BLACK,
};

class graphlist final {
    struct node {
        const size_t order;
        STATE state{STATE::WHITE};
        node *prev{nullptr};
        size_t gray_time, blacktime;
        size_t distance{NO_V};

        vector<link> links;

        explicit node(size_t node) : order(node) {}

        node(const node &node_) = default;
    };

    vector<node> graph;
    using invoke = std::function<void(const node &)>;
public:
    static constexpr const size_t NO_V{0x3f3f3f3f};

    graphlist(const vector<vector<int32_t>> &input, int32_t node_num) {
        check_graph_cost_all_positive(input);
        graph.reserve(node_num);
        for (int32_t i{0}; i < node_num; ++i) {
            graph.emplace_back(i);
        }
        for (const auto &item: input) {
            graph[item[0] - 1].links.emplace_back(item[1] - 1, item[2]);
        }
    }

    inline size_t size() const { return graph.size(); }

    inline auto at(size_t size) const { return graph.at(size).links; }

    void dfs() const {
        auto nodes = graph;
        size_t time = 0;
        for (const auto &node: nodes) {
            if (node.state == STATE::WHITE) {
                dfs(nodes, node.order, time);
            }
        }
    }

    static size_t dfs(vector<node> &nodes, size_t begin, size_t time) {
        static const invoke func = [](const node &n) {
            //std::cout << n.order << " " << ((n.prev == nullptr) ? 0 : n.prev->order) << std::endl;
        };
        func(nodes[begin]);
        nodes[begin].distance = 0;
        nodes[begin].state = STATE::GRAY;
        nodes[begin].gray_time = (++time);
        for (const auto &link: nodes[begin].links) {
            if (nodes[link.end].state == STATE::WHITE) {
                nodes[link.end].prev = &nodes[begin];
                time = dfs(nodes, link.end, time);
            }
        }
        nodes[begin].state = STATE::BLACK;
        nodes[begin].blacktime = (++time);
        return time;
    }
};

}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DFS_HPP
