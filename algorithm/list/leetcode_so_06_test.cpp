// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 剑指OfferII-I Day02
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_06_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_06_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_so_06.cpp"

namespace leetcode_so_06 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_206]", "[test_206]") {
    const LISTNODE::ListNodeLink vec1{1, 2, 3, 4, 5};
    Solution solution;
    const auto result = solution.reversePrint(vec1[0]);
    CHECK_THAT(result, Equals(vector<int32_t>{5, 4, 3, 2, 1}));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_SO_06_TEST_HPP
