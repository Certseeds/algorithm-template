// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_206 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    /**
     * 第一版
     * */
    ListNode *reverseList2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *ll = head;
        ListNode *rl = head->next;
        ListNode *rr = rl->next;
        while (rr != nullptr) {
            head->next = rr;
            rl->next = ll;
            ll = rl;
            rl = rr;
            rr = rr->next;
        }
        head->next = nullptr;
        rl->next = ll;
        ll = rl;
        return ll;
    }

    /**
     * 化简版
     * */
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *ll = head;
        ListNode *rl = head->next;
        while (rl != nullptr) {
            ListNode *rr = rl->next;
            head->next = rr;
            rl->next = ll;
            ll = rl;
            rl = rr;
        }
        return ll;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
