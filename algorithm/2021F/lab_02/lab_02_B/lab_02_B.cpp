// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Done

#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_02_B{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int64_t;
using input_type = vector<num_t>;
using output_type = vector<num_t>;

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
    num_t T{0};
    std::cin >> T;
    input_type inputs(T, 0);
    for (int32_t i{0}; i < T; ++i) {
        std::cin >> inputs[i];
    }
    return inputs;
}

output_type cal(const input_type &data) {
    output_type outputs(data.size(), static_cast<output_type::value_type>(0));
    const auto input_size = static_cast<int32_t>(data.size());
    for (int32_t i{0}; i < input_size; ++i) {
        outputs[i] = (data[i] * (data[i] + 1) * (data[i] + 2)) / 6;
    }
    return outputs;
}

void output(const output_type &data) {
    for (auto &&num: data) {
        std::cout << num << end;
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
