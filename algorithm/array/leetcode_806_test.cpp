// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_806.cpp"
#include <array>

using Catch::Matchers::Equals;

namespace leetcode_806 {
using std::array;

TEST_CASE("test case 1 [test_806]", "[test_806]") {
    static constexpr const array<int, 26> inputs{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                 10, 10, 10};
    static constexpr const char *const str{"abcdefghijklmnopqrstuvwxyz"};
    static constexpr const auto begin{3}, end{60};
    Solution solution;
    CHECK_THAT(
            (std::vector<int32_t>{begin, end}),
            Equals(solution.numberOfLines({inputs.begin(), inputs.end()}, str))
    );
}

TEST_CASE("test case 2 [test_806]", "[test_806]") {
    static constexpr const array<int, 26> inputs{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                 10, 10, 10, 10, 10, 10,
                                                 10, 10, 10};
    static constexpr const char *const str{"bbbcccdddaaa"};
    static constexpr const auto begin{2}, end{4};
    Solution solution;
    CHECK_THAT(
            (std::vector<int32_t>{begin, end}),
            Equals(solution.numberOfLines({inputs.begin(), inputs.end()}, str))
    );
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP
