// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_1038 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    int32_t rec(TreeNode *const root, int32_t sum) { // 最小和数大概是反过来?
        if (root == nullptr) {
            return sum;
        }
        const auto rightMax{rec(root->right, sum)};
        root->val += rightMax;
        const auto leftMax{rec(root->left, root->val)};
        return leftMax;
    }

public:
    TreeNode *bstToGst(TreeNode *root) {
        rec(root, 0);
        return root;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif