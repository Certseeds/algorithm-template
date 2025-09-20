// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container
//@Tag xor
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP

#include "leetcode_961.cpp"
#include <catch_main.hpp>

namespace leetcode_961 {

TEST_CASE("test case 1 {test_961}", "{test_961}") {
    static constexpr const std::array<int, 4> arr{
            1, 2, 3, 3
    };
    static constexpr const auto result{3};
    Solution solution;
    CHECK(result == solution.repeatedNTimes({arr.cbegin(), arr.cend()}));
}

TEST_CASE("test case 2 {test_961}", "{test_961}") {
    static constexpr const std::array<int, 10> arr{
            1, 0, 4, 4, 4, 4, 4, 5, 1, 4
    };
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.repeatedNTimes({arr.cbegin(), arr.cend()}));
}

TEST_CASE("test case 3 {test_961}", "{test_961}") {
    static constexpr const std::array<int, 10> arr{
            1, 9, 2, 9, 8, 9, 3, 9, 0, 9
    };
    static constexpr const auto result{9};
    Solution solution;
    CHECK(result == solution.repeatedNTimes({arr.cbegin(), arr.cend()}));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP
