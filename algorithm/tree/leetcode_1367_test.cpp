// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>


#include <tree/treenode_link.hpp>
#include "leetcode_1367.cpp"

namespace leetcode_1367 {

using LISTNODE::ListNodeLink;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1367]", "[test_1367]") {
    Solution solution;
    const ListNodeLink vec1{4, 2, 8};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK(solution.isSubPath(vec1[0], vec2[0]));
}

TEST_CASE("test_case 2 [test_1367]", "[test_1367]") {
    Solution solution;
    const ListNodeLink vec1{1, 4, 2, 6};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK(solution.isSubPath(vec1[0], vec2[0]));
}


TEST_CASE("test_case 3 [test_1367]", "[test_1367]") {
    Solution solution;
    const ListNodeLink vec1{1, 4, 2, 6, 8};
    const TreeNodeLink vec2{
            1,
            4, 4,
            TreeNode::No, 2, 2, TreeNode::No,
            TreeNode::No, TreeNode::No, 1, TreeNode::No, 6, 8, TreeNode::No, TreeNode::No,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, \
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 3
    };
    CHECK_FALSE(solution.isSubPath(vec1[0], vec2[0]));
}
}
