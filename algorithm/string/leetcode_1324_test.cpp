// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_1324.cpp"
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <array>

namespace leetcode_1324 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1324]", "[test_1324]") {
    Solution solution;
    constexpr const char *const input{"HOW ARE YOU INDIAN MI FANS"};
    constexpr const std::array<const char *const, 6> arr{"HAYIMF",
                                                         "ORONIA",
                                                         "WEUD N",
                                                         "   I S",
                                                         "   A",
                                                         "   N"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, Equals(solution.printVertically(input)));
}

TEST_CASE("2 [test_1324]", "[test_1324]") {
    Solution solution;
    constexpr const char *const input{"3z4"};
    constexpr const std::array<const char *const, 3> arr{"3", "z", "4"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, Equals(solution.printVertically(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_CPP
