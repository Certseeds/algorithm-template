// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag Trie
//@Tag 字典树
//@Plan 动态规划入门 Day9
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_139.cpp"

namespace leetcode_139 {
using std::vector;
using std::string;

TEST_CASE("1 [test_139]", "[test_139]") {
    static constexpr const char *const input{"leetcode"};
    static constexpr const std::array<const char *const, 2> wordDict{"leet", "code"};
    Solution solution;
    CHECK(solution.wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}

TEST_CASE("2 [test_139]", "[test_139]") {
    static constexpr const char *const input{"applepenapple"};
    static constexpr const std::array<const char *const, 2> wordDict{"apple", "pen"};
    Solution solution;
    CHECK(solution.wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}

TEST_CASE("3 [test_139]", "[test_139]") {
    static constexpr const char *const input{"catsandog"};
    static constexpr const std::array<const char *const, 5> wordDict{"cats", "dog", "sand", "and", "cat"};
    Solution solution;
    CHECK_FALSE(solution.wordBreak(input, {std::cbegin(wordDict), std::cend(wordDict)}));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_139_TEST_CPP
