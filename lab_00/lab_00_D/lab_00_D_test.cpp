// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <catch_main.hpp>
#include <iostream>
#include <tuple>
#include "lab_00_D.cpp"

std::string getFilePath() noexcept { return "./../../../lab_00/lab_00_D/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_D {

using std::cin;
using std::cout;
using std::tie;
using std::tuple;
using std::vector;

using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1", "[test 00 D]") {
    const CS203_redirect cr{"01.data.in"};
    // 重定向开始,开始run
    auto input_data = read();
    cal(input_data);
    // 重定向结束
}

TEST_CASE("test case 2", "[test 00 D]") {
    SECTION("do") {
        const CS203_redirect cr{"01.data.in", "01.test.out"};
        auto input_data = read();
        cal(input_data);
    }SECTION("compare files") {
        CHECK(compareFiles("01.test.out", "01.data.out"));
    }
}
} // namespace lab_00_D

#endif // CS203_DSAA_TEST_MACRO
