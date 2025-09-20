// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day10

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_145_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_145_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_145.cpp"

namespace leetcode_145 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_145]", "[test_145]") {
    Solution solution;
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{1, 3, 2, 7, 4};
    CHECK_THAT(result, Equals(solution.postorderTraversal(input[0])));
    CHECK_THAT(result, Equals(solution.postorderTraversalIter(input[0])));
}

TEST_CASE("test_case 2 [test_145]", "[test_145]") {
    Solution solution;
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, 5, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{1, 3, 2, 5, 7, 4};
    CHECK_THAT(result, Equals(solution.postorderTraversal(input[0])));
    CHECK_THAT(result, Equals(solution.postorderTraversalIter(input[0])));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_145_TEST_HPP
