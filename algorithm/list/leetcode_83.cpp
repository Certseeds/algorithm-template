// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_83 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val) {
            head = head->next;
        }
        return head;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

