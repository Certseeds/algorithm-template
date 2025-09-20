// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_29.cpp"

namespace leetcode_29 {

TEST_CASE("1 [test _29]", "[test _29]") {
    Solution solution;
    CHECK(solution.divide(std::numeric_limits<int32_t>::min(), -1) == std::numeric_limits<int32_t>::max());
    CHECK(solution.divide(std::numeric_limits<int32_t>::min(), 1) == std::numeric_limits<int32_t>::min());
    CHECK(solution.divide(std::numeric_limits<int32_t>::min(), 2) == -1073741824);
    CHECK(solution.divide(std::numeric_limits<int32_t>::min(), -2) == 1073741824);
    CHECK(solution.divide(10, 3) == 3);
    CHECK(solution.divide(7, -3) == -2);
    CHECK(solution.divide(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()) == 1);
    CHECK(solution.divide(-1010369383, -2147483648) == 0);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP
