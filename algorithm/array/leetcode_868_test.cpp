// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_868_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_868_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_868.cpp"

namespace leetcode_868 {

TEST_CASE("test case 1 {test_868}", "{test_868}") {
    Solution solution;
    static constexpr const auto input{22};
    static constexpr const auto result{2};
    CHECK(result == solution.binaryGap(input));
}

TEST_CASE("test case 2 {test_868}", "{test_868}") {
    Solution solution;
    static constexpr const auto input{5};
    static constexpr const auto result{2};
    CHECK(result == solution.binaryGap(input));
}

TEST_CASE("test case 3 {test_868}", "{test_868}") {
    Solution solution;
    static constexpr const auto input{6};
    static constexpr const auto result{1};
    CHECK(result == solution.binaryGap(input));
}

TEST_CASE("test case 4 {test_868}", "{test_868}") {
    Solution solution;
    static constexpr const auto input{8};
    static constexpr const auto result{0};
    CHECK(result == solution.binaryGap(input));
}
}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_868_TEST_HPP
