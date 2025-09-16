// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_82_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_82_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_82.cpp"

namespace leetcode_82 {

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("0 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1, 2};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2}, result));
}

TEST_CASE("1 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 2, 3, 4, 5}, result));
}

TEST_CASE("2 [test _82]", "[test _82]") {
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(nullptr);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1}, result));
}

TEST_CASE("4 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1, 2, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 3, 4, 5}, result));
}

TEST_CASE("5 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1, 2, 2, 3, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({1, 4, 5}, result));
}

TEST_CASE("6 [test _82]", "[test _82]") {
    const ListNodeLink vec1{1, 1, 2, 2, 3, 3, 4, 4, 5};
    Solution solution;
    const ListNode *const result = solution.deleteDuplicates(vec1[0]);
    CHECK(ListNode::equal({5}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_82_TEST_HPP
