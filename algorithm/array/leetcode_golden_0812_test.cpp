// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_golden_0812.cpp"

namespace leetcode_golden_0812 {
using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_golden_0812]", "[test_golden_0812]") {
    auto sol = Solution();
    constexpr const int32_t input{1};
    const std::vector<std::vector<std::string>> result{{"Q"}};
    CHECK_THAT(result, UnorderedEquals(sol.solveNQueen(input)));
}

TEST_CASE("test case 2 3 [test_golden_0812]", "[test_golden_0812]") {
    auto sol = Solution();
    CHECK_THAT(std::vector<std::vector<std::string>>{}, UnorderedEquals(sol.solveNQueen(2)));
    CHECK_THAT(std::vector<std::vector<std::string>>{}, UnorderedEquals(sol.solveNQueen(3)));
}

TEST_CASE("test case 5 [test_golden_0812]", "[test_golden_0812]") {
    auto sol = Solution();
    CHECK_THAT((std::vector<std::vector<std::string>>{{
                                                              ".Q..",
                                                              "...Q",
                                                              "Q...",
                                                              "..Q.",

                                                      },
                                                      {
                                                              "..Q.",
                                                              "Q...",
                                                              "...Q",
                                                              ".Q..",

                                                      }}),
               UnorderedEquals(sol.solveNQueen(4)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_golden_0812_TEST_HPP
