// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag array
//@Tag 数组

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_11_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_11_TEST_HPP

#include "leetcode_11.cpp"
#include <catch_main.hpp>

namespace leetcode_11 {
using std::vector;

TEST_CASE("test case 1 [test_11]", "[test_11]") {
    const vector<int32_t> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto clas = Solution();
    CHECK(clas.maxArea(vec) == 49);
}

TEST_CASE("test case 2 [test_11]", "[test_11]") {
    const vector<int32_t> vec{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    auto clas = Solution();
    CHECK(clas.maxArea(vec) == 35);
}

TEST_CASE("test case 3 [test_11]", "[test_11]") {
    const vector<int32_t> vec{959, 231, 691, 608, 805, 486, 630, 971, 712, 984, 856, 529, 979, 540, 301, 381, 285,
                              908, 78, 301, 818, 599, 996, 438, 163, 758, 301, 878, 22, 526, 771, 941, 59, 206, 636,
                              421, 45, 736, 676, 518, 645, 128, 291, 747, 458, 209, 987, 902, 632, 221, 955, 275,
                              889, 864, 827, 562, 554, 304, 610, 216, 41, 776, 700, 601, 457, 256, 825, 110, 429,
                              399, 488, 358, 346, 674, 557, 884, 665, 36, 810, 689, 520, 760, 455, 573, 881, 865,
                              568, 225, 588, 283, 689, 792, 677, 312, 229, 665, 585, 417, 666};
    auto clas = Solution();
    CHECK(clas.maxArea(vec) == 74004);
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_11_TEST_HPP
