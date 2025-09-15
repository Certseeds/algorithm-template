// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag disjoint_set
//@Tag 深度优先搜索
//@Tag DFS
//@Tag 广度优先搜索
//@Tag BFS

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_130.cpp"

namespace leetcode_130 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::LAND,  GRID::LAND,  GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::LAND,  GRID::WATER},
            {GRID::WATER, GRID::LAND,  GRID::WATER, GRID::WATER},
    };
    const vector<vector<char>> results{
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::LAND,  GRID::WATER, GRID::WATER},
    };
    Solution solution;
    solution.solve(edges);
    CHECK_THAT(results, Equals(edges));
}

TEST_CASE("2 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {GRID::WATER}
    };
    const vector<vector<char>> results{
            {GRID::WATER}
    };
    Solution solution;
    solution.solve(edges);
    CHECK_THAT(results, Equals(edges));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP
