// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_263.cpp"

namespace leetcode_263 {

TEST_CASE("1 [test_263]", "[test_263]") {
    static constexpr const auto input{6};
    Solution solution;
    CHECK(solution.isUgly(input));
}

TEST_CASE("2 [test_263]", "[test_263]") {
    static constexpr const auto input{8};
    Solution solution;
    CHECK(solution.isUgly(input));
}

TEST_CASE("3 [test_263]", "[test_263]") {
    static constexpr const auto input{14};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}

TEST_CASE("4 [test_263]", "[test_263]") {
    static constexpr const auto input{1};
    Solution solution;
    CHECK(solution.isUgly(input));
}

TEST_CASE("5 [test_263]", "[test_263]") {
    static constexpr const auto input{-1};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}

TEST_CASE("6 [test_263]", "[test_263]") {
    static constexpr const auto input{0};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}

TEST_CASE("7 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::min()};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}

TEST_CASE("8 [test_263]", "[test_263]") {
    static constexpr const auto input{std::numeric_limits<int32_t>::max()};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}

TEST_CASE("9 [test_263]", "[test_263]") {
    static constexpr const auto input{233};
    Solution solution;
    CHECK_FALSE(solution.isUgly(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_263_TEST_HPP

