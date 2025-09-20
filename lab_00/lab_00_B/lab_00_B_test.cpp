// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO


#include <catch_main.hpp>
#include <tuple>
#include <vector>
#include <iostream>
#include "lab_00_B.cpp"

std::string getFilePath() noexcept { return "./../../../lab_00/lab_00_B/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_B {
using std::tie;
using std::cin;
using std::cout;
using std::tuple;
using std::vector;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1", "[test 00 B]") {
    const auto vec1 = vector<num_type>{8, 1, 2, 3, 4, 5, 6, 7, 1100000};
    for (const auto &i: vec1) {
        CHECK(cal(i) == brute_force(i));
    }
}

TEST_CASE("test case 2", "[test 00 B]") {
    const auto vec1 = vector<num_type>{1, 2, 3, 4, 5, 6, 7, 1100000};
    const auto result = cal_warpper(vec1);
    const auto what_we_want = vector<num_type>{1, 4, 10, 20, 35, 56, 84, 221833938333700000};
    CHECK_THAT(result, Equals<num_type>({1, 4, 10, 20, 35, 56, 84, 221833938333700000}));
    CHECK_THAT(result, Equals(what_we_want));
}
}
#endif //CS203_DSAA_TEST_MACRO
