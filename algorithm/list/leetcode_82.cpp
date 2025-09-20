// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_82 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode will_return(-1);
        ListNode *will_return_ptr = &will_return;
        while (head != nullptr) {
            ListNode *const head_back{head};
            size_t count{0};
            for (int32_t v = head->val; head != nullptr && head->val == v; head = head->next) {
                count++;
            }
            if (count == 1) {
                will_return_ptr->next = head_back;
                will_return_ptr = will_return_ptr->next;
            }
        }
        will_return_ptr->next = nullptr;
        return will_return.next;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif

