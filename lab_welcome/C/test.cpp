// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>

#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../lab_welcome/C/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_welcome_C {

using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test welcome C]") {
    CHECK(cal_detail(1) == "2");
    CHECK(cal_detail(2) == "3");
    CHECK(cal_detail(3) == "6");
    CHECK(cal_detail(4) == "22");
    CHECK(cal_detail(5) == "23");
    CHECK(cal_detail(6) == "26");
    CHECK(cal_detail(7) == "32");
    CHECK(cal_detail(8) == "33");
    CHECK(cal_detail(9) == "36");
    CHECK(cal_detail(10) == "62");
    CHECK(cal_detail(100) == "6262");
    CHECK(cal_detail(1000) == "636362");
    CHECK(cal_detail(10000) == "222236662");
    CHECK(cal_detail(100000) == "22362622262");
    CHECK(cal_detail(1000000) == "2323266262362");
    CHECK(cal_detail(999999999) == "3226236233626363336");
    CHECK(cal_detail(1000000000) == "3226236233626363362");
}
}
#endif //ALGORITHM_TEST_MACRO
