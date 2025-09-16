// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Tag 优先队列
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_23.cpp"

namespace leetcode_23 {

using LISTNODE::ListNodeLink;

TEST_CASE("1 [test _23]", "[test _23]") {
    const ListNodeLink vec1{1, 4, 5};
    const ListNodeLink vec2{1, 3, 4};
    const ListNodeLink vec3{2, 6};
    const auto input = vector<ListNode *>{vec1[0], vec2[0], vec3[0]};
    Solution solution;
    const ListNode *const result = solution.mergeKLists(input);
    CHECK(ListNode::equal({1, 1, 2, 3, 4, 4, 5, 6}, result));
}

TEST_CASE("2 [test _23]", "[test _23]") {
    const auto input = vector<ListNode *>{};
    Solution solution;
    const ListNode *const result = solution.mergeKLists(input);
    CHECK(ListNode::equal({}, result));
}

TEST_CASE("3 [test _23]", "[test _23]") {
    const auto input = vector<ListNode *>{nullptr};
    Solution solution;
    const ListNode *const result = solution.mergeKLists(input);
    CHECK(ListNode::equal({}, result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_23_TEST_HPP
