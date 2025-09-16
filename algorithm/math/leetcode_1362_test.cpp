// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1362.cpp"

namespace leetcode_1362 {

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1362]", "[test_1362]") {
    constexpr const auto input{8};
    constexpr const auto m{3}, n{3};
    Solution solution;
    const std::array<int64_t, 2> result = solution.closetDivisors(input);
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
TEST_CASE("1-2 [test_1362]", "[test_1362]") {
    constexpr const auto input{123};
    constexpr const auto m{5}, n{25};
    Solution solution;
    const std::array<int64_t, 2> result = solution.closetDivisors(input);
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
TEST_CASE("1-3 [test_1362]", "[test_1362]") {
    constexpr const auto input{999};
    constexpr const auto m{25}, n{40};
    Solution solution;
    const std::array<int64_t, 2> result = solution.closetDivisors(input);
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP

