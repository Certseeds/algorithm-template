// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day2
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1.cpp"

namespace leetcode_1 {
using std::vector;


using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_1]", "[test_1]") {
    const vector<int32_t> vec{2, 7, 11, 15};
    auto clas = Solution();
    const auto result = clas.twoSum(vec, 9);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({0, 1}));
    }
}

TEST_CASE("basic tests 2 [test_1]", "[test_1]") {
    const vector<int32_t> vec{3, 2, 4};
    auto clas = Solution();
    const auto result = clas.twoSum(vec, 6);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({1, 2}));
    }
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1_TEST_HPP
