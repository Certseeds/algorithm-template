// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <stack>
#include <algorithm>
#include <tree/treenode.hpp>
namespace leetcode_104 {
using std::stack;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

#endif


class Solution {
public:
    int32_t maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        root->val = 1;
        int32_t will_return{1};
        stack<TreeNode *> tree{{root}};
        while (!tree.empty()) {
            const TreeNode *begin = tree.top();
            tree.pop();
            if (begin->left == nullptr && begin->right == nullptr) {
                will_return = std::max(will_return, begin->val);
                continue;
            }
            if (begin->left != nullptr) {
                begin->left->val = begin->val + 1;
                tree.push(begin->left);
            }
            if (begin->right != nullptr) {
                begin->right->val = begin->val + 1;
                tree.push(begin->right);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
