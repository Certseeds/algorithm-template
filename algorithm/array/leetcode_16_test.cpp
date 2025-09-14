// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP

#include "leetcode_16.cpp"
#include <catch_main.hpp>

namespace leetcode_16 {
using std::vector;

TEST_CASE("1 [test_16]", "[test_16]") {
    vector<int32_t> nums{-1, 2, 1, -4};
    auto clas = Solution();
    const auto output = clas.threeSumClosest(nums, 1);
    CHECK(output == 2);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_16_TEST_HPP
