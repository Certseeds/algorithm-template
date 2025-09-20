// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_so_18 {
using LISTNODE::ListNode;
#endif

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int32_t val) {
        ListNode base{-1};
        base.next = head;
        for (ListNode *root{&base}; root->next != nullptr; root = root->next) {
            if (root->next->val == val) {
                root->next = root->next->next;
                break;
            }
        }
        return base.next;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
