// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include <cstdint>
#include "leetcode_1104.cpp"

namespace leetcode_1104 {

using Catch::Matchers::Equals;
using std::vector;

TEST_CASE("test_case 1 [test_1104]", "[test_1104]") {
    Solution solution;
    static constexpr const auto input{14};
    const vector<int32_t> output{1, 3, 4, 14};
    CHECK_THAT(solution.pathInZigZagTree(input), Equals(output));
}

TEST_CASE("test_case 2 [test_1104]", "[test_1104]") {
    Solution solution;
    static constexpr const auto input{26};
    const vector<int32_t> output{1, 2, 6, 10, 26};
    CHECK_THAT(solution.pathInZigZagTree(input), Equals(output));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP
