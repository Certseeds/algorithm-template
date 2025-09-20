// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Done

#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_02_A{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_set;
static constexpr const char end{'\n'};
enum class CASE : uint8_t {
    NO, YES
};
using num_t = int32_t;
using input_type = tuple<unordered_set<num_t>, vector<num_t>>;
using output_type = vector<CASE>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t n{0}, v_in{-1};
    std::cin >> n;
    unordered_set<num_t> uset{};
    for (num_t i{0}; i < n; i++) {
        std::cin >> v_in;
        uset.insert(v_in);
    }
    num_t T{0};
    std::cin >> T;
    vector<num_t> testcases(T, 0);
    for (num_t i{0}; i < T; ++i) {
        std::cin >> testcases[i];
    }
    return std::make_tuple(uset, testcases);
}

output_type cal(const input_type &data) {
    unordered_set<num_t> uset;
    vector<num_t> testcases;
    std::tie(uset, testcases) = data;
    const size_t testcases_size = testcases.size();
    vector<CASE> will_return(testcases.size());
    for (size_t i{0}; i < testcases_size; i++) {
        if (uset.find(testcases[i]) == uset.end()) {
            will_return[i] = CASE::NO;
        } else {
            will_return[i] = CASE::YES;
        }
    }
    return will_return;
}

void output(const output_type &datas) {
    const static auto YES = "YES";
    const static auto NO = "NO";
    for (auto &&data: datas) {
        if (data == CASE::YES) {
            std::cout << YES << end;
        } else {
            std::cout << NO << end;
        }
    }
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
