// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_50.cpp"

namespace leetcode_50 {

using Catch::Approx;
static constexpr const auto epsilon{1e-3};

TEST_CASE("1 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2147483648};
    static constexpr const auto result{0.0};
    Solution solution;
    CHECK(Approx(result).epsilon(epsilon) == solution.myPow(x, n));
}

TEST_CASE("2 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{10};
    static constexpr const auto result{1024.0};
    Solution solution;
    CHECK(Approx(result).epsilon(epsilon) == solution.myPow(x, n));
}

TEST_CASE("3 [test_50]", "[test_50]") {
    static constexpr const auto x{2.00000};
    static constexpr const auto n{-2};
    static constexpr const auto result{0.25};
    Solution solution;
    CHECK(Approx(result).epsilon(epsilon) == solution.myPow(x, n));
}

TEST_CASE("4 [test_50]", "[test_50]") {
    static constexpr const auto x{2.1};
    static constexpr const auto n{3};
    static constexpr const auto result{9.261};
    Solution solution;
    CHECK(Approx(result).epsilon(epsilon) == solution.myPow(x, n));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_50_TEST_HPP
