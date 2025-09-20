// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Description 链表中点,经典双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_876_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_876_TEST_HPP

#include <catch_main.hpp>
#include <list/listnode.hpp>
#include "leetcode_876.cpp"

namespace leetcode_876 {

TEST_CASE("test case 1 [test_876]", "[test_876]") {
    const LISTNODE::ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const auto result = solution.middleNode(vec1[0]);
    CHECK(3 == result->val);
}

TEST_CASE("test case 2 [test_876]", "[test_876]") {
    const LISTNODE::ListNodeLink vec1{1, 1, 4, 5, 1, 4};
    Solution solution;
    const auto result = solution.middleNode(vec1[0]);
    CHECK(5 == result->val);
}

TEST_CASE("test case 3 [test_876]", "[test_876]") {
    const LISTNODE::ListNodeLink vec1{1, 9, 1, 9, 8, 1, 0};
    Solution solution;
    const auto result = solution.middleNode(vec1[0]);
    CHECK(9 == result->val);
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_876_TEST_HPP
