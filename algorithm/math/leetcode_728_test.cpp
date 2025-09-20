// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_728.cpp"

namespace leetcode_728 {
using Catch::Matchers::Equals;

TEST_CASE("1 [test_728]", "[test_728]") {
    static constexpr const auto left{1}, right{22};
    const vector<int32_t> results{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    Solution solution;
    CHECK_THAT(results, Equals(solution.selfDividingNumbers(left, right)));
}

TEST_CASE("2 [test_728]", "[test_728]") {
    static constexpr const auto left{47}, right{85};
    const vector<int32_t> results{48, 55, 66, 77};
    Solution solution;
    CHECK_THAT(results, Equals(solution.selfDividingNumbers(left, right)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP

