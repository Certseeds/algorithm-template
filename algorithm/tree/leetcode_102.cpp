// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <queue>
#include <vector>
#include <tree/treenode.hpp>
#include <algorithm>
namespace leetcode_102 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::queue;
#endif


class Solution {
public:
    vector<vector<int32_t>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int32_t>> will_return{};
        for (queue<const TreeNode *> now{{root}}, next{}; !now.empty();) {
            vector<int32_t> line{};
            while (!now.empty()) {
                const auto *const head = now.front();
                now.pop();
                line.push_back(head->val);
                if (head->left != nullptr) {
                    next.push(head->left);
                }
                if (head->right != nullptr) {
                    next.push(head->right);
                }
            }
            will_return.push_back(line);
            std::swap(now, next);
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
