// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#include <catch_main.hpp>
#include "flow.hpp"

namespace graph::flow {

TEST_CASE("test max flow 1", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist({{{1, 3, 30}, {2, 1, 30}, {2, 3, 20}, {4, 2, 30}, {4, 3, 20}}}, 4);
    flow origin{adjlist_obj, 4, 3};
    origin.maxflow_ek();
    static constexpr const auto result{50};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 2", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 40}, {1, 4, 20}, {2, 4, 20}, {2, 3, 30}, {3, 4, 10}}
            }, 4);
    flow origin{adjlist_obj, 1, 4};
    origin.maxflow_ek();
    static constexpr const auto result{50};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 3", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 10}, {2, 3, 5}, {2, 4, 15}, {1, 4, 5}, {4, 3, 10}}
            }, 4);
    flow origin{adjlist_obj, 1, 3};
    origin.maxflow_ek();
    static constexpr const auto result{15};
    CHECK(result == origin.result);
}

TEST_CASE("test max flow 4", "[test graph flow]") {
    const auto adjlist_obj = build_adjlist(
            {
                    {{1, 2, 40}, {2, 4, 30}, {1, 3, 60}, {2, 3, 20}, {3, 5, 40}, {4, 5, 50}}
            }, 5);
    flow origin{adjlist_obj, 1, 5};
    origin.maxflow_ek();
    static constexpr const auto result{70};
    CHECK(result == origin.result);
}
}
