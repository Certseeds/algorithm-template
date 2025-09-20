// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 排序
//@Tag 模拟
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_1030.cpp"

namespace leetcode_1030 {
using std::vector;

bool check(const vector<vector<int32_t>> &input, int32_t rCenter, int32_t cCenter) {
    vector<int32_t> test{};
    for (const auto &point: input) {
        test.push_back(std::abs(rCenter - point[0]) + std::abs(cCenter - point[1]));
    }
    return std::is_sorted(test.cbegin(), test.cend());
}

TEST_CASE("test case 3-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{3}, rCenter{1}, cCenter{2};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 3-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{3}, rCenter{1}, cCenter{2};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 2-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{2}, rCenter{0}, cCenter{1};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 2-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{2}, cols{2}, rCenter{0}, cCenter{1};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 1-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{1}, cols{2}, rCenter{0}, cCenter{0};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 1-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{1}, cols{2}, rCenter{0}, cCenter{0};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 4-2 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{11}, cols{45}, rCenter{1}, cCenter{4};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrder(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}

TEST_CASE("test case 4-1 {test_1030}", "{test_1030}") {
    static constexpr const auto rows{11}, cols{45}, rCenter{1}, cCenter{4};
    Solution solution;
    const vector<vector<int32_t>> result{solution.allCellsDistOrderNLogN(rows, cols, rCenter, cCenter)};
    CHECK(check(result, rCenter, cCenter));
    CHECK(result.size() == rows * cols);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1030_TEST_HPP
