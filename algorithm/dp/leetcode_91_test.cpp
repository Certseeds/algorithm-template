// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day10
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_91.cpp"

namespace leetcode_91 {
using std::vector;

TEST_CASE("1 [test_91]", "[test_91]") {
    static constexpr const char *const str{"12"};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("2 [test_91]", "[test_91]") {
    static constexpr const char *const str{"226"};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("3 [test_91]", "[test_91]") {
    static constexpr const char *const str{"0"};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("4 [test_91]", "[test_91]") {
    static constexpr const char *const str{"06"};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("5 [test_91]", "[test_91]") {
    static constexpr const char *const str{"10"};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("6 [test_91]", "[test_91]") {
    static constexpr const char *const str{"10011"};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}

TEST_CASE("7 [test_91]", "[test_91]") {
    static constexpr const char *const str{"012"};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.numDecodings(str));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP
