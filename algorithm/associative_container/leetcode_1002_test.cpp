// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag xor
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP

#include "leetcode_1002.cpp"
#include <catch_main.hpp>

namespace leetcode_1002 {

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 3> arr{
            "bella", "label", "roller"
    };
    static constexpr const std::array<const char *const, 3> result{
            "e", "l", "l"
    };
    Solution solution;
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(solution.commonChars({arr.cbegin(), arr.cend()}))
    );

}

TEST_CASE("test case 2 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 3> arr{
            "cool", "lock", "cook"
    };
    static constexpr const std::array<const char *const, 2> result{
            "c", "o"
    };
    Solution solution;
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(solution.commonChars({arr.cbegin(), arr.cend()}))
    );

}

TEST_CASE("test case 3 {test_1002}", "{test_1002}") {
    static constexpr const std::array<const char *const, 8> arr{
            "acabcddd", "bcbdbcbd", "baddbadb", "cbdddcac", "aacbcccd", "ccccddda", "cababaab", "addcaccd"
    };
    static constexpr const std::array<const char *const, 0> result{};
    Solution solution;
    CHECK_THAT((vector<string>{result.cbegin(), result.cend()}),
               Equals(solution.commonChars({arr.cbegin(), arr.cend()}))
    );

}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1002_TEST_HPP
