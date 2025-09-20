/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanos
 * @Date: 2021-04-02 10:12:44
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2021-2023  nanos

*/

#include <catch_main.hpp>
#include "kmp.hpp"

namespace string_search {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("1 [string search]", "[string search]") {
    CHECK(strStr("hello", "ll") == 2);
    CHECK(strStr("aaaaa", "bba") == -1);
    CHECK(strStr("aaaaa", "") == 0);
    CHECK(strStr("a", "a") == 0);
    CHECK(strStr("mississippi", "issi") == 1);
    CHECK(strStr("mississippi", "issip") == 4);
}
}
