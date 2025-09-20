// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include "leetcode_unknown.cpp"

namespace leetcode_unknown {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_unknown]", "[test_unknown]") {
    Solution solution;
    const TreeNodeLink input{5,
                                3, 6,
                                2, 4, TreeNode::No, 7,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No};
    static constexpr const auto target{9};
    CHECK(solution.findTarget(input[0], target));
}
}
