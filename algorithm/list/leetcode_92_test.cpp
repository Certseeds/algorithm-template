// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_92.cpp"

namespace leetcode_92 {

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _92]", "[test _92]") {
    const ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const ListNode *const result = solution.reverseBetween(vec1[0], 2, 4);
    CHECK(ListNode::equal({1, 4, 3, 2, 5}, result));
}

TEST_CASE("0 [test _92]", "[test _92]") {
    const ListNodeLink vec1{5};
    Solution solution;
    const ListNode *const result = solution.reverseBetween(vec1[0], 1, 1);
    CHECK(ListNode::equal({5}, result));
}

TEST_CASE("1 [test _92]", "[test _92]") {
    const ListNodeLink vec1{3, 5};
    Solution solution;
    const ListNode *const result = solution.reverseBetween(vec1[0], 1, 1);
    CHECK(ListNode::equal({3, 5}, result));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_92_TEST_HPP
