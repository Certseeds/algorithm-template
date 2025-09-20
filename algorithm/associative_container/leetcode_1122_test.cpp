// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag associative_container

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP

#include "leetcode_1122.cpp"
#include <catch_main.hpp>

namespace leetcode_1122 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1122}", "{test_1122}") {
    const vector<int32_t> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    const vector<int32_t> arr2{2, 1, 4, 3, 9, 6};
    const vector<int32_t> result{2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
    Solution solution;
    CHECK_THAT(result, Equals(solution.relativeSortArray(arr1, arr2)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1122_TEST_HPP
