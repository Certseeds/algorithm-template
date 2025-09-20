// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day15

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_so_54.cpp"

namespace leetcode_so_54 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_so_54]", "[test_so_54]") {
    Solution solution;
    const TreeNodeLink input{3,
                             1, 4,
                             TreeNode::No, 2};
    static constexpr const auto k{1};
    static constexpr const auto output{4};
    CHECK(output == solution.kthLargest(input[0], k));
}

TEST_CASE("test_case 2 [test_so_54]", "[test_so_54]") {
    Solution solution;
    const TreeNodeLink input{5,
                             3, 6,
                             2, 4, TreeNode::No, TreeNode::No,
                             1};
    static constexpr const auto k{3};
    static constexpr const auto output{4};
    CHECK(output == solution.kthLargest(input[0], k));
}
}
