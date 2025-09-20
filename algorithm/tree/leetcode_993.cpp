// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds


#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>
#include <queue>
#include <utility>

#include <tree/treenode.hpp>
namespace leetcode_993 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::queue;
#endif

class Solution {
public:


    bool isCousins(TreeNode *root, int x, int y) {
        for (queue<const TreeNode *> now{{root}}, next{}; !now.empty(); std::swap(now, next)) {
            for (bool getX{false}, getY{false}; !now.empty();) {
                const auto head = now.front();
                now.pop();
                if (head->left != nullptr && head->right != nullptr) {
                    if ((head->left->val == x && head->right->val == y) ||
                        (head->left->val == y && head->right->val == x)) {
                        return false;
                    }
                }
                const auto func = [&next, x, y, &getX, &getY](const TreeNode*const pointer) {
                    if (pointer != nullptr) {
                        next.push(pointer);
                        if (pointer->val == x) {
                            getX = true;
                        } else if (pointer->val == y) {
                            getY = true;
                        }
                    }
                };
                func(head->left);
                func(head->right);
                if (getX && getY) {
                    return true;
                }
            }
        }
        return false;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
