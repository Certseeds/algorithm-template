// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1408_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1408_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_1408.cpp"
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace leetcode_1408 {

using Catch::Matchers::UnorderedEquals;

TEST_CASE("0 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"evl", "evlat", "kes", "lwkesz", "ckk", "eylwkesz", "efuw", "ickkw", "xnc", "evlon",
                                "qsmd", "nmlwkeszk", "uyh", "xncme", "auze", "ixncmeqc"};
    const vector<string> output{"evl", "kes", "lwkesz", "ckk", "xnc", "xncme"};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("1 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"business", "bus", "assassin", "ass", "we", "can"};
    const vector<string> output{"bus", "ass"};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("2 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"tprefix", "prefix", "fix"};
    const vector<string> output{"prefix", "fix"};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("3 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"what", "the", "hell"};
    const vector<string> output{};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("4 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"mass", "as", "hero", "superhero"};
    const vector<string> output{"hero", "as"};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("5 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"leetcode", "et", "code"};
    const vector<string> output{"et", "code"};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}

TEST_CASE("6 [test_1408]", "[test_1408]") {
    Solution solution;
    const vector<string> inputs{"blue", "green", "bu"};
    const vector<string> output{};
    CHECK_THAT(output, UnorderedEquals(solution.stringMatching(inputs)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_STRING_LEETCODE_1408_TEST_HPP
