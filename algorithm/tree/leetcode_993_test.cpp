// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_993_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_993_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_993.cpp"

namespace leetcode_993 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_993]", "[test_993]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            2, 3,
            4, TreeNode::No, TreeNode::No, TreeNode::No
    };
    static constexpr const auto x{4}, y{3};
    CHECK_FALSE(solution.isCousins(input[0], x, y));
}

TEST_CASE("test_case 3 [test_993]", "[test_993]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            2, 3,
            TreeNode::No, 4, TreeNode::No, 5
    };
    static constexpr const auto x{5}, y{4};
    CHECK(solution.isCousins(input[0], x, y));
}

TEST_CASE("test_case 2 [test_993]", "[test_993]") {
    Solution solution;
    const TreeNodeLink input{
            1,
            2, 3,
            TreeNode::No, 4, TreeNode::No
    };
    static constexpr const auto x{5}, y{4};
    CHECK_FALSE(solution.isCousins(input[0], x, y));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_993_TEST_HPP
