/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-25 21:20:01
 * @LastEditors  : nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#define UNIT_TESTING_LAB_02

#include <catch_main.hpp>
#include "lab02_01.cpp"
#include "lab02_02.cpp"
#include "lab02_03.cpp"
#include <iostream>

using std::cout;
using std::endl;

TEST_CASE("test_lab03_01", "[run][.]") {
    sub_main_02_01();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_02", "[run][.]") {
    sub_main_02_02();
    cin.get();
    cin.get();
}

TEST_CASE("test_lab03_03", "[run][.]") {
    sub_main_02_03();
    cin.get();
    cin.get();
}
