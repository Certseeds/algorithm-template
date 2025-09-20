// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1008_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1008_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_1008.cpp"

namespace leetcode_1008 {

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::vector;

TEST_CASE("test_case 4 [test_1008]", "[test_1008]") {
    Solution solution;
    const vector<int32_t> input{1, 2, 3};
    const vector<int32_t> result{
            1,
            TreeNode::No, 2,
            TreeNode::No, 3,
            TreeNode::No, TreeNode::No
    };
    TreeNode *const pointer = solution.bstFromPreorder(input);
    const TreeNodeLink treeNodeLink{pointer};
    CHECK(TREE_NODE::judge_equal(pointer, result));
}

TEST_CASE("test_case 1 [test_1008]", "[test_1008]") {
    Solution solution;
    const vector<int32_t> input{8, 5, 1, 7, 10, 12};
    const vector<int32_t> result{
            8,
            5, 10,
            1, 7, TreeNode::No, 12,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No
    };
    TreeNode *const pointer = solution.bstFromPreorder(input);
    const TreeNodeLink treeNodeLink{pointer};
    CHECK(TREE_NODE::judge_equal(pointer, result));
}

TEST_CASE("test_case 2 [test_1008]", "[test_1008]") {
    Solution solution;
    const vector<int32_t> input{1};
    const vector<int32_t> result{
            1,
            TreeNode::No, TreeNode::No
    };
    TreeNode *const pointer = solution.bstFromPreorder(input);
    const TreeNodeLink treeNodeLink{pointer};
    CHECK(TREE_NODE::judge_equal(pointer, result));
}

TEST_CASE("test_case 3 [test_1008]", "[test_1008]") {
    Solution solution;
    const vector<int32_t> input{4, 2};
    const vector<int32_t> result{
            4,
            2, TreeNode::No,
            TreeNode::No, TreeNode::No
    };
    TreeNode *const pointer = solution.bstFromPreorder(input);
    const TreeNodeLink treeNodeLink{pointer};
    CHECK(TREE_NODE::judge_equal(pointer, result));
}

TEST_CASE("test_case 5 [test_1008]", "[test_1008]") {
    Solution solution;
    const vector<int32_t> input{15, 13, 12, 18};
    const vector<int32_t> result{
            15,
            13, 18,
            12, TreeNode::No, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No
    };
    TreeNode *const pointer = solution.bstFromPreorder(input);
    const TreeNodeLink treeNodeLink{pointer};
    CHECK(TREE_NODE::judge_equal(pointer, result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1008_TEST_HPP
