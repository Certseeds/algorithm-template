// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO

#include "disjoint_set.hpp"
#include "disjoint_set.cpp"

#include <vector>

namespace leetcode_684 {
using ::disjoint_set::disjoint_set;
using ::disjoint_set::getDisjointSet;
using std::vector;
#endif

class Solution {
public:
    vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
        const auto edge_sizes{edges.size()};
        const auto jset = getDisjointSet(edge_sizes);
        for (const auto &edge: edges) {
            if (jset->find(edge[0]) != jset->find(edge[1])) {
                jset->merge(edge[0], edge[1]);
            } else {
                return edge;
            }
        }
        return {};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
