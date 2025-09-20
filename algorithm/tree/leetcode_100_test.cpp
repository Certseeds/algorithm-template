// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_100.cpp"
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_100 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_100]", "[test_100]") {
    Solution solution;
    const TreeNodeLink vec{1, 2};
    const TreeNodeLink vec2{1, TreeNode::No, 2};
    CHECK_FALSE(solution.isSameTree(vec[0], vec2[0]));
}

TEST_CASE("test_case 2 [test_100]", "[test_100]") {
    Solution solution;
    const TreeNodeLink vec{1, 2, 3};
    const TreeNodeLink vec2{1, 2, 3};
    CHECK(solution.isSameTree(vec[0], vec2[0]));
}

TEST_CASE("test_case 3 [test_100]", "[test_100]") {
    Solution solution;
    const TreeNodeLink vec{1, 2, 1};
    const TreeNodeLink vec2{1, 1, 2};
    CHECK_FALSE(solution.isSameTree(vec[0], vec2[0]));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_100_TEST_HPP
