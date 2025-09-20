// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP

#include <catch_main.hpp>
#include <vector>
#include "leetcode_849.cpp"

namespace leetcode_849 {
TEST_CASE("test case 1 [test_849]", "[test_849]") {
    Solution solution;
    const vector<int32_t> inputs{1, 0, 0, 0, 1, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == solution.maxDistToClosest(inputs));
}

TEST_CASE("test case 2 [test_849]", "[test_849]") {
    Solution solution;
    const vector<int32_t> inputs{1, 0, 0, 0};
    static constexpr const auto result{3};
    CHECK(result == solution.maxDistToClosest(inputs));
}

TEST_CASE("test case 3 [test_849]", "[test_849]") {
    Solution solution;
    const vector<int32_t> inputs{0, 0, 0, 0, 1};
    static constexpr const auto result{4};
    CHECK(result == solution.maxDistToClosest(inputs));
}

TEST_CASE("test case 4 [test_849]", "[test_849]") {
    Solution solution;
    const vector<int32_t> inputs{0, 1};
    static constexpr const auto result{1};
    CHECK(result == solution.maxDistToClosest(inputs));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_849_TEST_HPP
