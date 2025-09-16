// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day11

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_18_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_18_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_so_18.cpp"

namespace leetcode_so_18 {

using LISTNODE::ListNodeLink;
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{4, 5, 1, 9};
    Solution solution;
    const auto result = solution.deleteNode(vec1[0], 5);
    CHECK(ListNode::equal({4, 1, 9}, result));
}

TEST_CASE("test case 2 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{4, 5, 1, 9};
    Solution solution;
    const auto result = solution.deleteNode(vec1[0], 1);
    CHECK(ListNode::equal({4, 5, 9}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_18_TEST_HPP
