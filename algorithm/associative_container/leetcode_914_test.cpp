// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash函数
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP

#include "leetcode_914.cpp"
#include <catch_main.hpp>

namespace leetcode_914 {

TEST_CASE("test case 1 {test_914}", "{test_914}") {
    const vector<int32_t> input{1, 2, 3, 4, 4, 3, 2, 1};
    Solution solution;
    CHECK(solution.hasGroupsSizeX(input));
}

TEST_CASE("test case 2 {test_914}", "{test_914}") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    Solution solution;
    CHECK_FALSE(solution.hasGroupsSizeX(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP
