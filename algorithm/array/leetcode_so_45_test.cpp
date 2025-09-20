// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Description 自定义比较函数
//@Plan 剑指OfferII-I Day16
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP

#include "leetcode_so_45.cpp"
#include <catch_main.hpp>

namespace leetcode_so_45 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_so_45]", "[test_so_45]") {
    auto sol = Solution();
    std::vector<int32_t> input{10, 2};
    static constexpr const char *const output{"102"};
    CHECK_THAT(output, Equals(sol.minNumber(input)));
}

TEST_CASE("test case 2 [test_so_45]", "[test_so_45]") {
    auto sol = Solution();
    std::vector<int32_t> input{3, 30, 34, 5, 9};
    static constexpr const char *const output{"3033459"};
    CHECK_THAT(output, Equals(sol.minNumber(input)));
}

TEST_CASE("test case 3 [test_so_45]", "[test_so_45]") {
    auto sol = Solution();
    std::vector<int32_t> input{12, 121};
    static constexpr const char *const output{"12112"};
    CHECK_THAT(output, Equals(sol.minNumber(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP
