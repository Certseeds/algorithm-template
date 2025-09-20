// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 双指针
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_999.cpp"

namespace leetcode_999 {

TEST_CASE("test case 1 {test_999}", "{test_999}") {
    auto sol = Solution();
    std::vector<std::vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                         {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'}};
    static constexpr const auto result{3};
    CHECK(result == sol.numRookCaptures(board));
}

TEST_CASE("test case 2 {test_999}", "{test_999}") {
    auto sol = Solution();
    std::vector<std::vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                                         {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                                         {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
                                         {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                                         {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'},
                                         {'.', '.', '.', '.', '.', '.', '.', '.'}};
    static constexpr const auto result{0};
    CHECK(result == sol.numRookCaptures(board));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_999_TEST_HPP
