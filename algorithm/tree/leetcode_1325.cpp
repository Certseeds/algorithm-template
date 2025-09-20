// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds


#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_1325 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *removeLeafNodesRec(TreeNode *root, int target) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *const left = removeLeafNodesRec(root->left, target);
        TreeNode *const right = removeLeafNodesRec(root->right, target);
        if (left == nullptr && right == nullptr) {
            if (root->val == target) {
                return nullptr;
            }
        }
        root->left = left;
        root->right = right;
        return root;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
