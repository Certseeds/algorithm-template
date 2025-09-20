// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组
//@Tag 二分搜索
//@Plan 数据结构基础 Day4
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_238.cpp"

namespace leetcode_238 {
using std::vector;

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_238}", "{test_238}") {
    const vector<int32_t> input{1, 4, 7, 11, 15};
    const vector<int32_t> result{4620, 1155, 660, 420, 308};
    Solution solution;
    CHECK_THAT(result, Equals(solution.productExceptSelf(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_238_TEST_HPP
