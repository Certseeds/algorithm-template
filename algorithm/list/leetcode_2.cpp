// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <list/listnode.hpp>

namespace leetcode_2 {
using LISTNODE::ListNode;

#endif

class Solution {
private:
    int32_t get_depth(ListNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int32_t will_return = 0;
        while (node != nullptr) {
            will_return++;
            node = node->next;
        }
        return will_return;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1_in, ListNode *l2_in) {
        ListNode *l1 = l1_in;
        ListNode *l2 = l2_in;
        if (get_depth(l2) > get_depth(l1)) {
            std::swap(l1, l2);
        }
        ListNode will_return{0};
        ListNode *head = &will_return;
        int32_t add_in = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int32_t sum = (l1->val + l2->val + add_in);
            head->next = new ListNode(sum % 10);
            add_in = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        while (l1 != nullptr) {
            int32_t sum = (l1->val + add_in);
            head->next = new ListNode{sum % 10};
            add_in = sum / 10;
            l1 = l1->next;
            head = head->next;
        }
        if (add_in != 0) {
            head->next = new ListNode{add_in};
        }
        return will_return.next;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
