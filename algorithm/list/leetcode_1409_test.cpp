// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 链表
//@Description 链表中点,经典双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP

#include <catch_main.hpp>

#include "leetcode_1409.cpp"

namespace leetcode_1409 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_1409]", "[test_1409]") {
    const vector<int32_t> vec1{3, 1, 2, 1};
    constexpr const auto m{5};
    const vector<int32_t> result{2, 1, 2, 1};
    Solution solution;
    CHECK_THAT(result, Equals(solution.processQueries(vec1, m)));
}


}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_1409_TEST_HPP
