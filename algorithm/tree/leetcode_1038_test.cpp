// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Tag 更大和数
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1038_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1038_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_1038.cpp"

namespace leetcode_1038 {

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::vector;

TEST_CASE("test_case 1 [test_1038]", "[test_1038]") {
    Solution solution;
    const TreeNodeLink input{
            4,
            1, 6,
            0, 2, 5, 7,
            TreeNode::No, TreeNode::No, TreeNode::No, 3, TreeNode::No, TreeNode::No, TreeNode::No, 8,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No
    };
    const vector<int32_t> result{
            30,
            36, 21,
            36, 35, 26, 15,
            TreeNode::No, TreeNode::No, TreeNode::No, 33, TreeNode::No, TreeNode::No, TreeNode::No, 8,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No
    };
    const auto output = solution.bstToGst(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}

TEST_CASE("test_case 2 [test_1038]", "[test_1038]") {
    Solution solution;
    const TreeNodeLink input{
            0,
            TreeNode::No, 1, TreeNode::No, TreeNode::No
    };
    const vector<int32_t> result{
            1,
            TreeNode::No, 1, TreeNode::No, TreeNode::No
    };
    const auto output = solution.bstToGst(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1038_TEST_HPP
