// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP

#include "leetcode_1160.cpp"
#include <catch_main.hpp>

namespace leetcode_1160 {

TEST_CASE("test case 1 {test_1160}", "{test_1160}") {
    const vector<string> input{"aaa", "bbb", "ccc"};
    const string chars{"aabbbcccc"};
    Solution solution;
    CHECK(6 == solution.countCharacters(input, chars));
}

TEST_CASE("test case 2 {test_1160}", "{test_1160}") {
    const vector<string> input{"cat", "bt", "hat", "tree"};
    const string chars{"atach"};
    Solution solution;
    CHECK(6 == solution.countCharacters(input, chars));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1160_TEST_HPP
