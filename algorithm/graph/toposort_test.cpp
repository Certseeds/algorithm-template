// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <catch_main.hpp>
#include "toposort.hpp"
#include <iostream>

namespace graph {
namespace toposort {
using Catch::Matchers::Equals;

TEST_CASE("2 [test graph toposort]", "[test graph toposort]") {
    const auto obj = graphlist({{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}}, 4);
    SECTION("one toposort") {
        const auto result = obj.toposort();
        std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
        std::cout << std::endl;
    }SECTION("all toposort order") {
        const auto results = obj.toposorts();
        for (const auto &result: results) {
            std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
            std::cout << std::endl;
        }
    }
}

TEST_CASE("1 [test graph toposort]", "[test graph toposort]") {
    const auto obj = graphlist({{
                                        {1, 3, 8},
                                        {2, 4, 6},
                                        {3, 5, 9},
                                        {5, 6, 7},
                                        {4, 6, 8},
                                        {6, 7, 9},
                                        {7, 8, 9},
                                        {8, 9, 10},
                                }}, 9);
    const auto results = obj.toposorts();
    for (const auto &result: results) {
        std::copy(result.begin(), result.end(), std::ostream_iterator<size_t>(cout, ", "));
        std::cout << std::endl;
    }
}
}
}
