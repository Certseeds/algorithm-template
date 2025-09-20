// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_136.cpp"

namespace leetcode_136 {

using Catch::Matchers::Equals;

TEST_CASE("1 [test_136]", "[test_136]") {
    const vector<int32_t> input{3, 4, 3};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.singleNumber(input));
}

TEST_CASE("2 [test_136]", "[test_136]") {
    const vector<int32_t> input{1, 1, 2, 2, 3, 3, 4};
    static constexpr const auto result{4};
    Solution solution;
    CHECK(result == solution.singleNumber(input));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_136_TEST_HPP

