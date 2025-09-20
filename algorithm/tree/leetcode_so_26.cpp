// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_so_26 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
private:
    bool in(TreeNode *A, TreeNode *B) {
        if (B == nullptr) {
            return true;
        } else if (A == nullptr) {
            return false;
        }
        return A->val == B->val && in(A->left, B->left) && in(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr || A == nullptr) {
            return false;
        }
        return in(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif