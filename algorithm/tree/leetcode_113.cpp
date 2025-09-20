// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds


#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
#include <queue>

#include <tree/treenode.hpp>
namespace leetcode_113 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif


using std::queue;
using std::vector;

class Solution {
public:
    vector<vector<int32_t>> pathSum(TreeNode *root, int target) {
        vector<vector<int32_t>> sums;
        if (root == nullptr) {
            return sums;
        }
        for (queue<std::pair<TreeNode *, const vector<int32_t>>> now{{{root, {root->val}}}}; !now.empty();) {
            const auto[head, vec] = now.front();
            now.pop();
            if (head->val == target && head->left == nullptr && head->right == nullptr) {
                sums.push_back(vec);
                continue;
            }
            if (head->left != nullptr) {
                vector<int32_t> path{vec};
                path.push_back(head->left->val);
                head->left->val += head->val;
                now.emplace(head->left, path);
            }
            if (head->right != nullptr) {
                vector<int32_t> path{vec};
                path.push_back(head->right->val);
                head->right->val += head->val;
                now.emplace(head->right, path);
            }
        }
        return sums;
    }
};
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
