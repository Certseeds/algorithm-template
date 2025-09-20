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
//@Related 33

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_81_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_81_TEST_HPP

#include "leetcode_81.cpp"
#include <catch_main.hpp>

namespace leetcode_81 {
using std::vector;

TEST_CASE("1 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 0, 1, 2};
    static constexpr const auto target{8};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("2 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 0, 1, 2};
    static constexpr const auto target{9};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("3 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 0, 1, 2};
    static constexpr const auto target{3};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}

TEST_CASE("4 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
    static constexpr const auto target{2};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("5 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2};
    static constexpr const auto target{7};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("6 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2};
    static constexpr const auto target{24};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}

TEST_CASE("7 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 1, 2};
    static constexpr const auto target{13};
    Solution solution;
    CHECK(solution.search(input, target));

}

TEST_CASE("8 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2};
    static constexpr const auto target{1};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("9 [test_81]", "[test_81]") {
    const vector<int32_t> input{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2};
    static constexpr const auto target{0};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("10 [test_81]", "[test_81]") {
    const vector<int32_t> input{
            49, 64, 66, 67, 68, 69, 71, 74, 76, 78, 83, 86, 91, 93, 94, 96, 97, 106, 113, 11,
            6, 118, 119, 120, 121, 122, 123, 125, 126, 129, 131, 132, 141, 142, 144, 146, 14,
            7, 156, 157, 167, 170, 171, 172, 178, 183, 185, 188, 191, 192, 196, 209, 210, 211,
            213, 221, 226, 228, 230, 233, 235, 236, 237, 242, 243, 246, 247, 250, 251, 252,
            256, 261, 266, 267, 272, 275, 286, 289, 291, 296, 299,
            0, 7, 8, 9, 14, 16, 21, 35, 37, 41, 44, 45, 47, 48};
    static constexpr const auto target{35};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("11 [test_81]", "[test_81]") {
    const vector<int32_t> input{2, 5, 6, 0, 0, 1, 2};
    static constexpr const auto target{0};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("12 [test_81]", "[test_81]") {
    const vector<int32_t> input{2, 5, 6, 0, 0, 1, 2};
    static constexpr const auto target{3};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}

TEST_CASE("13 [test_81]", "[test_81]") {
    const vector<int32_t> input{2, 2, 2, 3, 2, 2, 2};
    static constexpr const auto target{3};
    Solution solution;
    CHECK(solution.search(input, target));
}


TEST_CASE("14 [test 81]", "[test 81]") {
    const vector<int32_t> input{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    static constexpr const auto target{2};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("15 [test 81]", "[test 81]") {
    const vector<int32_t> input{1, 0, 1, 1, 1};
    static constexpr const auto target{0};
    Solution solution;
    CHECK(solution.search(input, target));
}

TEST_CASE("16 [test 81]", "[test 81]") {
    const vector<int32_t> input{1, 1};
    static constexpr const auto target{0};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}

TEST_CASE("17 [test 81]", "[test 81]") {
    const vector<int32_t> input{1, 1, 1, 3};
    static constexpr const auto target{2};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}

TEST_CASE("18 [test 81]", "[test 81]") {
    const vector<int32_t> input{1, 0, 1, 1, 1};
    static constexpr const auto target{2};
    Solution solution;
    CHECK_FALSE(solution.search(input, target));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_81_TEST_HPP
