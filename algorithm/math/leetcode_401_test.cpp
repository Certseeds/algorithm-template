// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_401.cpp"

namespace leetcode_401 {
using std::vector;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_401]", "[test_401]") {
    static constexpr const auto input{1};
    const vector<string> result{
            "0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"
    };
    Solution solution;
    CHECK_THAT(result, UnorderedEquals(solution.readBinaryWatch(input)));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_401_TEST_HPP

