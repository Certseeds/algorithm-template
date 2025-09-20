// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level middle

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_TEST_HPP

#include "leetcode_33.cpp"
#include <catch_main.hpp>

namespace leetcode_33 {

TEST_CASE("1 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 0, 1, 2};
    static constexpr const auto target{8};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("2 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 0, 1, 2};
    static constexpr const auto target{9};
    static constexpr const auto result{5};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("3 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 0, 1, 2};
    static constexpr const auto target{3};
    static constexpr const auto result{-1};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("4 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
    static constexpr const auto target{2};
    static constexpr const auto result{10};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("5 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2};
    static constexpr const auto target{7};
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("6 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2};
    static constexpr const auto target{24};
    static constexpr const auto result{-1};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("7 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 1, 2};
    static constexpr const auto target{13};
    static constexpr const auto result{9};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("8 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2};
    static constexpr const auto target{1};
    static constexpr const auto result{13};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("9 [test_33]", "[test_33]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2};
    static constexpr const auto target{0};
    static constexpr const auto result{13};
    Solution solution;
    CHECK(result == solution.search(input, target));
}

TEST_CASE("10 [test_33]", "[test_33]") {
    const vector<int32_t> input{
            49, 64, 66, 67, 68, 69, 71, 74, 76, 78, 83, 86, 91, 93, 94, 96, 97, 106, 113, 11,
            6, 118, 119, 120, 121, 122, 123, 125, 126, 129, 131, 132, 141, 142, 144, 146, 14,
            7, 156, 157, 167, 170, 171, 172, 178, 183, 185, 188, 191, 192, 196, 209, 210, 211,
            213, 221, 226, 228, 230, 233, 235, 236, 237, 242, 243, 246, 247, 250, 251, 252,
            256, 261, 266, 267, 272, 275, 286, 289, 291, 296, 299,
            0, 7, 8, 9, 14, 16, 21, 35, 37, 41, 44, 45, 47, 48};
    static constexpr const auto target{35};
    static constexpr const auto result{88};
    Solution solution;
    CHECK(result == solution.search(input, target));
}
}


#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_33_TEST_HPP
