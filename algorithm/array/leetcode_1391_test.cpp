// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2023-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

#include "leetcode_1391.cpp"

namespace leetcode_1391 {
using std::vector;

TEST_CASE("test case 1-1 {test_1391}", "{test_1391}") {
    vector<vector<int>> input{
            {2, 4, 3},
            {6, 5, 2},
    };
    Solution solution;
    CHECK(solution.hasValidPath(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP
