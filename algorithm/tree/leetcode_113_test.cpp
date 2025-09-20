// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day12
//@Plan 剑指OfferII-I Day15
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_113_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_113_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_113.cpp"

namespace leetcode_113 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_113]", "[test_113]") {
    Solution solution;
    const TreeNodeLink input{5,
                             4, 8,
                             11, TreeNode::No, 13, 4,
                             7, 2, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 5, 1
    };
    static constexpr const auto target{22};
    const vector<vector<int32_t>> output{{5, 4, 11, 2},
                                         {5, 8, 4,  5}};
    CHECK_THAT(output, Equals(solution.pathSum(input[0], target)));
}

TEST_CASE("test_case 2 [test_113]", "[test_113]") {
    Solution solution;
    const TreeNodeLink input{1,
                             2, 3};
    static constexpr const auto target{5};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(solution.pathSum(input[0], target)));
}

TEST_CASE("test_case 3 [test_113]", "[test_113]") {
    Solution solution;
    const TreeNodeLink input{1,
                             2};
    static constexpr const auto target{0};
    const vector<vector<int32_t>> output{};
    CHECK_THAT(output, Equals(solution.pathSum(input[0], target)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_113_TEST_HPP
