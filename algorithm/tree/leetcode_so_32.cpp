// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <queue>
#include <tree/treenode.hpp>
#include <vector>

#include "traverse.cpp"
namespace leetcode_so_32 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using namespace Tree_Traverse;
#endif

class Solution {
   public:
    std::vector<int32_t> levelOrderFst(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int32_t> will_return{};
        const auto func = [&will_return](const auto node) {
            will_return.push_back(node->val);
        };
        iter::level(root, func);
        return will_return;
    }

    std::vector<std::vector<int32_t>> levelOrderTrd(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int32_t>> will_return{};
        bool shift{true};
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
            if (shift) {
                will_return.emplace_back(line.begin(), line.end());
            } else {
                will_return.emplace_back(line.rbegin(), line.rend());
            }
            shift = !shift;
            std::swap(now, next);
        }
        return will_return;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
