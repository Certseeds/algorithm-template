// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_654.cpp"

#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_654 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_654]", "[test_654]") {
    Solution solution;
    const vector<int32_t> input{3, 2, 1, 6, 0, 5};
    const vector<int32_t> result{6,
                                 3, 5,
                                 TreeNode::No, 2, 0, TreeNode::No,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    auto *const resultPtr = solution.constructMaximumBinaryTree(input);
    const TreeNodeLink link{resultPtr};
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}

TEST_CASE("test_case 2 [test_654]", "[test_654]") {
    Solution solution;
    const vector<int32_t> input{3, 2, 1};
    const vector<int32_t> result{3, TreeNode::No, 2, TreeNode::No, 1, TreeNode::No, TreeNode::No};
    auto *const resultPtr = solution.constructMaximumBinaryTree(input);
    const TreeNodeLink link{resultPtr};
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_654_TEST_HPP
