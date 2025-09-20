// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_1261.cpp"

namespace leetcode_1261 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

constexpr const auto junk{-1};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1261]", "[test_1261]") {
    const TreeNodeLink input{
            junk,
            TreeNode::No, junk,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    FindElements tree(input[0]);
    CHECK(tree.find(0));
    CHECK_FALSE(tree.find(1));
    CHECK(tree.find(2));
    CHECK_FALSE(tree.find(3));
    CHECK_FALSE(tree.find(4));
}

TEST_CASE("test_case 2 [test_1261]", "[test_1261]") {
    const TreeNodeLink input{
            junk,
            junk, junk,
            junk, junk, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
            TreeNode::No,
    };
    FindElements tree(input[0]);
    CHECK(tree.find(0));
    CHECK(tree.find(1));
    CHECK(tree.find(2));
    CHECK(tree.find(3));
    CHECK(tree.find(4));
    CHECK_FALSE(tree.find(5));
    CHECK_FALSE(tree.find(6));
    CHECK_FALSE(tree.find(7));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1261_TEST_HPP
