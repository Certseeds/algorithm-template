// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day10

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_94_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_94_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_94.cpp"
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_94 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_94]", "[test_94]") {
    const TreeNodeLink input{4,
                             2, 7,
                             1, 3, TreeNode::No, TreeNode::No,
                             TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{1, 2, 3, 4, 7};
    CHECK_THAT(result, Equals(leetcode_94::inorderTraversal(input[0])));
    CHECK_THAT(result, Equals(leetcode_94::inorderTraversalIter(input[0])));
}

TEST_CASE("test_case 2 [test_94]", "[test_94]") {
    const TreeNodeLink input{4,
                             2, 7,
                             1, 3, 5, TreeNode::No,
                             TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{1, 2, 3, 4, 5, 7};
    CHECK_THAT(result, Equals(leetcode_94::inorderTraversal(input[0])));
    CHECK_THAT(result, Equals(leetcode_94::inorderTraversalIter(input[0])));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_94_TEST_HPP
