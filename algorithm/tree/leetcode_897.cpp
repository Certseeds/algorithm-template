// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/


#ifdef CS203_DSAA_TEST_MACRO

#include <cstddef>
#include <queue>

#include <tree/treenode.hpp>

namespace leetcode_897 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::queue;

#endif


class Solution {
private:
    void getSon(TreeNode *const root, queue<TreeNode *> &pq) {
        if (pq.empty()) {
            return;
        }
        root->left = nullptr;
        root->right = pq.front();
        pq.pop();
        getSon(root->right, pq);
    }

    void rec(TreeNode *const root, queue<TreeNode *> &pq) {
        if (root == nullptr) {
            return;
        }
        rec(root->left, pq);
        pq.push(root);
        rec(root->right, pq);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        queue<TreeNode *> pq;
        rec(root, pq);
        if (pq.empty()) {
            return nullptr;
        }
        auto *const rooted = pq.front();
        pq.pop();
        getSon(rooted, pq);
        return rooted;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif