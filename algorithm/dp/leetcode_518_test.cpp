// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day20

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP

#include <catch_main.hpp>

#include "leetcode_518.cpp"

namespace leetcode_518 {
using std::vector;

TEST_CASE("1 [test_518]", "[test_518]") {
    static constexpr const auto amount{std::array<int32_t, 6>{1, 2, 3, 4, 5, 6}};
    const vector<int32_t> coins{1, 2, 5};
    static constexpr const auto result{std::array<int32_t, 6>{1, 2, 2, 3, 4, 5}};
    Solution solution;
    for (size_t i{0}; i < amount.size(); i++) {
        CHECK(result[i] == solution.change(amount[i], coins));
        CHECK(result[i] == solution.change2(amount[i], coins));
    }
}

TEST_CASE("3 [test_518]", "[test_518]") {
    static constexpr const auto amount{10};
    const vector<int32_t> coins{10};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.change(amount, coins));
    CHECK(result == solution.change2(amount, coins));
}

TEST_CASE("2 [test_518]", "[test_518]") {
    static constexpr const auto amount{3};
    const vector<int32_t> coins{2};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.change(amount, coins));
    CHECK(result == solution.change2(amount, coins));
}

TEST_CASE("1s [test_518]", "[test_518]") {
    static constexpr const auto amount{std::array<int32_t, 6>{1, 2, 3, 4, 5, 6}};
    const vector<int32_t> coins{1};
    static constexpr const auto result{1};
    Solution solution;
    for (size_t i{0}; i < amount.size(); i++) {
        CHECK(result == solution.change(amount[i], coins));
        CHECK(result == solution.change2(amount[i], coins));
    }
}

TEST_CASE("5 [test_518]", "[test_518]") {
    static constexpr const auto amount{4};
    const vector<int32_t> coins{1, 2, 3};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.change(amount, coins));
    CHECK(result == solution.change2(amount, coins));
}


}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_518_TEST_CPP
