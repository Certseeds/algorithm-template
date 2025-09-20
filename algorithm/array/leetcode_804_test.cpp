// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_804.cpp"

namespace leetcode_804 {
TEST_CASE("test case 1 [test_804]", "[test_804]") {
    static constexpr const std::array<const char *const, 4> inputs{"gin", "zen", "gig", "msg"};
    static constexpr const auto result{2};
    std::vector<std::string> input_vec{inputs.cbegin(), inputs.cend()};
    Solution solution;
    CHECK(result == solution.uniqueMorseRepresentations(input_vec));
}

TEST_CASE("test case 2 [test_804]", "[test_804]") {
    static constexpr const std::array<const char *const, 1> inputs{"a"};
    static constexpr const auto result{1};
    std::vector<std::string> input_vec{inputs.cbegin(), inputs.cend()};
    Solution solution;
    CHECK(result == solution.uniqueMorseRepresentations(input_vec));
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_804_TEST_HPP
