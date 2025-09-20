// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_617.cpp"

namespace leetcode_617 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_617]", "[test_617]") {
    Solution solution;
    const TreeNodeLink input1{1, 3, 2, 5, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                              TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    const TreeNodeLink input2{2, 1, 3, TreeNode::No, 4, TreeNode::No, 7, TreeNode::No, TreeNode::No, TreeNode::No,
                              TreeNode::No, TreeNode::No, TreeNode::No};
    const vector<int32_t> result{3, 4, 5, 5, 4, TreeNode::No, 7, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                              TreeNode::No, TreeNode::No};
    const auto resultPtr = solution.mergeTrees(input1[0], input2[0]);
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_617_TEST_HPP
