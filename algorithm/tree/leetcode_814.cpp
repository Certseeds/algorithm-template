// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds



#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_814 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    TreeNode *pruneTree_rec(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree_rec(root->left);
        root->right = pruneTree_rec(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }

public:
    TreeNode *pruneTree(TreeNode *root) {
        return pruneTree_rec(root);
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif