// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>

#include <tree/treenode.hpp>
namespace leetcode_938 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    int32_t rangeSumBST(TreeNode *root, int32_t low, int32_t high) {
        if (root == nullptr)
            return 0;
        int32_t willreturn{0};
        willreturn += ((root->val >= low) && (root->val <= high)) ? root->val : 0;
        if (root->val >= high) {
            willreturn += rangeSumBST(root->left, low, high);
        } else if (root->val > low && root->val < high) {
            willreturn += rangeSumBST(root->left, low, high);
            willreturn += rangeSumBST(root->right, low, high);
        } else {
            willreturn += rangeSumBST(root->right, low, high);
        }
        return willreturn;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif