/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanos
 * @Date: 2021-05-13 20:29:20
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2021-2023  nanos

*/
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_FFT_FFT_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_FFT_FFT_HPP


#include <cstdint>
#include <array>
#include <cassert>
#include <vector>
#include <complex>

namespace fft {
constexpr static int32_t base{10};
using std::vector;
using std::complex;

/**
 * 将10进制数字的每个数字拆开,装在数组中
 * 要求两个数组长度相等,且都为2的倍数,设为n
 * 返回一个长度为2n的数组,
 * 20210504被表达为vector<int32_t>{4,0,5,0,1,2,0,2};
 * */
vector<int32_t> multiply(const vector<int32_t> &one, const vector<int32_t> &sec);

inline void extend(vector<int32_t> &vec) {
    if (vec.empty()) {
        return;
    }
    size_t size{vec.size() - 1};
    int32_t powered{0};
    while (size != 0) {
        size /= 2;
        powered++;
    }
    size = vec.size();
    for (int32_t i{static_cast<int32_t>(size)}; i < (1 << powered); i++) {
        vec.emplace_back(0);
    }
}

inline vector<int32_t> num_to_vec(uint64_t uint64) {
    vector<int32_t> will_return{};
    while (uint64 != 0) {
        will_return.push_back(static_cast<int32_t>(uint64 % base));
        uint64 /= base;
    }
    extend(will_return);
    return will_return;
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_FFT_FFT_HPP
