// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_61.cpp"

namespace leetcode_61 {

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 0);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("0 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({1, 2}, result));
}

TEST_CASE("1 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({4, 5, 1, 2, 3}, result));
}

TEST_CASE("2 [test _61]", "[test _61]") {
    Solution solution;
    const ListNode *const result = solution.rotateRight(nullptr, 2);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 2);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 3);
    CHECK(ListNode::equal({3, 4, 5, 1, 2}, result));
}

TEST_CASE("5 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 4);
    CHECK(ListNode::equal({2, 3, 4, 5, 1}, result));
}

TEST_CASE("6 [test _61]", "[test _61]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.rotateRight(vec1[0], 1234);
    CHECK(ListNode::equal({2, 3, 4, 5, 1}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_61_TEST_HPP
