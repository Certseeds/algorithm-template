// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_60.cpp"

namespace leetcode_60 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{3};
    static constexpr const char *const result{"213"};
    Solution solution;
    CHECK_THAT(result,Equals(solution.getPermutation(n, k)));
    CHECK_THAT(result,Equals(solution.getPermutation_rec_out(n, k)));
}

TEST_CASE("2 [test_60]", "[test_60]") {
    static constexpr const auto n{4}, k{9};
    static constexpr const char *const result{"2314"};
    Solution solution;
    CHECK_THAT(result,Equals(solution.getPermutation(n, k)));
    CHECK_THAT(result,Equals(solution.getPermutation_rec_out(n, k)));
}

TEST_CASE("3 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{1};
    static constexpr const char *const result{"123"};
    Solution solution;
    CHECK_THAT(result,Equals(solution.getPermutation(n, k)));
    CHECK_THAT(result,Equals(solution.getPermutation_rec_out(n, k)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP

