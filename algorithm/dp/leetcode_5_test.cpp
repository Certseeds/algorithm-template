// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day17
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_5.cpp"

namespace leetcode_5 {

using std::string;
using std::vector;

template<typename Type, size_t length>
constexpr size_t arr_length(const Type (&)[length]) {
    return length;
}

template<size_t length>
constexpr size_t arr_length(const char (&)[length]) {
    return length - 1;
}

TEST_CASE("1 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"babad"};
    static constexpr const char result[]{"bab"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
}

TEST_CASE("2 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cbbc"};
    static constexpr const char result[]{"cbbc"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

TEST_CASE("2_  [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cbbd"};
    static constexpr const char result[]{"bb"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

TEST_CASE("3 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"cb"};
    static constexpr const char result[]{"c"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
}

TEST_CASE("4 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"c"};
    static constexpr const char result[]{"c"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}


TEST_CASE("5 [test_5]", "[test_5]") {
    static constexpr const auto *const input{""};
    static constexpr const char result[]{""};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

TEST_CASE("6 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"ac"};
    static constexpr const char result[]{"a"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

TEST_CASE("7 [test_5]", "[test_5]") {
    static constexpr const auto *const input{"aaaaa"};
    static constexpr const char result[]{"aaaaa"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

TEST_CASE("8 [test_5]", "[test_5]") {
    static constexpr const auto *const input{
            "mozblnzrszxtdjmwvgeovtxoftpcsbnjryogrnibiiqfexljlfikfcxvrzrpfvugtdjrlkgvkmrqgeltifdehsewpdhpjpnuobmuozopmglnocqcozvratjpzrklexqdeuvvzfjkuknkkoynxptrgtzadmpfdkphfjhdulhzncoofmmrwqjxeyhodfavcgpjmohohuztezdxegqzbaaobzrqptuqsvwnfdneyccbkgkjafztytwuppvleukdqqzyeiltsvoqbxupbasiityganofxijucwzqgtdyxljociwwjdrnfnfbwyymmvbuvbrdnvcubzkohknbsneutrcukfiqqhfviqdsbtrldipenqifdcrenpuyaqvkparycksurhbtjppwhezbcgocamurdawimkzzkmiwadrumacogcbzehwppjtbhruskcyrapkvqayupnercdfiqnepidlrtbsdqivfhqqifkucrtuensbnkhokzbucvndrbvubvmmyywbfnfnrdjwwicojlxydtgqzwcujixfonagytiisabpuxbqovstlieyzqqdkuelvppuwtytzfajkgkbccyendfnwvsqutpqrzboaabzqgexdzetzuhohomjpgcvafdohyexjqwrmmfoocnzhludhjfhpkdfpmdaztgrtpxnyokknkukjfzvvuedqxelkrzpjtarvzocqconlgmpozoumbounpjphdpweshedfitlegqrmkvgklrjdtguvfprzrvxcfkifljlxefqiibinrgoyrjnbscptfoxtvoegvwmjdtxzsrznlbzom"};
    static constexpr const char result[]{
            "mozblnzrszxtdjmwvgeovtxoftpcsbnjryogrnibiiqfexljlfikfcxvrzrpfvugtdjrlkgvkmrqgeltifdehsewpdhpjpnuobmuozopmglnocqcozvratjpzrklexqdeuvvzfjkuknkkoynxptrgtzadmpfdkphfjhdulhzncoofmmrwqjxeyhodfavcgpjmohohuztezdxegqzbaaobzrqptuqsvwnfdneyccbkgkjafztytwuppvleukdqqzyeiltsvoqbxupbasiityganofxijucwzqgtdyxljociwwjdrnfnfbwyymmvbuvbrdnvcubzkohknbsneutrcukfiqqhfviqdsbtrldipenqifdcrenpuyaqvkparycksurhbtjppwhezbcgocamurdawimkzzkmiwadrumacogcbzehwppjtbhruskcyrapkvqayupnercdfiqnepidlrtbsdqivfhqqifkucrtuensbnkhokzbucvndrbvubvmmyywbfnfnrdjwwicojlxydtgqzwcujixfonagytiisabpuxbqovstlieyzqqdkuelvppuwtytzfajkgkbccyendfnwvsqutpqrzboaabzqgexdzetzuhohomjpgcvafdohyexjqwrmmfoocnzhludhjfhpkdfpmdaztgrtpxnyokknkukjfzvvuedqxelkrzpjtarvzocqconlgmpozoumbounpjphdpweshedfitlegqrmkvgklrjdtguvfprzrvxcfkifljlxefqiibinrgoyrjnbscptfoxtvoegvwmjdtxzsrznlbzom"};
    Solution solution;
    CHECK(arr_length(result) == solution.longestPalindrome(input).size());
    CHECK(result == solution.longestPalindrome(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_5_TEST_CPP
