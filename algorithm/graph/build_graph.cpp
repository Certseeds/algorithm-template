// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
#include <cassert>
#include "build_graph.hpp"

namespace graph {

adjlist build_adjlist(const vector<vector<int32_t>> &input, int32_t node_num) {
    check_graph_cost_all_positive(input);
    adjlist graph(node_num, vector<link>{});
    for (const auto &item: input) {
        graph[item[0] - 1].emplace_back(item[1] - 1, item[2]);
    }
    return graph;
}

bool check_graph_cost_all_positive(const vector<vector<int32_t>> &input) {
    for (const auto &item: input) {
        assert(item.size() == 3);
        assert(item[2] >= 0);
    }
    return false;
}

}
