// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day11

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_so_22.cpp"

namespace leetcode_so_22 {

using LISTNODE::ListNodeLink;
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1};
    Solution solution;
    const auto result = solution.getKthFromEnd(vec1[0], 1);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("test case 2 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{4, 5, 1, 9};
    Solution solution;
    const auto result = solution.getKthFromEnd(vec1[0], 3);
    CHECK(ListNode::equal({5, 1, 9}, result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_22_TEST_HPP
