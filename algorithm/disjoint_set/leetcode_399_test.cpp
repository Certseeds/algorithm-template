// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP

#include <catch_main.hpp>
#include "leetcode_399.cpp"

namespace leetcode_399 {
using std::string;
using std::vector;

using Catch::Matchers::ApproxMatcher;
using Catch::Matchers::Approx;

TEST_CASE("1 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "b"},
            {"b", "c"},
    };
    const vector<double_t> values{2.0f, 3.0f};
    const vector<vector<string>> queries{
            {"a", "c"},
            {"b", "a"},
            {"a", "e"},
            {"a", "a"},
            {"x", "x"},
    };
    const vector<double_t> results{6.0f, 0.5f, -1.0f, 1.0f, -1.0f};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("2 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "b"},
    };
    const vector<double_t> values{0.5f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"b", "a"},
            {"a", "c"},
            {"x", "y"},
    };
    const vector<double_t> results{0.5f, 2.0f, -1.0f, -1.0f};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("3 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a",  "b"},
            {"b",  "c"},
            {"bc", "cd"}
    };
    const vector<double_t> values{1.5f, 2.5f, 5.0f};
    const vector<vector<string>> queries{
            {"a",  "c"},
            {"c",  "b"},
            {"bc", "cd"},
            {"cd", "bc"},
    };
    const vector<double_t> results{3.75f, 0.4f, 5.0f, 0.2f};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}


TEST_CASE("5 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"x1", "x2"},
            {"x2", "x3"},
            {"x1", "x4"},
            {"x2", "x5"},
    };
    const vector<double_t> values{3.0f, 0.5f, 3.4f, 5.6f};
    const vector<vector<string>> queries{
            {"x2", "x4"},
            {"x1", "x5"},
            {"x1", "x3"},
            {"x5", "x5"},
            {"x5", "x1"},
            {"x3", "x4"},
            {"x4", "x3"},
            {"x6", "x6"},
            {"x0", "x0"},
    };
    const vector<double_t> results{1.13333, 16.8, 1.5, 1.0, 0.05952, 2.26667, 0.44118, -1.0, -1.0};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("4 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"a", "e"},
            {"b", "e"},
    };
    const vector<double_t> values{4.0f, 3.0f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"e", "e"},
            {"x", "x"},
    };
    const vector<double_t> results{1.3333f, 1.0f, -1.0f};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}

TEST_CASE("6 [test_399]", "[test_399]") {
    const vector<vector<string>> edges{
            {"e", "a"},
            {"e", "b"},
    };
    const vector<double_t> values{3.0f, 4.0f};
    const vector<vector<string>> queries{
            {"a", "b"},
            {"e", "e"},
            {"x", "x"},
    };
    const vector<double_t> results{1.3333f, 1.0f, -1.0f};
    Solution solution;
    CHECK_THAT(results, Approx(solution.calcEquation(edges, values, queries)).epsilon(0.01f));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_399_TEST_CPP
