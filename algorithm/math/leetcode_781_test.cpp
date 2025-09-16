// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_781.cpp"

namespace leetcode_781 {
using std::vector;
using Catch::Matchers::Equals;

TEST_CASE("1 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 2};
    static constexpr const auto output{5};
    Solution solution;
    CHECK(output == solution.numRabbits(input));
}

TEST_CASE("2 [test_781]", "[test_781]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto output{15};
    Solution solution;
    CHECK(output == solution.numRabbits(input));
}

TEST_CASE("3 [test_781]", "[test_781]") {
    const vector<int32_t> input{10, 10, 10};
    static constexpr const auto output{11};
    Solution solution;
    CHECK(output == solution.numRabbits(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_781_TEST_HPP

