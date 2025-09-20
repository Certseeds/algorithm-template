/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-04-16 00:50:43
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-16 13:24:31
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifndef CS205_C_CPP_MIDTERM_2021SPRING
#define CS205_C_CPP_MIDTERM_2021SPRING

#include <catch_main.hpp>
#include "question1.cpp"
#include "question2.cpp"
#include "question3.cpp"
#include "question4.cpp"
#include "question5.cpp"

namespace question1 {
TEST_CASE("1 [question 1]", "[question 1]") {
    CHECK(count(1) == 0);
    CHECK(count(2) == 0);
    CHECK(count(3) == 0);
    CHECK(count(4) == 0);
    CHECK(count(5) == 1);
    CHECK(count(6) == 1);
    CHECK(count(7) == 1);
    CHECK(count(8) == 1);
    CHECK(count(9) == 1);
    CHECK(count(10) == 2);
    CHECK(count(1000) != 0);
}
}
namespace question2 {
TEST_CASE("2 [question 2]", "[question 2]") {
    CHECK(count(make_tuple(unordered_map<int32_t, int32_t>{{{1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}}}, 2, 3)) ==
          3);
}
}
namespace question3 {
TEST_CASE("1 [question 3]", "[question 3]") {
    CHECK(count(1) == 5);
    CHECK(count(9) == 13);
    CHECK(count(15) == 18);
}
}
namespace question4 {
TEST_CASE("1 [question 4]", "[question 4]") {
    CHECK(count(std::make_tuple(vector<int32_t>{30, 20, 35, 40}, vector<int32_t>{20, 18, 25, 30}, 50)) == 38);
    CHECK(count(std::make_tuple(vector<int32_t>{5, 4, 7, 2, 6}, vector<int32_t>{12, 3, 10, 3, 6}, 10)) == 15);
    CHECK(count(std::make_tuple(vector<int32_t>{3, 4, 5}, vector<int32_t>{4, 5, 6}, 10)) == 11);
    CHECK(count(std::make_tuple(vector<int32_t>{2, 2, 6, 5, 4}, vector<int32_t>{6, 3, 5, 4, 6}, 10)) == 15);
}
}
namespace question5 {
TEST_CASE("1 [question 5]", "[question 5]") {
    CHECK(count(vector<vector<Color>>{{Color::Y, Color::X, Color::X, Color::B},
                                      {Color::Y, Color::X, Color::X, Color::B},
                                      {Color::Y, Color::X, Color::X, Color::B},
                                      {Color::Y, Color::X, Color::X, Color::B}}) == 3);
}
}
#endif //! CS205_C_CPP_MIDTERM_2021SPRING
