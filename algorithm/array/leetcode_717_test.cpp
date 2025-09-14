// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_717.cpp"

namespace leetcode_717 {
using std::vector;

TEST_CASE("test case 1 [test_717]", "[test_717]") {
    vector<int32_t> input{1, 0, 0};
    Solution solution;
    CHECK(solution.isOneBitCharacter(input));
}

TEST_CASE("test case 2 [test_717]", "[test_717]") {
    vector<int32_t> input{1, 1, 1, 0};
    Solution solution;
    CHECK_FALSE(solution.isOneBitCharacter(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP
