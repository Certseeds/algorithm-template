// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_883.cpp"

namespace leetcode_883 {
using std::vector;
using Catch::Matchers::Equals;

TEST_CASE("1 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{1, 2}, {3, 4}};
    static constexpr const auto output{17};
    Solution solution;
    CHECK(output == solution.projectionArea(input));
}

TEST_CASE("2 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{2}};
    static constexpr const auto output{5};
    Solution solution;
    CHECK(output == solution.projectionArea(input));
}

TEST_CASE("3 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{1, 0}, {0, 2}};
    static constexpr const auto output{8};
    Solution solution;
    CHECK(output == solution.projectionArea(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP

