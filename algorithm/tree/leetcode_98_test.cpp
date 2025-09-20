// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_98_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_98_TEST_HPP

#include <catch_main.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_98.cpp"

namespace leetcode_98 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_98]", "[test_98]") {
    Solution solution;
    const TreeNodeLink vec{2, 1, 3};
    CHECK(solution.isValidBST(vec[0]));
}

TEST_CASE("test_case 2 [test_98]", "[test_98]") {
    Solution solution;
    const TreeNodeLink vec{5, 1, 4, TreeNode::No, TreeNode::No, 3, 6};
    CHECK_FALSE(solution.isValidBST(vec[0]));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_98_TEST_HPP
