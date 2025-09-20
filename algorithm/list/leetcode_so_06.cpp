// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <stack>
#include <list/listnode.hpp>

namespace leetcode_so_06 {
using std::vector;
using LISTNODE::ListNode;
#endif

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        std::stack<int32_t> sta;
        while (head != nullptr) {
            sta.push(head->val);
            head = head->next;
        }
        vector<int32_t> will_return;
        while (!sta.empty()) {
            will_return.push_back(sta.top());
            sta.pop();
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
