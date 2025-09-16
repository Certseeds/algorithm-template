// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_21 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
