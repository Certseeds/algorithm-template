// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds



#ifdef ALGORITHM_TEST_MACRO
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_701 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif


class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int32_t val) {
        auto *const newnode = new TreeNode(val);
        if (root == nullptr) {
            return newnode;
        }
        for (TreeNode *base{root}; base != nullptr;) {
            if (base->val > val) {
                if (base->left == nullptr) {
                    base->left = newnode;
                    return root;
                }
                base = base->left;
            } else {
                if (base->right == nullptr) {
                    base->right = newnode;
                    return root;
                }
                base = base->right;
            }
        }
        return nullptr;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif