// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@Tag in-traverse
//@Tag 中序遍历二叉树
//@Same 783
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_530.cpp"

namespace leetcode_530 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_530]", "[test_530]") {
    Solution solution;
    const TreeNodeLink input{4, 2, 6, 1, 3};
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == solution.getMinimumDifference(input[0]));
    }THEN("case 2") {
        CHECK(result == solution.getMinimumDifference2(input[0]));
    }
}

TEST_CASE("test_case 2 [test_530]", "[test_530]") {
    Solution solution;
    const TreeNodeLink input{1, 0, 48, TreeNode::No, TreeNode::No, 12, 49};
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == solution.getMinimumDifference(input[0]));
    }THEN("case 2") {
        CHECK(result == solution.getMinimumDifference2(input[0]));
    }
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP
