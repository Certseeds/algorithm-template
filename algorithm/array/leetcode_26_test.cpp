// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP

#include "leetcode_26.cpp"
#include <catch_main.hpp>

namespace leetcode_26 {
using std::vector;

using Catch::Matchers::Equals;


TEST_CASE("1 [test_26]", "[test_26]") {
    vector<int32_t> vec{1, 2};
    const vector<int32_t> result{1, 2};
    auto clas = Solution();
    THEN("then1 [test_26]") {
        clas.removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("2 [test_26]", "[test_26]") {
    vector<int32_t> vec{1, 1, 2};
    const vector<int32_t> result{1, 2};
    auto clas = Solution();
    THEN("then3 [test_26]") {
        clas.removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("3 [test_26]", "[test_26]") {
    vector<int32_t> vec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const vector<int32_t> result{0, 1, 2, 3, 4};
    auto clas = Solution();
    THEN("then5 [test_26]") {
        clas.removeDuplicates(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_26_TEST_HPP
