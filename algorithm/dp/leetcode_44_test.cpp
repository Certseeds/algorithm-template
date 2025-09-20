// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_44.cpp"

namespace leetcode_44 {
using std::string;


TEST_CASE("double empty [test_44]", "[test_44]") {
    Solution solution;
    CHECK(solution.isMatch("", "*"));
}

TEST_CASE("test 1 [test_44]", "[test_44]") {
    Solution solution;
    CHECK_FALSE(solution.isMatch("aa", "a"));
}


TEST_CASE("test 2 [test_44]", "[test_44]") {
    Solution solution;
    CHECK(solution.isMatch("aa", "*"));
}

TEST_CASE("? [test_44]", "[test_44]") {
    Solution solution;
    CHECK_FALSE(solution.isMatch("cb", "*a"));
}


TEST_CASE("* can match '' or any string [test_44]", "[test_44]") {
    Solution solution;
    CHECK(solution.isMatch("adceb", "a*b"));
}

TEST_CASE("both * and ? [test_44]", "[test_44]") {
    Solution solution;
    CHECK_FALSE(solution.isMatch("acdcb", "a*c?b"));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP
