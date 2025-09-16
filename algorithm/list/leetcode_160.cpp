/*
AGPL-3.0-or-later License

CS160_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <list/listnode.hpp>

namespace leetcode_160 {
using LISTNODE::ListNode;

#endif

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t aSize{0}, bSize{0};
        for (ListNode *temp{headA}; temp != nullptr; temp = temp->next, ++aSize) {}
        for (ListNode *temp{headB}; temp != nullptr; temp = temp->next, ++bSize) {}
        if (aSize > bSize) {
            for (size_t i{bSize}; i < aSize; ++i, headA = headA->next) {}
        } else if (aSize < bSize) {
            for (size_t i{aSize}; i < bSize; ++i, headB = headB->next) {}
        }
        ListNode aObj{-1, headA}, bObj{-1, headB};
        for (headA = &aObj, headB = &bObj; headA != nullptr; headA = headA->next, headB = headB->next) {
            if (headA->next == headB->next) {
                return headA->next;
            }
        }
        return nullptr;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
