// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Sword-Offer 28
//@Plan 数据结构入门 Day11
//@Plan 剑指OfferII-I Day07
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_101.cpp"
#include <tree/treenode_link.hpp>

namespace leetcode_101 {

using std::vector;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

TEST_CASE("test_case 1 [test_101]", "[test_101]") {
    Solution solution;
    const TreeNodeLink vec{1,
                           2, 2,
                           3, 4, 4, 3};
    CHECK(solution.isSymmetric(vec[0]));
}

TEST_CASE("test_case 2 [test_101]", "[test_101]") {
    Solution solution;
    const TreeNodeLink vec{1,
                           2, 2,
                           TreeNode::No, 3, TreeNode::No, 3};
    CHECK_FALSE(solution.isSymmetric(vec[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP
