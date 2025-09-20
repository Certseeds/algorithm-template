// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_867_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_942.cpp"
#include <vector>
#include <string>

namespace leetcode_942 {
static void check(const string &str, const vector<int32_t> &vec) {
    const auto str_size{str.size()}, vec_size{vec.size()};
    CHECK(str_size + 1 == vec_size);
    for (size_t i{0}; i < str_size; ++i) {
        CHECK((str[i] == 'I' || str[i] == 'D'));
        if (str[i] == 'I') {
            CHECK(vec[i] < vec[i + 1]);
        } else {
            CHECK(vec[i] > vec[i + 1]);
        }
    }
}

TEST_CASE("test case 1 {test_942}", "{test_942}") {
    Solution solution;
    static constexpr const char *const str{"IDID"};
    check(str, solution.diStringMatch(str));
}

TEST_CASE("test case 2 {test_942}", "{test_942}") {
    Solution solution;
    static constexpr const char *const str{"III"};
    check(str, solution.diStringMatch(str));
}

TEST_CASE("test case 3 {test_942}", "{test_942}") {
    Solution solution;
    static constexpr const char *const str{"DDI"};
    check(str, solution.diStringMatch(str));
}
}
#endif // ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_942_TEST_HPP
