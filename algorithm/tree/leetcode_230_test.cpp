// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_230_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_230_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_230.cpp"

namespace leetcode_230 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_230]", "[test_230]") {
    Solution solution;
    const TreeNodeLink input{3,
                             1, 4,
                             TreeNode::No, 2};
    static constexpr const auto k{1};
    static constexpr const auto result{1};
    CHECK(result == solution.kthSmallest(input[0], k));
}

TEST_CASE("test_case 2 [test_230]", "[test_230]") {
    Solution solution;
    const TreeNodeLink input{5,
                             3, 6,
                             2, 4, TreeNode::No, TreeNode::No,
                             1
    };
    static constexpr const auto k{3};
    static constexpr const auto result{3};
    CHECK(result == solution.kthSmallest(input[0], k));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_230_TEST_HPP
