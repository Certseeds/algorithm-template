// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>
#include "leetcode_338.cpp"

namespace leetcode_338 {
using std::vector;
using Catch::Matchers::Equals;

TEST_CASE("1 [test_338]", "[test_338]") {
    static constexpr const auto input{0};
    const vector<int32_t> result{0};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}

TEST_CASE("2 [test_338]", "[test_338]") {
    static constexpr const auto input{1};
    const vector<int32_t> result{0, 1};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}

TEST_CASE("3 [test_338]", "[test_338]") {
    static constexpr const auto input{2};
    const vector<int32_t> result{0, 1, 1};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}

TEST_CASE("4 [test_338]", "[test_338]") {
    static constexpr const auto input{5};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}

TEST_CASE("5 [test_338]", "[test_338]") {
    static constexpr const auto input{33};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
                                 4, 4, 5, 1, 2};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}

TEST_CASE("6 [test_338]", "[test_338]") {
    static constexpr const auto input{63};
    const vector<int32_t> result{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3,
                                 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
                                 4, 5, 4, 5, 5, 6};
    Solution solution;
    CHECK_THAT(result, Equals(solution.countBits(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_338_TEST_HPP

