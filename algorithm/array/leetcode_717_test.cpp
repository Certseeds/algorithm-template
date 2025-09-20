// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_717.cpp"

namespace leetcode_717 {
using std::vector;

TEST_CASE("test case 1 [test_717]", "[test_717]") {
    vector<int32_t> input{1, 0, 0};
    Solution solution;
    CHECK(solution.isOneBitCharacter(input));
}

TEST_CASE("test case 2 [test_717]", "[test_717]") {
    vector<int32_t> input{1, 1, 1, 0};
    Solution solution;
    CHECK_FALSE(solution.isOneBitCharacter(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP
