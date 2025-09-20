// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 数据结构入门 Day7
//@Plan 剑指OfferII-I Day12
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP

#include <catch_main.hpp>
#include <cstddef>
#include "leetcode_21.cpp"

namespace leetcode_21 {
using LISTNODE::ListNode;
using LISTNODE::ListNodeLink;

TEST_CASE("1 [test_21]", "[test_21]") {
    const ListNodeLink vec1{1, 2, 4};
    const ListNodeLink vec2{1, 3, 4};
    auto clas = Solution();
    const ListNode *const node1 = clas.mergeTwoLists(vec1[0], vec2[0]);
    CHECK(ListNode::equal({1, 1, 2, 3, 4, 4}, node1));
}

TEST_CASE("2 [test_21]", "[test_21]") {
    const ListNodeLink vec1{1, 1, 1, 4, 4, 5};
    const ListNodeLink vec2{0, 1, 1, 1, 8, 9, 9};
    auto clas = Solution();
    const ListNode *const node1 = clas.mergeTwoLists(vec1[0], vec2[0]);
    CHECK(ListNode::equal({0, 1, 1, 1, 1, 1, 1, 4, 4, 5, 8, 9, 9}, node1));
}

TEST_CASE("3 [test_21]", "[test_21]") {
    auto clas = Solution();
    const ListNode *const node1 = clas.mergeTwoLists(nullptr, nullptr);
    CHECK(ListNode::equal({}, node1));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_21_TEST_HPP
