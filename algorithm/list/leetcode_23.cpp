// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <queue>
#include <list/listnode.hpp>

namespace leetcode_23 {
using std::vector;
using std::priority_queue;
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *mergeKLists(const vector<ListNode *> &lists) {
        static constexpr auto cmp{
                [](const ListNode *const v1, const ListNode *const v2) {
                    return v1->val > v2->val;
                }};
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq{cmp};
        for (auto &&ele: lists) {
            if (ele != nullptr) {
                pq.push(ele);
            }
        }
        ListNode head(0);
        for (ListNode *stable = &head; !pq.empty();) {
            stable->next = pq.top();
            pq.pop();
            stable = stable->next;
            if (stable->next != nullptr) {
                pq.push(stable->next);
            }
        }
        return head.next;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

