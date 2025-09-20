// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Sword-Offer 27
//@Plan 数据结构入门 Day12
//@Plan 剑指OfferII-I Day07
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_226.cpp"

namespace leetcode_226 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_226]", "[test_226]") {
    Solution solution;
    const TreeNodeLink input{4, 2, 7, 1, 3, 6, 9};
    solution.invertTree(input[0]);
    const vector<int32_t> result{4, 7, 2, 9, 6, 3, 1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    CHECK(TREE_NODE::judge_equal(input[0], result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP
