// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_414_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_414_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_414.cpp"

namespace leetcode_414 {

TEST_CASE("1 [test_414]", "[test_414]") {
    const vector<int32_t> input{3, 2, 1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.thirdMax(input));
}

TEST_CASE("2 [test_414]", "[test_414]") {
    const vector<int32_t> input{2, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.thirdMax(input));
}

TEST_CASE("3 [test_414]", "[test_414]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.thirdMax(input));
}

TEST_CASE("4 [test_414]", "[test_414]") {
    const vector<int32_t> input{1, 9, 1, 9, 8, 1, 0};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.thirdMax(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_414_TEST_HPP

