// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag associative_container

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP

#include "leetcode_1078.cpp"
#include <catch_main.hpp>

namespace leetcode_1078 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1078}", "{test_1078}") {
    static constexpr const char *const text{"how are you indian mi fans do you like mi four i"};
    static constexpr const char *const fst{"mi"};
    static constexpr const char *const snd{"fans"};
    const vector<string> result{"do"};
    Solution solution;
    CHECK_THAT(result, Equals(solution.findOcurrences(text, fst, snd)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1078_TEST_HPP
