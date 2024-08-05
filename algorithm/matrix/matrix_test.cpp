// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS203_DSAA_template
    Copyright (C) 2020-2023 nanoseeds Wjia wuyuhao
*/
#include <catch_main.hpp>
#include <catch2/catch_version.hpp>
#include <catch2/catch_version_macros.hpp>
#include <complex>
#include <iostream>
#include <random>
#include <vector>
#include <cstdint>
#include "./matrix.hpp"

using namespace Mat_pro;

using Catch::Matchers::Equals;
using std::cout;
using std::endl;
using std::string;

TEST_CASE("test 0", "[test 0]") {
    auto function = [](const std::vector<int32_t> &t1,
                       const std::vector<int32_t> &t2) -> bool {
        assert(t1.size() == t2.size());
        for (uint32_t i = 0; i < t1.size(); i++) {
            if (t1[i] > t2[i]) {
                return true;
            } else if (t1[i] < t2[i]) {
                return false;
            }
        }
        return true;
    };
    REQUIRE(function({CATCH_VERSION_MAJOR, CATCH_VERSION_MINOR, CATCH_VERSION_PATCH}, {2, 12, 1}));
    REQUIRE(function({2, 13, 0}, {2, 12, 1}));
    REQUIRE(function({3, 0, 12}, {2, 12, 1}));
}

TEST_CASE("default nonparametric Constructor", "[test_1]") {
    Matrix<int32_t> m1;
    cout << m1;
    const auto *const m2_p = new Matrix<int32_t>();
    cout << *m2_p;
    delete m2_p;
}

TEST_CASE("default parameterized Constructor", "[test_1]") {
    Matrix<int64_t> m1(2, 2);
    cout << m1;
    Matrix<uint32_t> m2(5, 4);
    cout << m2;
    Matrix<std::complex<int32_t>> mat_comp(3, 4);
    cout << mat_comp;
}

TEST_CASE("Copy Constructor", "[test_1]") {
    Matrix<int64_t> m1(2, 2);
    Matrix<uint32_t> m2(5, 4);
    Matrix<std::complex<int32_t>> mat_comp(3, 4);
    Matrix<int64_t> m3(m1);
    cout << m3;
    Matrix<uint32_t> m4 = m2;
    cout << m4;
    CHECK(!m1.is_empty());
    CHECK(!m2.is_empty());
    CHECK(!m3.is_empty());
    CHECK(!m4.is_empty());
}

TEST_CASE("Move Constructor", "[test_1]") {
    Matrix<uint32_t> m1(5, 4);
    cout << m1;
    CHECK(!m1.is_empty());
    Matrix<uint32_t> m2 = std::move(m1);
    cout << m2;
    CHECK(m1.is_empty());
    CHECK(!m2.is_empty());
    Matrix<int32_t> m3 = std::move(Matrix<int32_t>(2, 3));
    cout << m3;
    CHECK(!m3.is_empty());
}

TEST_CASE("test vector<vector<T>> constructor") {
    vector<vector<int32_t>> v1{{1, 2},
                               {3, 4},
                               {5, 6},
                               {7, 8},
                               {9, 10}};
    vector<vector<int32_t>> v2{{1, 1, 4},
                               {5, 1, 4}};
    vector<vector<int32_t>> v3{{1, 1, 9},
                               {1, 2, 0},
                               {1, 1, 4}};
    vector<vector<int32_t>> v4{{1, 10},
                               {3, 4},
                               {5, 6},
                               {7, 8},
                               {9, 10}};
    auto vci = v4[1].begin();
    Matrix<int32_t> m1(v1);
    Matrix<int32_t> m2 = Matrix<int32_t>(v2);
    const auto m3 = Matrix<int32_t>(v3);
    const auto m4((Matrix<int32_t>(v4)));
    cout << m4;
}

TEST_CASE("Copy Assignment operator", "[test_1]") {
    Matrix<uint64_t> m1(3, 4);
    Matrix<uint64_t> m2;
    CHECK(!m1.is_empty());
    CHECK(m2.is_empty());
    m2 = m1;
    CHECK(!m1.is_empty());
    CHECK(!m2.is_empty());
}

TEST_CASE("Move Assignment operator", "[test_1]") {
    Matrix<uint64_t> m1(3, 7);
    Matrix<uint64_t> m2(7, 3);
    CHECK(!m1.is_empty());
    CHECK(!m2.is_empty());
    m2 = std::move(m1);
    CHECK(m1.is_empty());
    CHECK(!m2.is_empty());
}

TEST_CASE("initializer_list", "[test_1]") {
    Matrix<int64_t> m1
            {{1, 2, 3, 4, 54},
             {5, 2, 3, 3, 41}};
    CHECK(!m1.is_empty());
    cout << m1 << endl;
    Matrix<int64_t> m2{{1, 1, 4, 5, 1, 4},
                       {1, 9, 1, 9, 8, 1, 0}};
    CHECK(m2.is_empty());
    Matrix<int64_t> m3{};
    CHECK(m3.is_empty());
    cout << m3;
    Matrix<int64_t> m4{1, 2, 3, 4, 5};
    CHECK(!m4.is_empty());
    cout << m4;
    Matrix<int64_t> m5{1};
    CHECK(!m5.is_empty());
    cout << m5;
    // can not Matrix<int64_t> m6{};
}

TEST_CASE("no vectors negative", "[test_1]") {
    Matrix<std::complex<int32_t>> m1(5, 2);
    Matrix<int32_t> m2(4, 6);
    Matrix<int_fast16_t> m3(1, 4);
    Matrix<double> m4(0, -1);
    Matrix<float> m5(-1, -1);
    Matrix<int_least32_t> m6(-2, 9);
    CHECK(m1.rows() == 5);
    CHECK(m1.cols() == 2);
    CHECK(m2.rows() == 4);
    CHECK(m2.cols() == 6);
    CHECK(m3.rows() == 1);
    CHECK(m3.cols() == 4);
    CHECK(m4.rows() == 0);
    CHECK(m4.cols() == 0);
    CHECK(m5.rows() == 0);
    CHECK(m5.cols() == 0);
    CHECK(m6.rows() == 0);
    CHECK(m6.cols() == 0);
}

TEST_CASE("zeros and ones", "[test_2]") {
    Matrix<int16_t> m1 = Matrix<int16_t>::zeros(3, 3);
    cout << m1;
    Matrix<int32_t> m2 = Matrix<int32_t>::ones(4, 4);
    cout << m2;
    Matrix<int64_t> m3 = Matrix<int64_t>::values(5, 5, 114);
    cout << m3;
}

TEST_CASE("eye and eye_value", "[test_2]") {
    Matrix<int16_t> m1 = Matrix<int16_t>::eye(4);
    cout << m1;
    Matrix<int32_t> m2 = Matrix<int32_t>::eye_value(4, 4);
    cout << m2;
}

TEST_CASE("test is empty", "[test_2]") {
    CHECK(!Matrix<int16_t>::eye(4).is_empty());
    CHECK(!Matrix<int32_t>::eye_value(4, 4).is_empty());
    CHECK(Matrix<int16_t>::zeros(0, 0).is_empty());
    CHECK(Matrix<int32_t>::ones(0, 0).is_empty());
}

// UNTODO test the equal function.
TEST_CASE("size_equal function", "[test_2]") {
    auto m1 = Matrix<std::complex<int32_t>>::eye_value(5, 2);
    auto m2 = Matrix<int32_t>::zeros(5, 5);
    CHECK(size_equal(m1, m2));
    CHECK(size_equal(m1, m1));
    CHECK(size_equal(m2, m2));
    auto m3 = Matrix<int_fast16_t>::ones(3, 4);
    auto empty = Matrix<double>(0, 0);
    CHECK(!size_equal(m3, empty));
    CHECK(size_equal(m3, m3));
    CHECK(!size_equal(empty, empty));
    auto empty_2 = Matrix<float>(0, 0);
    CHECK(!size_equal(empty, empty_2));
    auto temp = std::move(empty_2);
    CHECK(!size_equal(temp, empty));
    CHECK(!size_equal(temp, empty_2));
    CHECK(!size_equal(m1, empty));
    CHECK(!size_equal(m2, empty));
}

TEST_CASE("inside_equal function", "[test_2]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 0},
                            {1, 1, 4}};
    Matrix<int32_t> m4{{1, 10},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m5{{1, 3, 4},
                       {5, 1, 4}};
    Matrix<int_fast16_t> m6{{1, 1, 9},
                            {1, 2, 0},
                            {4, 1, 4}};
    CHECK(!Matrix<int32_t>::inside_equal(m1, m4));
    CHECK(!Matrix<int32_t>::inside_equal(m2, m5));
    CHECK(!Matrix<int_fast16_t>::inside_equal(m3, m6));
}
// UNTODO and rows functiont
TEST_CASE("rows function", "[test_2]") {
    auto m1 = Matrix<std::complex<int32_t>>::eye_value(5, 2);
    auto m2 = Matrix<int32_t>::zeros(5, 5);
    auto m3 = Matrix<int_fast16_t>::ones(3, 4);
    auto empty = Matrix<double>(0, 0);
    auto empty_2 = Matrix<float>(0, 0);
    auto m4 = Matrix<int_least32_t>(3, 6);
    CHECK(m1.rows() == 5);
    CHECK(m2.rows() == 5);
    CHECK(m3.rows() == 3);
    CHECK(empty.rows() == 0);
    CHECK(empty_2.rows() == 0);
    CHECK(m4.rows() == 3);
    CHECK(Matrix<uint64_t>::ones(3, 4).rows() == 3);
    CHECK(Matrix<int16_t>::eye(4).rows() == 4);
    CHECK(Matrix<int32_t>::eye_value(4, 4).rows() == 4);
    CHECK(!Matrix<int16_t>::zeros(0, 0).rows());
    CHECK(!Matrix<int32_t>::ones(0, 0).rows());
    CHECK(!Matrix<int32_t>::ones(0, 5).rows());
    CHECK(Matrix<int32_t>::ones(5, 0).rows() == 5);
}
// UNTODO test for cols funciton
TEST_CASE("cols function", "[test_2]") {
    auto m1 = Matrix<std::complex<int32_t>>::eye_value(5, 2);
    auto m2 = Matrix<int32_t>::zeros(5, 5);
    auto m3 = Matrix<int_fast16_t>::ones(3, 4);
    auto empty = Matrix<double>(0, 0);
    auto empty_2 = Matrix<float>(0, 0);
    auto m4 = Matrix<int_least32_t>(3, 6);
    CHECK(m1.cols() == 5);
    CHECK(m2.cols() == 5);
    CHECK(m3.cols() == 4);
    CHECK(empty.cols() == 0);
    CHECK(empty_2.cols() == 0);
    CHECK(m4.cols() == 6);
    CHECK(Matrix<uint64_t>::ones(3, 4).cols() == 4);
    CHECK(Matrix<int16_t>::eye(4).cols() == 4);
    CHECK(Matrix<int32_t>::eye_value(4, 4).cols() == 4);
    CHECK(!Matrix<int16_t>::zeros(0, 0).cols());
    CHECK(!Matrix<int32_t>::ones(0, 0).cols());
    CHECK(!Matrix<int32_t>::ones(0, 5).cols());
    CHECK(!Matrix<int32_t>::ones(5, 0).cols());
}

// UNTODO test transpose
TEST_CASE("transpose", "[test_3]") {
    Matrix<std::complex<int32_t>> m1(5, 2);
    Matrix<int32_t> m2(4, 6);
    Matrix<int_fast16_t> m3(1, 4);
    Matrix<double> m4(0, -1);
    Matrix<float> m5(-1, -1);
    Matrix<int_least32_t> m6(-2, 9);
    CHECK(Matrix<uint64_t>::ones(3, 4).transpose().rows() == 4);
    CHECK(Matrix<int16_t>::eye(4).transpose().rows() == 4);
    CHECK(Matrix<int32_t>::eye_value(4, 4).transpose().rows() == 4);
    CHECK(!Matrix<int16_t>::zeros(0, 0).transpose().rows());
    CHECK(!Matrix<int32_t>::ones(0, 0).transpose().rows());
    CHECK(!Matrix<int32_t>::ones(0, 5).transpose().rows());
    CHECK(!Matrix<int32_t>::ones(5, 0).transpose().rows());
    CHECK(Matrix<uint64_t>::ones(3, 4).transpose().cols() == 3);
    CHECK(Matrix<int16_t>::eye(4).transpose().cols() == 4);
    CHECK(Matrix<int32_t>::eye_value(4, 4).transpose().cols() == 4);
    CHECK(!Matrix<int16_t>::zeros(0, 0).transpose().cols());
    CHECK(!Matrix<int32_t>::ones(0, 0).transpose().cols());
    CHECK(!Matrix<int32_t>::ones(0, 5).transpose().cols());
    CHECK(!Matrix<int32_t>::ones(5, 0).transpose().cols());
    CHECK(m1.transpose().cols() == 5);
    CHECK(m1.transpose().rows() == 2);
    CHECK(m2.transpose().cols() == 4);
    CHECK(m2.transpose().rows() == 6);
    CHECK(m3.transpose().cols() == 1);
    CHECK(m3.transpose().rows() == 4);
    CHECK(m4.transpose().cols() == 0);
    CHECK(m4.transpose().rows() == 0);
    CHECK(m5.transpose().cols() == 0);
    CHECK(m5.transpose().rows() == 0);
    CHECK(m6.transpose().cols() == 0);
    CHECK(m6.transpose().rows() == 0);
}

TEST_CASE("conj test", "[test_3]") {
    Matrix<std::complex<int32_t>> m1{{std::complex(2, 3),  std::complex(3, 5)},
                                     {std::complex(-2, 3), std::complex(-2, -3)},
                                     {std::complex(2, -3), std::complex(2, 3)}};
    Matrix<std::complex<double>> m2{{std::complex(2.5f, -3.0f), std::complex(3.0f, 5.0f)},
                                    {std::complex(-2.3f, 3.2f), std::complex(-2.0f, -3.0f)},
                                    {std::complex(2.0f, -3.0f), std::complex(2.5f, 3.0f)}};
    Matrix<std::complex<int32_t>> m1_conj{{std::complex(2, -3),  std::complex(3, -5)},
                                          {std::complex(-2, -3), std::complex(-2, 3)},
                                          {std::complex(2, 3),   std::complex(2, -3)}};
    Matrix<std::complex<double>> m2_conj{{std::complex(2.5f, 3.0f),   std::complex(3.0f, -5.0f)},
                                         {std::complex(-2.3f, -3.2f), std::complex(-2.0f, 3.0f)},
                                         {std::complex(2.0f, 3.0f),   std::complex(2.5f, -3.0f)}};
    Matrix<int32_t> m3{{2,  12},
                       {6,  8},
                       {10, 12},
                       {14, 16},
                       {18, 20}};
    cout << m1.conj();
    cout << m2.conj();
    // do not have
    CHECK(Matrix<std::complex<int32_t>>::inside_equal(m1.conj(), m1_conj));
    CHECK(Matrix<std::complex<double>>::inside_equal(m2.conj(), m2_conj));
    //CHECK(Matrix<int32_t>::inside_equal(conj(m3), m3));
}
// UNTODO for operator+
TEST_CASE("operator plus", "[test_3]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m4{{1, 10},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m7{{2,  12},
                       {6,  8},
                       {10, 12},
                       {14, 16},
                       {18, 20}};
    Matrix<int32_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m5{{1, 3, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m8{{2,  4, 8},
                       {10, 2, 8}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 0},
                            {1, 1, 4}};
    Matrix<int_fast16_t> m6{{1, 1, 9},
                            {1, 1, 0},
                            {2, 1, 6}};
    Matrix<int_fast16_t> m9{{2, 2, 18},
                            {2, 3, 0},
                            {3, 2, 10}};
    Matrix<int32_t> m14 = m1 + m4;
    Matrix<int32_t> m25{};
    m25 = m2 + m5;
    Matrix<int32_t> m36{m3 + m6};
    Matrix<int32_t> temp = m1 + m4 + m7;
    Matrix<int32_t> temp2 = m1 + m4 + m7 + make_number(2);
    Matrix<int32_t> temp4 = m1 + m4 + make_number(2) + m7;
    CHECK(Matrix<int32_t>::inside_equal(m1 + m4, m7));
    CHECK(Matrix<int32_t>::inside_equal(m14, m7));
    CHECK(Matrix<int32_t>::inside_equal(m2 + m5, m8));
    CHECK(Matrix<int32_t>::inside_equal(m25, m8));
    CHECK(Matrix<int_fast16_t>::inside_equal(m3 + m6, m9));
    CHECK(Matrix<int_fast16_t>::inside_equal(m36, m9));
}
// UNTODO for operator-
TEST_CASE("operator minus", "[test_3]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m4{{1, 10},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m7{{0, -8},
                       {0, 0},
                       {0, 0},
                       {0, 0},
                       {0, 0}};
    Matrix<int32_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m5{{1, 3, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m8{{0, -2, 0},
                       {0, 0,  0}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 0},
                            {1, 1, 4}};
    Matrix<int_fast16_t> m6{{1, 1, 9},
                            {1, 1, 0},
                            {2, 1, 6}};
    Matrix<int_fast16_t> m9{{0,  0, 0},
                            {0,  1, 0},
                            {-1, 0, -2}};
    CHECK(Matrix<int32_t>::inside_equal(m1 - m4, m7));
    CHECK(Matrix<int32_t>::inside_equal(m2 - m5, m8));
    CHECK(Matrix<int_fast16_t>::inside_equal(m3 - m6, m9));
}
// UNTODO for operator* (Matrix & number)
TEST_CASE("operator multiply_matrix_number", "[test_3]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m4{{2,  4},
                       {6,  8},
                       {10, 12},
                       {14, 16},
                       {18, 20}};
    Matrix<int32_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m5{{2,  2, 8},
                       {10, 2, 8}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 0},
                            {1, 1, 4}};
    Matrix<int_fast16_t> m6{{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0}};
    CHECK(Matrix<int32_t>::inside_equal(m1 * 2, m4));
    CHECK(Matrix<int32_t>::inside_equal(2 * m1, m4));
    CHECK(Matrix<int32_t>::inside_equal(m2 * 2, m5));
    CHECK(Matrix<int32_t>::inside_equal(2 * m2, m5));
    CHECK(Matrix<int_fast16_t>::inside_equal(m3 * 0, m6));
    CHECK(Matrix<int_fast16_t>::inside_equal(0 * m3, m6));
    Matrix<std::complex<int32_t>> mc1 = Matrix<std::complex<int32_t>>::ones(5, 4);
    Matrix<int32_t> m10 = Matrix<int32_t>::ones(5, 4);
    mc1 = mc1 * std::complex<int32_t>(3, 4);
    auto m11 = m10 * std::complex<int32_t>(3, 4);
    auto m12 = std::complex<int32_t>(3, 4) * m10;
    cout << mc1;
    cout << m11;
    cout << m12;
}
// TODO for operator* (matrix * matrix)
TEST_CASE("operator multiply_matrix_matrix_same", "[test_3]") {
    std::uniform_int_distribution<int32_t> range1(3, 6);
    std::random_device r;
    std::default_random_engine e1(r());
    int32_t t1 = range1(e1);
    int32_t t2 = range1(e1);
    int32_t t3 = range1(e1);
    vector<vector<int32_t>> vec1(t1, vector<int32_t>(t2));
    vector<vector<int32_t>> vec2(t2, vector<int32_t>(t3));
    for (auto &item: vec1) {
        for (auto &item2: item) {
            item2 = range1(e1);
        }
    }
    for (auto &item: vec2) {
        for (auto &item2: item) {
            item2 = range1(e1);
        }
    }
    cout << Matrix<int32_t>(vec1) * Matrix<int32_t>(vec2);
    vector<int32_t> vec3{1, 2, 3, 4};
    vector<int32_t> vec4{1, 2, 3, 4};
    cout << std::inner_product(vec1[0].cbegin(), vec1[0].cend(), vec1[0].cbegin(), 0) << "\n";
    vector<vector<int32_t>> vec5{{1, 2, 3},
                                 {4, 5, 6}};
    vector<vector<std::complex<int32_t>>> vec_c6{{std::complex<int32_t>(9, 10),  std::complex<int32_t>(11, 12)},
                                                 {std::complex<int32_t>(13, 14), std::complex<int32_t>(15, 61)}};
    //cout << Matrix<int32_t>(vec5) * Matrix<std::complex<int32_t>>(vec_c6);
}
// UNTODO for operator mul
TEST_CASE("operator mul", "[test_3]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m4{{1, 10},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<int32_t> m7{{1,  20},
                       {9,  16},
                       {25, 36},
                       {49, 64},
                       {81, 100}};
    Matrix<int32_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m5{{1, 3, 4},
                       {5, 1, 4}};
    Matrix<int32_t> m8{{1,  3, 16},
                       {25, 1, 16}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 0},
                            {1, 1, 4}};
    Matrix<int_fast16_t> m6{{1, 1, 9},
                            {1, 1, 0},
                            {2, 1, 6}};
    Matrix<int_fast16_t> m9{{1, 1, 81},
                            {1, 2, 0},
                            {2, 1, 24}};
    CHECK(Matrix<int32_t>::inside_equal(m1.mul(m4), m7));
    CHECK(Matrix<int32_t>::inside_equal(m2.mul(m5), m8));
    CHECK(Matrix<int_fast16_t>::inside_equal(m3.mul(m6), m9));
}
// UNTODO for operator dot
TEST_CASE("operator dot", "[test_3]") {
    Matrix<int32_t> m1{{1, 2, 3},
                       {4, 5, 6}};
    Matrix<int32_t> m2{{1, 2, 3},
                       {4, 5, 6}};
    cout << m1.dot(m2);
    CHECK(m1.dot(m2) == 91);
}

TEST_CASE("Kronecker product", "[test_3]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 1}};
    Matrix<int32_t> m2{{0, 3},
                       {2, 1}};
    Matrix<int32_t> result{{0, 3, 0, 6},
                           {2, 1, 4, 2},
                           {0, 9, 0, 3},
                           {6, 3, 2, 1}};
    auto m3 = kron(m1, m2);
    CHECK(Matrix<int32_t>::inside_equal(m3, result));
    cout << m3;
}

TEST_CASE("vector * matrix", "[test_3]") {
    Matrix<int32_t> m1{{0, 3, 0},
                       {2, 1, 4}};
    vector<int32_t> vec1{4,
                         5,
                         6};
    vector<int32_t> vec2{4,
                         5};
    vector<std::complex<int32_t>> vec3{std::complex<int64_t>(3, 4), std::complex<int64_t>(5, 6)};
    vector<std::complex<int32_t>> vec4{std::complex<int64_t>(3, 4), std::complex<int64_t>(5, 6),
                                       std::complex<int64_t>(7, 98)};
    cout << m1 * vec1;
    cout << vec2 * m1;
    cout << m1 * vec4;
    // decltype(std::declval<std::complex<int64_t>>() * std::declval<int64_t>()) temp2{1, 2};
    cout << vec3 * m1;
}

TEST_CASE("vector cross vector", "[test_3]") {
    vector<int32_t> vec1{4, 5, 6};
    vector<std::complex<int32_t>> vec2{std::complex<int64_t>(3, 4), std::complex<int64_t>(5, 6),
                                       std::complex<int64_t>(7, 98)};
    const auto vec3 = cross(vec1, vec2);
}

TEST_CASE("test for trace", "[test_5]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 1}};
    Matrix<int32_t> m2{{0, 3},
                       {2, 1}};
    Matrix<int32_t> result{{0, 3, 0, 6},
                           {2, 1, 4, 2},
                           {0, 9, 0, 3},
                           {6, 3, 2, 1}};
    cout << m1.trace() << "\n";
    cout << m1.determinant() << "\n";
    cout << m2.trace() << "\n";
    cout << m2.determinant() << "\n";
    cout << result.trace() << "\n";
    cout << result.determinant() << "\n";
}

TEST_CASE("max & min", "[test_1]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<uint32_t> m4{{2,  4},
                        {6,  8},
                        {10, 12},
                        {14, 16},
                        {18, 20}};
    Matrix<int64_t> m2{{1, 1, 4},
                       {5, 1, 4}};
    Matrix<int_least32_t> m5{{2,  2, 8},
                             {10, 2, 8}};
    Matrix<int_fast16_t> m3{{1, 1, 9},
                            {1, 2, 5},
                            {1, 1, 4}};

    CHECK(m1.max() == 10);
    CHECK(m1.min() == 1);
    CHECK(m4.max() == 20);
    CHECK(m4.min() == 2);
    CHECK(m2.max() == 5);
    CHECK(m2.min() == 1);
    CHECK(m3.max() == 9);
    CHECK(m3.min() == 1);
    CHECK(m5.max() == 10);
    CHECK(m5.min() == 2);
    CHECK(m1.row_max(3) == 6);
    CHECK(m1.row_min(2) == 3);
    CHECK(m4.row_max(5) == 20);
    CHECK(m4.row_min(1) == 2);
    CHECK(m2.row_max(2) == 5);
    //CHECK(m2.row_min(0) == -1);
    CHECK(m3.row_max(3) == 4);
    CHECK(m3.row_min(1) == 1);
    CHECK(m5.row_max(2) == 10);
    CHECK(m5.row_min(1) == 2);
    CHECK(m1.col_max(1) == 9);
    CHECK(m1.col_min(2) == 2);
    //CHECK(m4.col_max(0) == -1);
    CHECK(m4.col_min(2) == 4);
    CHECK(m2.col_max(1) == 5);
    CHECK(m2.col_min(3) == 4);
    CHECK(m3.col_max(3) == 9);
    CHECK(m3.col_min(1) == 1);
    CHECK(m5.col_max(1) == 10);
    CHECK(m5.col_min(2) == 2);
}

TEST_CASE("sum & avg", "[test_1]") {
    Matrix<int32_t> m1{{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8},
                       {9, 10}};
    Matrix<uint32_t> m4
            {{2,  4},
             {6,  8},
             {10, 12},
             {14, 16},
             {18, 20}};
    //cout << m4.conj();
    Matrix<int64_t> m2{{1, 1, 4},
                       {5, 1, 6}};
    Matrix<int_least32_t> m5{{2,  2, 8},
                             {10, 2, 6}};
    Matrix<int_fast16_t> m3{{1, 3, 9},
                            {1, 2, 5},
                            {1, 1, 4}};
    CHECK(m1.sum() == 55);
    CHECK(m1.avg() == 5.5);
    CHECK(m4.sum() == 110);
    CHECK(m4.avg() == 11);
    CHECK(m2.sum() == 18);
    CHECK(m2.avg() == 3);
    CHECK(m3.sum() == 27);
    CHECK(m3.avg() == 3);
    CHECK(m5.sum() == 30);
    CHECK(m5.avg() == 5);
    CHECK(m1.row_sum(1) == 3);
    CHECK(m1.row_avg(5) == 9.5);
    CHECK(m4.row_sum(2) == 14);
    CHECK(m4.row_avg(3) == 11);
    CHECK(m2.row_sum(1) == 6);
    CHECK(m2.row_avg(6) == -1);
    CHECK(m3.row_sum(1) == 13);
    CHECK(m3.row_avg(3) == 2);
    CHECK(m5.row_sum(1) == 12);
    CHECK(m5.row_avg(1) == 4);
    CHECK(m1.col_sum(1) == 25);
    CHECK(m1.col_avg(5) == -1);
    CHECK(m4.col_sum(2) == 60);
    CHECK(m4.col_avg(1) == 10);
    CHECK(m2.col_sum(1) == 6);
    CHECK(m2.col_avg(1) == 3);
    CHECK(m3.col_sum(1) == 3);
    CHECK(m3.col_avg(3) == 6);
    CHECK(m5.col_sum(1) == 12);
    CHECK(m5.col_avg(1) == 6);

    Matrix<std::complex<int32_t>> mc1 = Matrix<std::complex<int32_t>>::ones(5, 4);
    Matrix<double_t> m10 = Matrix<double_t>::ones(5, 4);
    mc1 = mc1 * std::complex<int32_t>(3, 4);
    cout << mc1;
    cout << "sum: " << mc1.sum() << endl;
    cout << "average: " << mc1.avg() << endl;
    cout << "sum of row1: " << mc1.row_sum(1) << endl;
    cout << "average of row1: " << mc1.row_avg(1) << endl;
    cout << "sum of column1: " << mc1.col_sum(1) << endl;
    cout << "average of column1: " << mc1.col_avg(1) << endl;
    const Matrix<std::complex<double_t>> m11 = m10 * std::complex<double_t>(3.5, 4.5);
    cout << m11;
    cout << "sum: " << m11.sum() << endl;
    cout << "average: " << m11.avg() << endl;
    cout << "sum of row5: " << m11.row_sum(5) << endl;
    cout << "average of row5: " << m11.row_avg(5) << endl;
    cout << "sum of column4: " << m11.col_sum(4) << endl;
    cout << "average of column4: " << m11.col_avg(4) << endl;
}
// TODO vector<vector<T>> test
TEST_CASE("test for convolution", "[test_7]") {
    Matrix<int32_t> m1{{1, 1, 1, 0, 0},
                       {0, 1, 1, 1, 0},
                       {0, 0, 1, 1, 1},
                       {0, 0, 1, 1, 0},
                       {0, 1, 1, 0, 0}};
    Matrix<int32_t> m2{{1, 0, 1},
                       {0, 1, 0},
                       {1, 0, 1}};
    cout << m1.convolution(m2);
    cout << m1.convolution(m2, 0, 2);
    cout << m1.convolution(m2, 1);
    cout << m1.convolution(m2, 1, 2);
    cout << m1.convolution(m2, 2);
    cout << m1.convolution(m2, 2, 2);
    cout << m1.convolution(m2, 2, 3);
}

TEST_CASE("test for reshape&slice", "[test_6]") {
    Matrix<int32_t> m1{{1,  2},
                       {3,  4},
                       {5,  6},
                       {7,  8},
                       {9,  10},
                       {11, 12}};
    Matrix<uint32_t> m2{{2, 4, 5, 6, 7, 8},
                        {9, 1, 3, 4, 0, 2}};

    Matrix<int64_t> m3{{3, 4, 7},
                       {5, 1, 6},
                       {1, 1, 1},
                       {9, 8, 2}};
    Matrix<int_least32_t> m4{{2,  2, 8, 6},
                             {10, 2, 6, 7},
                             {1,  3, 9, 4}};
    Matrix<int_fast16_t> m5{{1, 1, 1, 1, 1, 1},
                            {2, 2, 2, 2, 2, 2},
                            {3, 3, 3, 3, 3, 3},
                            {1, 1, 1, 1, 1, 1},
                            {2, 2, 2, 2, 2, 2},
                            {3, 3, 3, 3, 3, 3}};
    cout << m1.reshape(3, 4);
    cout << m1.slice(1, 3);
    cout << m1.slice(1, 3, 4, 3);
    cout << m2.reshape(4, 3);
    cout << m2.slice(1, 2);
    cout << m2.slice(1, 2, 2, 6);
    cout << m3.reshape(2, 6);
    cout << m3.slice(1, 2);
    cout << m3.slice(1, 2, 1, 2);
    cout << m4.reshape(6, 2);
    cout << m4.slice(1, 2);
    cout << m4.slice(1, 2, 3, 4);
    cout << m5.reshape(9, 4);
    cout << m5.slice(2, 3);
    cout << m5.slice(2, 3, 4, 5);
}

#ifdef  _HAVE_OPENCV_

template<typename T>
void full_random(Mat &temp);

template<typename T>
void full_random(Mat &temp) {
    std::uniform_int_distribution<int32_t> range1(10, 100);
    std::random_device r;
    std::default_random_engine e1(r());
    for (int i = 0; i < temp.rows; ++i) {
        for (int j = 0; j < temp.cols * temp.channels(); ++j) {
            temp.at<T>(i, j) = range1(e1);
        }
    }
}

TEST_CASE("test for cv_matrix", "[test_8][.]") {
    Mat temp = Mat::ones(2, 3, 0);
    full_random<uchar>(temp);
    cout << "mat 1" << endl;
    cout << cv_to_mat<int32_t>(temp) << endl;

    Mat temp2 = Mat::ones(3, 4, CV_16SC2);
    full_random<short>(temp2);
    cout << temp2 << endl;
    cout << cv_to_mat<int32_t>(temp2);

    Mat temp3 = Mat::zeros(5, 6, CV_32SC3);
    full_random<int32_t>(temp3);
    cout << temp3 << endl;
    cout << cv_to_mat<int32_t>(temp3);

    Mat temp4 = Mat::zeros(5, 6, CV_32FC3);
    full_random<float>(temp4);
    cout << temp4 << endl;
    cout << cv_to_mat<float>(temp4);

    Mat temp5 = Mat::ones(6, 7, CV_64FC4);
    full_random<double_t>(temp5);
    cout << temp5 << endl;
    cout << cv_to_mat<double_t>(temp5);
}

TEST_CASE("test for matrix_to_cv", "[test_8][.]") {
    Matrix<int32_t> mat1{{1, 2, 3, 4},
                         {2, 3, 4, 5},
                         {4, 5, 6, 7}};
    cout << mat1 << endl;
    cout << mat_to_cv<int32_t>(mat1, 2) << endl;

    Matrix<int16_t> mat2{{1, 2, 3, 4},
                         {2, 3, 4, 5},
                         {4, 5, 6, 7}};
    cout << mat2 << endl;
    cout << mat_to_cv<int16_t>(mat2, 4) << endl;

    Matrix<uint16_t> mat3{{1, 2, 3, 4},
                          {2, 3, 4, 5},
                          {4, 5, 6, 7}};
    cout << mat3 << endl;
    cout << mat_to_cv<uint16_t>(mat3, 4) << endl;

    Matrix<uint8_t> mat4{{1, 2, 3, 4},
                         {2, 3, 4, 5},
                         {4, 5, 6, 7}};
    cout << mat4 << endl;
    cout << mat_to_cv<uint8_t>(mat4, 1) << endl;

    Matrix<int8_t> mat5{{1, 2, 3, 4},
                        {2, 3, 4, 5},
                        {4, 5, 6, 7}};
    cout << mat5 << endl;
    cout << mat_to_cv<int8_t>(mat5, 1) << endl;

    Matrix<float> mat6{{1.0f, 2.0f, 3, 4},
                       {2,    3,    4, 5},
                       {4,    5,    6, 7}};
    cout << mat6 << endl;
    cout << mat_to_cv<float>(mat6, 2) << endl;

    Matrix<double> mat7{{1.0f, 2.0f, 3, 4},
                        {2,    3,    4, 5},
                        {4,    5,    6, 7}};
    cout << mat7 << endl;
    cout << mat_to_cv<>(mat7, 4) << endl;
    cout << mat_to_cv(mat7, 4) << endl;
}

#endif

TEST_CASE("test for row_exchange in test_5") {
    Matrix<double_t> matrix{{1, 2},
                            {3, 4}};
    Matrix<double_t> result1{{3, 4},
                             {1, 2}};
    CHECK(Matrix<double_t>::inside_equal(result1, matrix.row_exchange(0, 1)));
    CHECK(!Matrix<double_t>::inside_equal(result1, matrix));
}

TEST_CASE("eigenvalue", "[test_5]") {
    vector<double_t> eigenvalues;
    Matrix<int32_t> m3{{5, -3, 2},
                       {6, -4, 4},
                       {4, -4, 5}};
    eigenvalues = m3.eigenvalue();

    cout << m3.Hessenberg().Givens(1, 1, 2);

    cout << "eigenvalues of m3: \n";
    for (int i = 0; i < 3; ++i) {
        cout << eigenvalues[i] << " ";
    }
    cout << endl;

    Matrix<int32_t> m1{{1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1}};
    cout << "Hessenberg of m1: \n";
    cout << m1.Hessenberg();
    cout << "eigenvalues of m1: \n";
    eigenvalues = m1.eigenvalue();
    for (int i = 0; i < 4; ++i) {
        cout << eigenvalues[i] << " ";
    }
    cout << endl;
    cout << "m1's eigenvector:\n";
    Matrix<int32_t> m2{{9, 3, 5},
                       {2, 6, 7},
                       {4, 8, 1}};
    cout << endl << m2.Householder(1, 2);
    cout << m2.Hessenberg();
    cout << "eigenvalues of m2: \n";
    eigenvalues = m2.eigenvalue();
    for (int j = 0; j < 3; ++j) {
        cout << eigenvalues[j] << " ";
    }
}

TEST_CASE("eigenvector", "[test_5]") {
    Matrix<int32_t> m1{{2, 1},
                       {1, 2}};

    Matrix<int32_t> m2{{-2, 1, 1},
                       {0,  2, 0},
                       {-4, 1, 3}};
    Matrix<int32_t> m3{{1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1},
                       {1, 1, 1, 1}};
    vector<double_t> eigenvalues;
    eigenvalues = m1.eigenvalue();
    cout << "m1's eigenvalues:" << endl;
    for (int j = 0; j < 2; ++j) {
        cout << eigenvalues[j] << " ";
    }
    cout << endl << "m1's eigenvectors:" << endl << m1.eigenvector();
    eigenvalues = m2.eigenvalue();
    cout << "m2's eigenvalues:" << endl;
    for (int j = 0; j < 3; ++j) {
        cout << eigenvalues[j] << " ";
    }
    cout << endl << "m2's eigenvectors:" << endl << m2.eigenvector();
    eigenvalues = m3.eigenvalue();
    cout << "m3's eigenvalues:" << endl;
    for (int j = 0; j < 4; ++j) {
        cout << eigenvalues[j] << " ";
    }
    cout << endl << "m3's eigenvectors:" << endl << m3.eigenvector();
}

TEST_CASE("inverse", "[test_5]") {
    Matrix<double> m1{{2, 2},
                      {1, 2}};
    auto temp = m1.inverse();
    Matrix<double> m2{{1,    -1},
                      {-0.5, 1}};
    Matrix<double> m3{{-2, 1, 1},
                      {0,  2, 0},
                      {-4, 1, 3}};
    auto temp2 = m3.inverse();
    Matrix<double> m4{{-1.5, 0.5, 0.5},
                      {0,    0.5, 0},
                      {-2,   0.5, 1}};
    Matrix<double> m5{{2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 2, 0, 0, 0, 0, 0, 0},
                      {0, 0, 2, 0, 0, 0, 0, 0},
                      {0, 0, 0, 2, 0, 0, 0, 0},
                      {0, 0, 0, 0, 2, 0, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 0, 2, 0},
                      {0, 0, 0, 0, 0, 0, 0, 2}};
    auto temp3 = m5.inverse();
    Matrix<double> m6{{0.5, 0,   0,   0,   0,   0,   0,   0},
                      {0,   0.5, 0,   0,   0,   0,   0,   0},
                      {0,   0,   0.5, 0,   0,   0,   0,   0},
                      {0,   0,   0,   0.5, 0,   0,   0,   0},
                      {0,   0,   0,   0,   0.5, 0,   0,   0},
                      {0,   0,   0,   0,   0,   0.5, 0,   0},
                      {0,   0,   0,   0,   0,   0,   0.5, 0},
                      {0,   0,   0,   0,   0,   0,   0,   0.5}};
    Matrix<double> m7{2};
    auto temp4 = m7.inverse();
    Matrix<double> m8{0.5};
    CHECK(Matrix<double>::inside_equal(temp, m2));
    CHECK(Matrix<double>::inside_equal(temp2, m4));
    CHECK(Matrix<double>::inside_equal(m5.inverse(), m6));
    CHECK(Matrix<double>::inside_equal(m7.inverse(), m8));
}
