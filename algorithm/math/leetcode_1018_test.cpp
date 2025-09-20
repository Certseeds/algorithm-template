// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag Math
//@Tag 数学
//@Tag 记忆化
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1018_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1018_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1018.cpp"

namespace leetcode_1018 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1018]", "[test_1018]") {
    const vector<int32_t> input{0, 1, 1};
    const vector<bool> result{true, false, false};
    Solution solution;
    CHECK_THAT(result, Equals(solution.prefixesDivBy5(input)));
}

TEST_CASE("2 [test_1018]", "[test_1018]") {
    const vector<int32_t> input{0, 1, 1};
    const vector<bool> result{true, false, false};
    Solution solution;
    CHECK_THAT(result, Equals(solution.prefixesDivBy5(input)));
}

TEST_CASE("3 [test_1018]", "[test_1018]") {
    const vector<int32_t> input{0, 1, 1};
    const vector<bool> result{true, false, false};
    Solution solution;
    CHECK_THAT(result, Equals(solution.prefixesDivBy5(input)));
}

}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1018_TEST_HPP

