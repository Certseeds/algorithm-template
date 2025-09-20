// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_24 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }
        ListNode *const fir = head;
        ListNode *const sec = fir->next;
        ListNode *const third = swapPairs(sec->next);
        sec->next = fir;
        fir->next = third;
        return sec;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

