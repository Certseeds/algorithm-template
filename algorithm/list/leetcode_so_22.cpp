// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_so_22 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int32_t k) {
        const ListNode *slow{head}, *fast{head};
        for (int32_t i{0}; fast != nullptr && i < k; (fast = fast->next) && ++i) {}
        if (fast == nullptr) {
            return const_cast<ListNode *>(slow);
        }
        for (; fast != nullptr; (fast = fast->next) && (slow = slow->next)) {}
        return slow->next;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
