// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#define UNIT_TESTING_LAB_04


#include <catch_main.hpp>
#include "./lab04_01.cpp"
#include "./lab04_02.cpp"
#include "./lab04_03.cpp"
#include <iostream>

using std::cout;
using std::endl;

TEST_CASE("test_lab04_01", "[run][.]") {
    sub_main_04_01();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab04_02", "[run][.]") {
    sub_main_04_02();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab04_03", "[run][.]") {
    sub_main_04_03();
    cin.get();
    cin.get();
}
