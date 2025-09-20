// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos


*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP

#include <cassert>
#include <queue>
#include "build_graph.hpp"

namespace graph {
namespace dijistra {
using std::vector;
using std::priority_queue;

class graphlist final {
    vector<vector<link>> graph;
public:
    graphlist(const vector<vector<int32_t>> &input, int32_t node_num) : graph(node_num, vector<link>{}) {
        check_graph_cost_all_positive(input);
        for (const auto &item: input) {
            graph[item[0] - 1].emplace_back(item[1] - 1, item[2]);
        }
    }

    inline size_t size() const { return graph.size(); }

    inline auto at(size_t size) const { return graph.at(size); }

    [[nodiscard]] vector<int32_t> dijkstra(int32_t begin_node) const {
        begin_node -= 1;
        vector<int32_t> results(this->size(), 0x3f3f3f3f);
        results[begin_node] = 0;
        // PS: in this part,if begin_node count from 1, begin_node should -= 1
        static constexpr const auto cmp{
                [](const link &v1, const link &v2) {
                    return v1.cost > v2.cost;
                }
        };
        priority_queue<link, vector<link>, decltype(cmp)> priorityQueue{cmp};
        priorityQueue.emplace(begin_node, -1);
        while (!priorityQueue.empty()) {
            const auto head = priorityQueue.top();
            priorityQueue.pop();
            for (auto &i: this->at(head.end)) {
                const auto val = results[head.end] + i.cost;
                if (results[i.end] >= val) {
                    results[i.end] = val;
                    priorityQueue.push(i);
                }
            }
        }
        // then, in result is the distance from begin_node to i
        return results;
    }
};

}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_GRAPH_DIJISTRA_HPP
