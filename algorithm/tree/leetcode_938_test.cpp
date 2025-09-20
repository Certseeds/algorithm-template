// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_938.cpp"

namespace leetcode_938 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_938]", "[test_938]") {
    Solution solution;
    const TreeNodeLink input{
            10,
            5, 15,
            3, 7, TreeNode::No, 18
    };
    static constexpr const auto low{7}, high{15};
    static constexpr const auto result{32};
    CHECK(result == solution.rangeSumBST(input[0], low, high));
}

TEST_CASE("test_case 2 [test_938]", "[test_938]") {
    Solution solution;
    const TreeNodeLink input{
            10,
            5, 15,
            3, 7, 13, 18,
            1, TreeNode::No, 6
    };
    static constexpr const auto low{6}, high{10};
    static constexpr const auto result{23};
    CHECK(result == solution.rangeSumBST(input[0], low, high));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP
