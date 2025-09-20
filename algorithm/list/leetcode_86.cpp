// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_86 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *partition(ListNode *head, int32_t x) {
        ListNode node1{-1}, node2{-1};
        ListNode *p_node1{&node1}, *p_node2{&node2};
        while (head != nullptr) {
            if (head->val >= x) {
                p_node2->next = new ListNode(head->val);
                p_node2 = p_node2->next;
            } else {
                p_node1->next = new ListNode(head->val);
                p_node1 = p_node1->next;
            }
            head = head->next;
        }
        p_node1->next = node2.next;
        return node1.next;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

