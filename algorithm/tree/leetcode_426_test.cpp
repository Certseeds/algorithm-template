// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14
//@Plan 剑指OfferII-I Day15
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_426.cpp"

namespace leetcode_426 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Node = TreeNode;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_426]", "[test_426]") {
    Solution solution;
    const TreeNodeLink input{4, 2, 5, 1, 3};
    solution.treeToDoublyList(input[0]);
    CHECK(3 == input[0]->left->val);
    CHECK(5 == input[0]->right->val);
    CHECK(1 == input[1]->left->val);
    CHECK(3 == input[1]->right->val);
    CHECK(4 == input[2]->left->val);
    CHECK(1 == input[2]->right->val);
    CHECK(5 == input[3]->left->val);
    CHECK(2 == input[3]->right->val);
    CHECK(2 == input[4]->left->val);
    CHECK(4 == input[4]->right->val);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP
