// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include "leetcode_814.cpp"

namespace leetcode_814 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_814]", "[test_814]") {
    Solution solution;
    const TreeNodeLink input{1,
                             TreeNode::No, 0,
                             TreeNode::No, TreeNode::No, 0, 1
    };
    const vector<int32_t> result{1,
                                 TreeNode::No, 0,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No // 这里是一处缺陷,两个TreeNode::No本应在左边
    };
    const auto output = solution.pruneTree(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}
TEST_CASE("test_case 2 [test_814]", "[test_814]") {
    Solution solution;
    const TreeNodeLink input{1,
                             0, 0,
                             0, 0, 0, 1
    };
    const vector<int32_t> result{1,
                                 TreeNode::No, 0,
                                 TreeNode::No, 1, TreeNode::No, TreeNode::No // 这里是一处缺陷,两个TreeNode::No本应在左边
    };
    const auto output = solution.pruneTree(input[0]);
    CHECK(TREE_NODE::judge_equal(output, result));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_814_TEST_HPP
