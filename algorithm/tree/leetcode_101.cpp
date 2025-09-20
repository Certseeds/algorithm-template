// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO
#include <tree/treenode.hpp>
namespace leetcode_101 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

#endif


class Solution {
private:
    bool isSym(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if ((left == nullptr) != (right == nullptr)) {
            return false;
        }
        return left->val == right->val && isSym(left->left, right->right) && isSym(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSym(root->left, root->right);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
