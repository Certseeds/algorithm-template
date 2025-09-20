// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag divide_merge
//@Tag 分治
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day5
//@Plan 数据结构入门 Day1
//@Plan 剑指OfferII-I Day09
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_53.cpp"

namespace leetcode_53 {
using std::string;
using std::vector;

TEST_CASE("1 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    static constexpr const int32_t output{6};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}

TEST_CASE("2 [test_53]", "[test_53]") {
    const vector<int32_t> input{1};
    static constexpr const int32_t output{1};
    Solution solution;
    CHECK(solution.maxSubArray2(input) == output);
    CHECK(solution.maxSubArray(input) == output);
}

TEST_CASE("3 [test_53]", "[test_53]") {
    const vector<int32_t> input{0};
    static constexpr const int32_t output{0};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}

TEST_CASE("4 [test_53]", "[test_53]") {
    const vector<int32_t> input{-1};
    static constexpr const int32_t output{-1};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}

TEST_CASE("5 [test_53]", "[test_53]") {
    const vector<int32_t> input{-100000};
    static constexpr const int32_t output{-100000};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}

TEST_CASE("6 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, -1};
    static constexpr const int32_t output{-1};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}

TEST_CASE("7 [test_53]", "[test_53]") {
    const vector<int32_t> input{5, 4, -1, 7, 8};
    static constexpr const int32_t output{23};
    Solution solution;
    CHECK(solution.maxSubArray(input) == output);
    CHECK(solution.maxSubArray2(input) == output);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP
