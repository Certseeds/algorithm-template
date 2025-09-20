// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day07

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_so_26.cpp"

namespace leetcode_so_26 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_so_26]", "[test_so_26]") {
    Solution solution;
    const TreeNodeLink input{3, 4, 5, 1, 2}, input2{4, 1};
    CHECK(solution.isSubStructure(input[0], input2[0]));
}

TEST_CASE("test_case 2 [test_so_26]", "[test_so_26]") {
    Solution solution;
    const TreeNodeLink input{1, 0, 1, -4, -3}, input2{1, -4};
    CHECK_FALSE(solution.isSubStructure(input[0], input2[0]));
}

TEST_CASE("test_case 3 [test_so_26]", "[test_so_26]") {
    Solution solution;
    const TreeNodeLink input{1, 2, 3, 4}, input2{3};
    CHECK(solution.isSubStructure(input[0], input2[0]));
}

TEST_CASE("test_case 4 [test_so_26]", "[test_so_26]") {
    Solution solution;
    const TreeNodeLink input{10, 12, 6, 8, 3, 11}, input2{10, 12, 6, 8};
    CHECK(solution.isSubStructure(input[0], input2[0]));
}
}
