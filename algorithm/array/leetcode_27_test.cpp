// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag STL

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_27_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_27_TEST_HPP

#include "leetcode_27.cpp"
#include <catch_main.hpp>

namespace leetcode_27 {
using std::vector;

TEST_CASE("1 [test_27]", "[test_27]") {
    static constexpr const int32_t test_result{5};
    vector<int32_t> vec1{0, 1, 2, 2, 3, 0, 4, 2};
    auto clas = Solution();
    THEN("1-1 [test_27]") {
        CHECK(clas.removeElement(vec1, 2) == test_result);
    }THEN("1-2 [test_27]") {
        CHECK(clas.removeElement2(vec1, 2) == test_result);
    }
}

TEST_CASE("2 [test_27]", "[test_27]") {
    vector<int32_t> vec1{3, 2, 2, 3};
    static constexpr const int32_t test_result{2};
    auto clas = Solution();
    THEN("2-1 [test_27]") {
        CHECK(clas.removeElement(vec1, 2) == test_result);
    }THEN("2-2 [test_27]") {
        CHECK(clas.removeElement2(vec1, 2) == test_result);
    }

}

TEST_CASE("3 [test_27]", "[test_27]") {
    vector<int32_t> vec1{1};
    static constexpr const int32_t test_result{0};
    auto clas = Solution();
    THEN("3-1 [test_27]") {
        CHECK(clas.removeElement(vec1, 1) == test_result);
    }THEN("3-2 [test_27]") {
        CHECK(clas.removeElement2(vec1, 1) == test_result);
    }
}

TEST_CASE("4 [test_27]", "[test_27]") {
    static constexpr const int32_t test_result{0};
    vector<int32_t> vec1{};
    auto clas = Solution();
    THEN("4-1 [test_27]") {
        CHECK(clas.removeElement(vec1, 0) == test_result);
    }THEN("4-2 [test_27]") {
        CHECK(clas.removeElement(vec1, 0) == test_result);
    }
}

TEST_CASE("5 [test_27]", "[test_27]") {
    static constexpr const int32_t test_result{0};
    vector<int32_t> vec1{3, 3};
    auto clas = Solution();
    THEN("5-1 [test_27]") {
        CHECK(clas.removeElement(vec1, 3) == test_result);
    }THEN("5-2 [test_27]") {
        CHECK(clas.removeElement(vec1, 3) == test_result);
    }
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_27_TEST_HPP
