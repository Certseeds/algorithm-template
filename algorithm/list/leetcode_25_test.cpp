// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_25.cpp"

namespace leetcode_25 {

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.reverseKGroup(vec1[0], 2);
    CHECK(ListNode::equal({2, 1, 4, 3, 5}, result));
}

TEST_CASE("2 [test _25]", "[test _25]") {
    Solution solution;
    const ListNode *const result = solution.reverseKGroup(nullptr, 2);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1};
    Solution solution;
    const ListNode *const result = solution.reverseKGroup(vec1[0], 2);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.reverseKGroup(vec1[0], 3);
    CHECK(ListNode::equal({3, 2, 1, 4, 5}, result));
}

TEST_CASE("5 [test _25]", "[test _25]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.reverseKGroup(vec1[0], 1);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_25_TEST_HPP
