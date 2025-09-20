// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2021-2025 nanoseeds
#include <catch_main.hpp>
#include "fft.hpp"

namespace fft {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("basic -2", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(21ull)};
    const vector<int32_t> vec2{num_to_vec(43ull)};
    const vector<int32_t> result{num_to_vec(903ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("basic -1", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(4211ull)};
    const vector<int32_t> vec2{num_to_vec(3655ull)};
    const vector<int32_t> result{num_to_vec(15391205ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("basic 0", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(21ull)};
    const vector<int32_t> vec2{num_to_vec(35ull)};
    const vector<int32_t> result{num_to_vec(735ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("basic 1", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(123ull)};
    const vector<int32_t> vec2{num_to_vec(456ull)};
    const vector<int32_t> result{num_to_vec(56088ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("basic 2", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(114514ull)};
    const vector<int32_t> vec2{num_to_vec(1919810ull)};
    const vector<int32_t> result{num_to_vec(219845122340ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("basic 3", "[algorithm fft]") {
    const vector<int32_t> vec1{num_to_vec(201037ull)};
    const vector<int32_t> vec2{num_to_vec(20210513ull)};
    const vector<int32_t> result{num_to_vec(4063060901981ull)};
    CHECK_THAT(multiply(vec1, vec2), Equals(result));
}

TEST_CASE("extend check 0", "[algorithm fft]") {
    vector<int32_t> vec1{1};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{1}));
}

TEST_CASE("extend check 1", "[algorithm fft]") {
    vector<int32_t> vec1{1, 2};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2}));
}

TEST_CASE("extend check 2", "[algorithm fft]") {
    vector<int32_t> vec1{};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{}));
}

TEST_CASE("extend check 3", "[algorithm fft]") {
    vector<int32_t> vec1{1, 2, 3};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2, 3, 0}));
}

TEST_CASE("extend check 4", "[algorithm fft]") {
    vector<int32_t> vec1{1, 2, 3, 4};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2, 3, 4}));
}

TEST_CASE("extend check 5", "[algorithm fft]") {
    vector<int32_t> vec1{1, 2, 3, 4, 5};
    extend(vec1);
    CHECK_THAT(vec1, Equals(vector<int32_t>{1, 2, 3, 4, 5, 0, 0, 0}));
}
}
