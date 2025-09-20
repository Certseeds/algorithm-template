// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_763.cpp"
#include <vector>
#include <string>

namespace leetcode_763 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_763]", "[test_763]") {
    Solution solution;
    static constexpr const char *const input{"ababcbacadefegdehijhklij"};
    const vector<int32_t> output{9, 7, 8};
    CHECK_THAT(output, Equals(solution.partitionLabels(input)));
}

TEST_CASE("2 [test_763]", "[test_763]") {
    Solution solution;
    static constexpr const char *const input{"eccbbbbdec"};
    const vector<int32_t> output{10};
    CHECK_THAT(output, Equals(solution.partitionLabels(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_763_TEST_HPP
