// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_39.cpp"

namespace leetcode_39 {

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic test [test_39]", "[test_39]") {
    vector<int32_t> candidates{2, 3, 6, 7};
    const static constexpr auto target{7};
    const vector<vector<int32_t>> results{{7},
                                          {2, 2, 3}};
    Solution solution;
    CHECK_THAT(solution.combinationSum(candidates, target), UnorderedEquals(results));
}

TEST_CASE("basic test 2[test_39]", "[test_39]") {
    vector<int32_t> candidates{2, 3, 5};
    const static constexpr auto target{8};
    const vector<vector<int32_t>> results{{2, 3, 3},
                                          {2, 2, 2, 2},
                                          {3, 5}};
    Solution solution;
    CHECK_THAT(solution.combinationSum(candidates, target), UnorderedEquals(results));
}

TEST_CASE("basic test 3[test_39]", "[test_39]") {
    vector<int32_t> candidates{2};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{};
    Solution solution;
    CHECK_THAT(solution.combinationSum(candidates, target), UnorderedEquals(results));
}

TEST_CASE("basic test 4[test_39]", "[test_39]") {
    vector<int32_t> candidates{1};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{{1}};
    Solution solution;
    CHECK_THAT(solution.combinationSum(candidates, target), UnorderedEquals(results));
}

TEST_CASE("basic test 5[test_39]", "[test_39]") {
    vector<int32_t> candidates{1};
    const static constexpr auto target{2};
    const vector<vector<int32_t>> results{{1, 1}};
    Solution solution;
    CHECK_THAT(solution.combinationSum(candidates, target), UnorderedEquals(results));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP
