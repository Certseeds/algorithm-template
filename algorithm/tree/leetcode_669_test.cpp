// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_669.cpp"

namespace leetcode_669 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_669]", "[test_669]") {
    Solution solution;
    const TreeNodeLink input{1, 0, 2};
    const vector<int32_t> result{1,
                                 TreeNode::No, 2,
                                 TreeNode::No, TreeNode::No
    };
    auto *const resultPtr = solution.trimBST(input[0], 1, 2);
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP
