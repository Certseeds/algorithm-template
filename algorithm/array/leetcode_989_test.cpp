// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP

#include "leetcode_989.cpp"
#include <catch_main.hpp>

namespace leetcode_989 {
using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_989}", "{test_989}") {
    auto sol = Solution();
    std::vector<int32_t> fst{1, 3, 2, 1};
    static constexpr const auto k{34};
    std::vector<int32_t> result{1, 3, 5, 5};
    CHECK_THAT(result, Equals(sol.addToArrayForm(fst, k)));
}

TEST_CASE("test case 2 {test_989}", "{test_989}") {
    auto sol = Solution();
    std::vector<int32_t> fst{2, 7, 4};
    static constexpr const auto k{181};
    std::vector<int32_t> result{4, 5, 5};
    CHECK_THAT(result, Equals(sol.addToArrayForm(fst, k)));
}

TEST_CASE("test case 3 {test_989}", "{test_989}") {
    auto sol = Solution();
    std::vector<int32_t> fst{2, 1, 5};
    static constexpr const auto k{806};
    std::vector<int32_t> result{1, 0, 2, 1};
    CHECK_THAT(result, Equals(sol.addToArrayForm(fst, k)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP
