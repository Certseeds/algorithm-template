// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_372.cpp"

namespace leetcode_372 {

TEST_CASE("1 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2};
    const vector<int32_t> inputB{3};
    static constexpr const auto result{8};
    Solution solution;
    CHECK(result == solution.superPow(inputA, inputB));
}

TEST_CASE("2 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2};
    const vector<int32_t> inputB{1, 0};
    static constexpr const auto result{1024};
    Solution solution;
    CHECK(result == solution.superPow(inputA, inputB));
}

TEST_CASE("3 [test_372]", "[test_372]") {
    static constexpr const auto inputA{1};
    const vector<int32_t> inputB{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.superPow(inputA, inputB));
}

TEST_CASE("4 [test_372]", "[test_372]") {
    static constexpr const auto inputA{2147483647};
    const vector<int32_t> inputB{2, 0, 0};
    static constexpr const auto result{1198};
    Solution solution;
    CHECK(result == solution.superPow(inputA, inputB));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_372_TEST_HPP

