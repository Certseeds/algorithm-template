// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day06

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_so_32.cpp"

namespace leetcode_so_32 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1-1 [test_so_32]", "[test_so_32]") {
    Solution solution;
    const TreeNodeLink input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<int32_t> results{3, 9, 20, 15, 7};
    CHECK_THAT(results, Equals(solution.levelOrderFst(input[0])));
}

TEST_CASE("test_case 3-1 [test_so_32]", "[test_so_32]") {
    Solution solution;
    const TreeNodeLink input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<vector<int32_t>> results{{3},
                                          {20, 9},
                                          {15, 7}};
    CHECK_THAT(results, Equals(solution.levelOrderTrd(input[0])));
}
}
