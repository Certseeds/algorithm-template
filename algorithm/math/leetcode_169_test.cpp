// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_169.cpp"

namespace leetcode_169 {

TEST_CASE("1 [test_169]", "[test_169]") {
    const vector<int32_t> input{3, 4, 3};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.majorityElement(input));
    CHECK(result == solution.majorityElement2(input));
}

TEST_CASE("2 [test_169]", "[test_169]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.majorityElement(input));
    CHECK(result == solution.majorityElement2(input));
}

TEST_CASE("3 [test_169]", "[test_169]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.majorityElement(input));
    CHECK(result == solution.majorityElement2(input));
}

TEST_CASE("4 [test_169]", "[test_169]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.majorityElement(input));
    CHECK(result == solution.majorityElement2(input));
}

TEST_CASE("5 [test_169]", "[test_169]") {
    const vector<int32_t> input{2, 2, 1, 1, 1, 2, 2};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.majorityElement(input));
    CHECK(result == solution.majorityElement2(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_169_TEST_HPP

