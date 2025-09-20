// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@Sword-Offer 32-II
//@Plan 数据结构入门 Day11
//@Plan 剑指OfferII-I Day06
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_102.cpp"
#include <tree/treenode_link.hpp>

namespace leetcode_102 {

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::vector;

TEST_CASE("test_case 1 [test_102]", "[test_102]") {
    Solution solution;
    const TreeNodeLink vec{3,
                           9, 20,
                           TreeNode::No, TreeNode::No, 15, 7};
    const vector<vector<int32_t>> result{{3},
                                         {9,  20},
                                         {15, 7}};
    CHECK_THAT(solution.levelOrder(vec[0]), Equals(result));
}

TEST_CASE("test_case 2 [test_102]", "[test_102]") {
    Solution solution;
    const TreeNodeLink vec{1};
    const vector<vector<int32_t>> result{{1},};
    CHECK_THAT(solution.levelOrder(vec[0]), Equals(result));
}

TEST_CASE("test_case 3 [test_102]", "[test_102]") {
    Solution solution;
    const vector<vector<int32_t>> result{};
    CHECK_THAT(solution.levelOrder(nullptr), Equals(result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP
