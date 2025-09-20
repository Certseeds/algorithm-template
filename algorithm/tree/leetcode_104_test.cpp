// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day11
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_104.cpp"
#include <tree/treenode_link.hpp>

namespace leetcode_104 {

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

TEST_CASE("test_case 1 [test_104]", "[test_104]") {
    Solution solution;
    const TreeNodeLink input{3, 9, 20, TreeNode::No, TreeNode::No, 15, 7};
    static constexpr const auto result{3};
    CHECK(result == solution.maxDepth(input[0]));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP
