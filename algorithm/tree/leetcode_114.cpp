// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <stack>

#include <tree/treenode.hpp>
namespace leetcode_114 {
using std::vector;
using std::stack;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode base{-1};
        TreeNode *last = &base;
        for (stack<TreeNode *> sta{{root}}; !sta.empty();) {
            TreeNode *const head = sta.top();
            sta.pop();
            if (head->right != nullptr) {
                sta.push(head->right);
            }
            if (head->left != nullptr) {
                sta.push(head->left);
            }
            last->right = head;
            last->left = nullptr;
            last = head;
        }
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
