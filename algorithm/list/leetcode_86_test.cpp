// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_86.cpp"

namespace leetcode_86 {

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _86]", "[test _86]") {
    const ListNodeLink vec1{1, 4, 3, 2, 5, 2};
    Solution solution;
    const ListNode *const result = solution.partition(vec1[0], 3);
    CHECK(ListNode::equal({1, 2, 2, 4, 3, 5}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_86_TEST_HPP
