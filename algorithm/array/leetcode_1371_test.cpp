// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

#include "leetcode_1371.cpp"

namespace leetcode_1371 {
using std::vector;

TEST_CASE("test case 1-1 {test_1371}", "{test_1371}") {
    constexpr const char *const input{"leetcodeisgreat"};
    constexpr const auto output{5};
    Solution solution;
    CHECK(output == solution.findTheLongestSubstring(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1371_TEST_HPP
