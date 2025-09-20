// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <unordered_set>
#include <list/listnode.hpp>

namespace leetcode_141 {
using std::unordered_set;
using LISTNODE::ListNode;

#endif

// 无需畏惧死循环, while这个肯定能打破

class Solution {
public:
    bool hasCycle(ListNode *head) {
        for (unordered_set<ListNode *> nodes{}; head != nullptr;) {
            if (nodes.count(head) != 0) {
                return true;
            }
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {
        for (ListNode *quick{head}, *slow{head}; quick != nullptr && slow != nullptr;) {
            slow = slow->next;
            quick = quick->next;
            if (quick == nullptr) {
                return false;
            }
            quick = quick->next;
            if (slow == quick && slow != nullptr) {
                return true;
            }
        }
        return false;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

