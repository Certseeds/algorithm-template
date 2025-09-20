// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_965.cpp"

namespace leetcode_965 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_965]", "[test_965]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            1, 1,
            1, 1, TreeNode::No, 2
    };
    CHECK_FALSE(solution.isUnivalTreeRec(input[0]));
    CHECK_FALSE(solution.isUnivalTreeIter(input[0]));
}

TEST_CASE("test_case 2 [test_965]", "[test_965]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            1, 1,
            1, 1, 1, 1,
            1, TreeNode::No, 1
    };
    CHECK(solution.isUnivalTreeRec(input[0]));
    CHECK(solution.isUnivalTreeIter(input[0]));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_965_TEST_HPP
