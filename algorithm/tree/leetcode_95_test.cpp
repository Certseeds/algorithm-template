// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_95.cpp"
#include <tree/treenode_link.hpp>

namespace leetcode_95 {

using std::vector;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_95]", "[test_95]") {
    Solution solution;
    const auto three = solution.generateTrees(0);
    CHECK_THAT(three, Equals<TreeNode *>({}));
    const TreeNodeLink link1{three};
}

TEST_CASE("test_case 2 [test_95]", "[test_95]") {
    Solution solution;
    const vector<vector<int32_t>> result{
            {1, TreeNode::No, 2,            TreeNode::No, 3,            TreeNode::No, TreeNode::No},
            {1, TreeNode::No, 3,            2,            TreeNode::No, TreeNode::No, TreeNode::No},
            {2, 1,            3,            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No},
            {3, 1,            TreeNode::No, TreeNode::No, 2,            TreeNode::No, TreeNode::No},
            {3, 2,            TreeNode::No, 1,            TreeNode::No, TreeNode::No, TreeNode::No},
    };
    const auto three = solution.generateTrees(3);
    static constexpr const auto length{5};
    CHECK(length == three.size());
    for (int32_t i{0}; i < length; ++i) {
        CHECK(TREE_NODE::judge_equal(three[i], result[i]));
    }
    for (const auto &node: three) {
        TreeNodeLink{node}; // just for invoke ~
    }
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP
