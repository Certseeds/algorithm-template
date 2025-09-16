// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_109 {
using LISTNODE::ListNode;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
#endif

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return new TreeNode(head->val);
        }
        ListNode *one{head}, *two{head}, *prev{nullptr};
        while (two->next != nullptr) {
            prev = one;
            one = one->next;
            two = two->next;
            if (two->next != nullptr) {
                two = two->next;
            }
        }
        auto *const mid = new TreeNode(one->val);
        prev->next = nullptr;
        mid->left = sortedListToBST(head);
        mid->right = sortedListToBST(one->next);
        return mid;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

