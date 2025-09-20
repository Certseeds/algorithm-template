/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanos
 * @Date: 2021-05-13 20:29:37
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2021-2023  nanos

*/
#include "fft.hpp"

namespace fft {
vector<int32_t> multiply(const vector<int32_t> &one, const vector<int32_t> &sec) {
    size_t length = std::max(one.size(), sec.size());
    vector<int32_t> will_return(length << 1, 0);
    for (size_t i{0}; i < one.size(); ++i) {
        for (size_t j{0}; j < sec.size(); ++j) {
            will_return[i + j] += one[i] * sec[j];
        }
    }
    for (size_t i{1}; i < will_return.size(); ++i) {
        will_return[i] += will_return[i - 1] / base;
        will_return[i - 1] %= base;
    }
    return will_return;
}
}
