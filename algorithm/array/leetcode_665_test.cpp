// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_665.cpp"

namespace leetcode_665 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_665]", "[test_665]") {
    vector<int32_t> input{4, 2, 3};
    Solution solution;
    CHECK(solution.checkPossibility(input));
}

TEST_CASE("test case 2 [test_665]", "[test_665]") {
    vector<int32_t> input{4, 2, 1};
    Solution solution;
    CHECK_FALSE(solution.checkPossibility(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP
