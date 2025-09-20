// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>

namespace leetcode_1409 {
using std::vector;
using std::unordered_map;

#endif

struct ListNode1409 final {
    ListNode1409 *pre{}, *next{};
    int32_t val{}; // 纯debug用
    int32_t position{};

    ListNode1409(int32_t v, ListNode1409 *pre, ListNode1409 *n) : pre(pre), next(n), val(v) {}
};

class Solution {
public:
    vector<int32_t> processQueries(const vector<int32_t> &queries, int32_t m) {
        ListNode1409 head{0, nullptr, nullptr};
        ListNode1409 *head_pointer{&head};
        vector<ListNode1409 *> todelete{};
        for (int32_t i{0}; i < m; ++i) {
            head_pointer->next = new ListNode1409(i + 1, head_pointer, nullptr);
            head_pointer->next->position = i;
            head_pointer = head_pointer->next;
            todelete.push_back(head_pointer);
        }
        head_pointer = head.next;
        head_pointer->pre = nullptr;
        std::unordered_map<int32_t, ListNode1409 *> loca{};
        for (int32_t i{0}; i < m; ++i) {
            loca[i + 1] = todelete[i];
        }
        vector<int32_t> will_return{};
        for (const auto query: queries) {
            const auto node = loca[query];
            will_return.push_back(node->position);
            const auto pre = node->pre;
            if (pre == nullptr) {  // 前无古人, 不需要操作
                continue;
            }
            for (auto begin{head_pointer}; begin != node; begin = begin->next) {
                begin->position++;
            }
            node->position = 0;
            pre->next = node->next;
            if (pre->next != nullptr) {
                pre->next->pre = pre;
            }
            node->pre = nullptr;
            node->next = head_pointer;
            head_pointer->pre = node;
            head_pointer = node;
        }
        for (auto &pointer: todelete) {
            delete pointer;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
