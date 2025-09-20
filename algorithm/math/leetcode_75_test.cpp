// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_75.cpp"

namespace leetcode_75 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_75]", "[test_75]") {
    const vector<int32_t> input{2, 0, 1, 2, 2, 2, 0, 0, 0, 0, 1, 1};
    const vector<int32_t> result{0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2};
    vector<int32_t> input_v{input};
    Solution solution;
    solution.sortColors(input_v);
    CHECK_THAT(result, Equals(input_v));
}

TEST_CASE("2 [test_75]", "[test_75]") {
    const vector<int32_t> input{2, 0, 1};
    const vector<int32_t> result{0, 1, 2};
    vector<int32_t> input_v{input};
    Solution solution;
    solution.sortColors(input_v);
    CHECK_THAT(result, Equals(input_v));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_75_TEST_HPP
