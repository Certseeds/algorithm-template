// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
// id: 1250
#include <list>
#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_00_B{
#endif
using std::cin;
using std::cout;
using std::string;
using std::vector;
static constexpr const char end{'\n'};

using num_type = uint64_t;
using input_type = vector<num_type>;
using output_type = vector<num_type>;

inline input_type read();

output_type cal_warpper(const input_type &input);

num_type cal(num_type data);

num_type brute_force(num_type data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    const auto output_data = cal_warpper(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    int32_t number{0};
    std::cin >> number;
    input_type will_return(number, 0);
    for (auto &item: will_return) {
        std::cin >> item;
    }
    return will_return;
}

output_type cal_warpper(const input_type &input) {
    const auto size{input.size()};
    output_type will_return(size, 0);
    for (size_t i{0}; i < size; ++i) {
        will_return[i] = cal(input[i]);
    }
    return will_return;
}

inline num_type cal(num_type data) {
    const num_type will_return = data * (data + 1) * (data + 2) / 6;
    return will_return;
}

num_type brute_force(num_type data) {
    num_type will_return{0};
    for (num_type i = 1; i <= data; ++i) {
        will_return += i * (i + 1) / 2;
    }
    return will_return;
}

void output(const vector<num_type> &data) {
    for (const auto &num: data) {
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
