// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
#include <cstddef>
#include <cstdint>
#include <list/listnode.hpp>
#include <queue>
#include <tree/treenode.hpp>
namespace leetcode_1367 {
using std::queue;
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using LISTNODE::ListNode;
#endif

class Solution {
private:
    bool isSubPathRec(ListNode *head, TreeNode *root) {
        if (head == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        if (head->val != root->val) {
            return false;
        }
        const auto left = isSubPathRec(head->next, root->left);
        const auto right = isSubPathRec(head->next, root->right);
        return left || right;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (head == nullptr) {
            return true;
        } else if (root == nullptr) {
            return false;
        }
        for (queue<TreeNode *> que{{root}}; !que.empty();) {
            const auto leader = que.front();
            que.pop();
            if (leader->left != nullptr) {
                que.push(leader->left);
            }
            if (leader->right != nullptr) {
                que.push(leader->right);
            }
            if (isSubPathRec(head, leader)) {
                return true;
            }
        }
        return false;
    }
};
#ifdef ALGORITHM_TEST_MACRO
}
#endif
