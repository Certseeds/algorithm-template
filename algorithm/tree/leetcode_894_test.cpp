// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_894_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_894_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_894.cpp"

namespace leetcode_894 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_894]", "[test_894]") {
    Solution solution;
    // The test case is a placeholder.
    // Calling the function to ensure it compiles.
    solution.allPossibleFBT(7);
    CHECK(std::true_type::value);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_894_TEST_HPP
