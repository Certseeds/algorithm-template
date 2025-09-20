// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_653.cpp"

namespace leetcode_653 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_653]", "[test_653]") {
    Solution solution;
    const TreeNodeLink input{6,
                                2, 8,
                                0, 4, 7, 9,
                                TreeNode::No, TreeNode::No, 3, 5, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No,
    };
    auto *const p = new TreeNode(2);
    auto *const q = new TreeNode(8);
    const TreeNodeLink link2{p}, link3{q};
    static constexpr const auto result{6};
    CHECK(result == solution.lowestCommonAncestor(input[0], p, q)->val);
}

TEST_CASE("test_case 2 [test_653]", "[test_653]") {
    Solution solution;
    const TreeNodeLink input{6,
                                2, 8,
                                0, 4, 7, 9,
                                TreeNode::No, TreeNode::No, 3, 5, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No,
    };
    auto *const p = new TreeNode(2);
    auto *const q = new TreeNode(4);
    const TreeNodeLink link2{p}, link3{q};
    static constexpr const auto result{2};
    CHECK(result == solution.lowestCommonAncestor(input[0], p, q)->val);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_653_TEST_HPP
