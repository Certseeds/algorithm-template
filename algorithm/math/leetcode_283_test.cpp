// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>
#include "leetcode_283.cpp"

namespace leetcode_283 {
using std::vector;
using Catch::Matchers::Equals;

TEST_CASE("1 [test_283]", "[test_283]") {
    vector<int32_t> input{0, 1, 0, 3, 12};
    const vector<int32_t> result{1, 3, 12, 0, 0};
    Solution solution;
    WHEN("one node") {
        solution.moveZeroes(input);
        THEN("the values") {
            CHECK_THAT(result, Equals(input));
        }
    }WHEN("one node") {
        solution.moveZeroes2(input);
        THEN("the values") {
            CHECK_THAT(result, Equals(input));
        }
    }

}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_283_TEST_HPP

