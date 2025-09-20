// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/



#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <stack>

#include <tree/treenode.hpp>
namespace leetcode_1022 {
using std::vector;
using std::stack;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

#include <stack>

class Solution {
public:
    int32_t sumRootToLeaf(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int32_t willreturn{0};
        for (stack<TreeNode *> tree{{root}}; !tree.empty();) {
            TreeNode *const begin = tree.top();
            tree.pop();
            if (begin->left == nullptr && begin->right == nullptr) {
                willreturn += begin->val;
                continue;
            }
            if (begin->left != nullptr) {
                begin->left->val += begin->val << 1;
                tree.push(begin->left);
            }
            if (begin->right != nullptr) {
                begin->right->val += begin->val << 1;
                tree.push(begin->right);
            }
        }
        return willreturn;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
