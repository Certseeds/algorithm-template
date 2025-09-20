// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <list/listnode.hpp>

namespace leetcode_19 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int32_t n) {
        // auto *will_return = new ListNode(0);
        ListNode will_return_o{0, head};
        auto *const will_return = &will_return_o;
        ListNode *first = will_return;
        ListNode *second = will_return;
        if (n == 0) {
            second = second->next;
            while (second->next != nullptr) {
                first = first->next;
                second = second->next;
            }
            first->next = nullptr;
            return head;
        }
        for (int32_t i{0}; i <= n; i++) {
            second = second->next;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }
        if (first == nullptr || first->next == nullptr) {
            return head;
        }
        first->next = (first->next)->next;
        return will_return->next;
    }

    ListNode *removeNthFromEnd2(ListNode *head, int32_t n) {
        // auto *will_return = new ListNode(0);
        ListNode will_return_o{0, head};
        auto *const will_return = &will_return_o;
        ListNode *first = will_return;
        ListNode *second = will_return;
        for (int32_t i{0}; i <= n; i++) {
            second = second->next;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }
        if (first == nullptr || first->next == nullptr) {
            return head;
        }
        first->next = (first->next)->next;
        return will_return->next;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
