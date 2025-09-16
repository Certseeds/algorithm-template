// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_203 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *removeElements(ListNode *head, int32_t val) {
        ListNode fst{0};
        for (ListNode *base{head}; base != nullptr; base = base->next) {
            if (base->val != val) {
                fst.next = base;
                break;
            }
        }
        if (fst.next == nullptr) {
            return nullptr;
        }
        for (ListNode *base{fst.next}; base->next != nullptr;) {
            ListNode *nnext{base->next};
            if (nnext->val == val) {
                base->next = nnext->next;
            } else {
                base = base->next;
            }
        }
        return fst.next; // should not reach there
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
