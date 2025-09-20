// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 动态规划入门 Day11
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_96.cpp"

namespace leetcode_96 {

using std::unordered_map;

TEST_CASE("test_case 1 [test_96]", "[test_96]") {
    Solution solution;
    static constexpr const auto input{1};
    static constexpr const auto result{1};
    CHECK(result == solution.numTrees(input));
    CHECK(result == numTreesConstexpr(input));
}

TEST_CASE("test_case 2 [test_96]", "[test_96]") {
    Solution solution;
    static constexpr const auto input{3};
    static constexpr const auto result{5};
    CHECK(result == solution.numTrees(input));
    CHECK(result == numTreesConstexpr(input));
}

TEST_CASE("test_case 3 [test_96]", "[test_96]") {
    Solution solution;
    static constexpr const auto input{19};
    static constexpr const auto result{1767263190};
    CHECK(result == solution.numTrees(input));
    CHECK(result == numTreesConstexpr(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP
