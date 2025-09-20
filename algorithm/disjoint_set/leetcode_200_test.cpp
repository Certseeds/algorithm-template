// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_200.cpp"

namespace leetcode_200 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("1 [test_200]", "[test_200]") {
    vector<vector<char>> edges{
            {GRID::LAND,  GRID::LAND,  GRID::LAND,  GRID::LAND,  GRID::WATER},
            {GRID::LAND,  GRID::LAND,  GRID::WATER, GRID::LAND,  GRID::WATER},
            {GRID::LAND,  GRID::LAND,  GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER, GRID::WATER},
    };
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.numIslands(edges));

}

TEST_CASE("2 [test_200]", "[test_200]") {
    const vector<vector<char>> edges{
            {GRID::LAND,  GRID::LAND,  GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::LAND,  GRID::LAND,  GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::LAND,  GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::WATER, GRID::LAND,  GRID::LAND}
    };
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.numIslands(edges));
}

TEST_CASE("3 [test_200]", "[test_200]") {
    const vector<vector<char>> edges{
            {GRID::LAND,  GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::WATER},
            {GRID::WATER, GRID::WATER, GRID::LAND}
    };
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.numIslands(edges));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP
