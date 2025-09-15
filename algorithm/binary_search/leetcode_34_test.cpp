// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Hard
//@Plan 剑指OfferII-I Day04
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP

#include "leetcode_34.cpp"
#include <catch_main.hpp>

namespace leetcode_34 {
using std::vector;

TEST_CASE("test case 1", "[test leetcode_34]") {
    const vector<int32_t> vec0{};
    const vector<int32_t> vec1{5, 7, 7, 8, 8, 10};
    Solution solution;
    assert(solution.searchRange(vec1, 8)[0] == 3 && solution.searchRange(vec1, 8)[1] == 4);
    assert(solution.searchRange(vec1, 6)[0] == -1 && solution.searchRange(vec1, 6)[1] == -1);
    assert(solution.searchRange(vec0, 115)[0] == -1 && solution.searchRange(vec0, 6)[1] == -1);
}

}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_34_TEST_HPP
