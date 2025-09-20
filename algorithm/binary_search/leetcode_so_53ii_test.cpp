// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag binary-search
//@Tag 二分搜索

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP

#include "leetcode_so_53ii.cpp"
#include <catch_main.hpp>

namespace leetcode_so_53ii {
using std::vector;

TEST_CASE("test case 1 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.missingNumber(input));
}

TEST_CASE("test case 2 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    Solution solution;
    CHECK(result == solution.missingNumber(input));
}

TEST_CASE("test case 3 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0, 1};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.missingNumber(input));
}

TEST_CASE("test case 4 [test_so_53ii]", "[test_so_53ii]") {
    const vector<int32_t> input{0};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.missingNumber(input));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_SO_53II_HPP
