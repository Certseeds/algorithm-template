// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/

#include <tree/treenode.hpp>

#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
namespace leetcode_100 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

#endif


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == q) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        return p->val == q->val &&
               isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
