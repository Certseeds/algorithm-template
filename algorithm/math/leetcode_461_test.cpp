// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_461_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_461_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include "leetcode_461.cpp"

namespace leetcode_461 {

TEST_CASE("1 [test_461]", "[test_461]") {
    static constexpr const auto inputX{1}, inputY{4};
    static constexpr const auto result{2};
    Solution solution;
    CHECK(result == solution.hammingDistance(inputX, inputY));
}

TEST_CASE("2 [test_461]", "[test_461]") {
    static constexpr const auto inputX{3}, inputY{1};
    static constexpr const auto result{1};
    Solution solution;
    CHECK(result == solution.hammingDistance(inputX, inputY));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_461_TEST_HPP

