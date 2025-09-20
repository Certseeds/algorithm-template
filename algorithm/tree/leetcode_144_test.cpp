// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day10
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_144.cpp"

namespace leetcode_144 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_144]", "[test_144]") {
    Solution solution;
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{4, 2, 1, 3, 7};
    CHECK_THAT(result, Equals(solution.preorderTraversal(input[0])));
    CHECK_THAT(result, Equals(solution.preorderTraversalIter(input[0])));
}

TEST_CASE("test_case 2 [test_144]", "[test_144]") {
    Solution solution;
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, 5, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{4, 2, 1, 3, 7, 5};
    CHECK_THAT(result, Equals(solution.preorderTraversal(input[0])));
    CHECK_THAT(result, Equals(solution.preorderTraversalIter(input[0])));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP
