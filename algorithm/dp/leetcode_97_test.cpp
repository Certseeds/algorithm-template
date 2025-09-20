// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag DP
//@Tag 动态规划


#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_97.cpp"

namespace leetcode_97 {
using std::string;

TEST_CASE("1 [test_97]", "[test_97]") {
    static constexpr const char *const s1{"aabcc"}, *const s2{"dbbca"}, *const s3{"aadbbcbcac"};
    Solution solution;
    CHECK(solution.isInterleave(s1, s2, s3));
}

TEST_CASE("2 [test_97]", "[test_97]") {
    static constexpr const char *const s1{"aabcc"}, *const s2{"dbbca"}, *const s3{"aadbbbaccc"};
    Solution solution;
    CHECK_FALSE(solution.isInterleave(s1, s2, s3));
}

TEST_CASE("3 [test_97]", "[test_97]") {
    static constexpr const char *const s1{""}, *const s2{""}, *const s3{""};
    Solution solution;
    CHECK(solution.isInterleave(s1, s2, s3));
}

TEST_CASE("4 [test_97]", "[test_97]") {
    static constexpr const char *const s1{
            "abababababababababababababababababababababababababababababababababababababababababababababababababbb"},
            *const s2{
            "babababababababababababababababababababababababababababababababababababababababababababababababaaaba"},
            *const s3{
            "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"};
    Solution solution;
    CHECK_FALSE(solution.isInterleave(s1, s2, s3));
}


}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
