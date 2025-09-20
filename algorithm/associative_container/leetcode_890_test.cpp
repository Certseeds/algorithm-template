// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag array as hashmap
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP

#include "leetcode_890.cpp"
#include <catch_main.hpp>

namespace leetcode_890 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_890}", "{test_890}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    static constexpr const char *const pattern{"abb"};
    static constexpr const std::array<const char *const, 2> result{"mee", "aqq"};
    Solution solution;
    CHECK_THAT(
            (vector<string>{result.cbegin(), result.cend()}),
            Equals(solution.findAndReplacePattern({input.cbegin(), input.cend()}, pattern))
    );

}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_890_TEST_HPP
