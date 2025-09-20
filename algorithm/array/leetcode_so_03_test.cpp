// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
//@Plan 剑指OfferII-I Day04
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP

#include "leetcode_so_03.cpp"
#include <catch_main.hpp>

namespace leetcode_so_03 {

TEST_CASE("test case 1 [test_so_03]", "[test_so_03]") {
    auto sol = Solution();
    std::vector<int32_t> input{1, 2, 2, 3, 1};
    std::vector<int32_t> input2{1, 2, 2, 3, 1};
    std::vector<int32_t> input3{1, 2, 2, 3, 1};
    static constexpr const auto resultOne{1}, resultTwo{2};
    CHECK(resultOne == sol.findRepeatNumber(input));
    CHECK(resultTwo == sol.findRepeatNumber2(input2));
    CHECK(resultTwo == sol.findRepeatNumber3(input3));
}

TEST_CASE("test case 2 [test_so_03]", "[test_so_03]") {
    auto sol = Solution();
    std::vector<int32_t> input{2, 3, 1, 0, 2, 5, 3};
    std::vector<int32_t> input2{2, 3, 1, 0, 2, 5, 3};
    std::vector<int32_t> input3{2, 3, 1, 0, 2, 5, 3};
    static constexpr const auto resultOne{2};
    CHECK(resultOne == sol.findRepeatNumber(input));
    CHECK(resultOne == sol.findRepeatNumber2(input2));
    CHECK(resultOne == sol.findRepeatNumber3(input3));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP
