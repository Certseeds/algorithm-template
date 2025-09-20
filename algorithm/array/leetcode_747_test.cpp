// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_747.cpp"

namespace leetcode_747 {
using std::vector;

TEST_CASE("test case 2 [test_747]", "[test_747]") {
    vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto result{-1};
    Solution solution;
    CHECK(result == solution.dominantIndex(input));
}

TEST_CASE("test case 1 [test_747]", "[test_747]") {
    vector<int32_t> input{3, 6, 1, 0};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.dominantIndex(input));
}


TEST_CASE("test case 3 [test_747]", "[test_747]") {
    vector<int32_t> input{1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.dominantIndex(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP
