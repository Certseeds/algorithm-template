// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1022_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1022_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_1022.cpp"

namespace leetcode_1022 {

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

TEST_CASE("test_case 2 [test_1022]", "[test_1022]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            0, 1,
            0, 1, 0, 1,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No
    };
    static constexpr const auto result{22};
    CHECK(result == solution.sumRootToLeaf(input[0]));
}

TEST_CASE("test_case 1 [test_1022]", "[test_1022]") {
    Solution solution;
    const TreeNodeLink input{
            0,
            TreeNode::No, TreeNode::No
    };
    static constexpr const auto result{0};
    CHECK(result == solution.sumRootToLeaf(input[0]));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1022_TEST_HPP
