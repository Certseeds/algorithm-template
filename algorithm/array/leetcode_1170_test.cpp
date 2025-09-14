// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1170_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1170_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include "leetcode_1170.cpp"

namespace leetcode_1170 {
using std::vector;
using std::string;

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1170}", "{test_1170}") {
    const vector<string> queries{"cbd"};
    const vector<string> words{"tencent"};
    const vector<int32_t> output{0};
    Solution solution;
    CHECK_THAT(output, Equals(solution.numSmallerByFrequency(queries, words)));
}

TEST_CASE("test case 1-2 {test_1170}", "{test_1170}") {
    const vector<string> queries{"bbb", "cc"};
    const vector<string> words{"a", "aa", "aaa", "aaaa"};
    const vector<int32_t> output{1, 2};
    Solution solution;
    CHECK_THAT(output, Equals(solution.numSmallerByFrequency(queries, words)));
}

TEST_CASE("test case 1-3 {test_1170}", "{test_1170}") {
    const vector<string> queries{"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab",
                                 "bbabbaabb"};
    const vector<string> words{"aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab",
                               "aa"};
    const vector<int32_t> output{6, 1, 1, 2, 3, 3, 3, 1, 3, 2};
    Solution solution;
    CHECK_THAT(output, Equals(solution.numSmallerByFrequency(queries, words)));
}

TEST_CASE("test case 1-4 {test_1170}", "{test_1170}") {
    const vector<string> queries{"aabbabbb", "abbbabaa", "aabbbabaa", "aabba", "abb", "a", "ba", "aa", "ba",
                                 "baabbbaaaa", "babaa", "bbbbabaa"};
    const vector<string> words{"b", "aaaba", "aaaabba", "aa", "aabaabab", "aabbaaabbb", "ababb", "bbb", "aabbbabb",
                               "aab", "bbaaababba", "baaaaa"};
    const vector<int32_t> output{6, 5, 0, 6, 11, 11, 11, 8, 11, 0, 6, 6};
    Solution solution;
    CHECK_THAT(output, Equals(solution.numSmallerByFrequency(queries, words)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1170_TEST_HPP
