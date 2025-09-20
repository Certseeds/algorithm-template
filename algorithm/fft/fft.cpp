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
#include "fft.hpp"

#ifndef M_PI
constexpr static auto M_PI{3.141592653589793238462643383279f};
#endif
constexpr static auto ntwoPI = -2 * M_PI;
namespace fft {
template<int32_t T>
void fft(vector<complex<double>> &line) {
    static_assert(T == 1 || T == -1, "T should be 1 or -1");
    size_t size{line.size()};
    if (1 == size) {
        return;
    }
    vector<complex<double>> fst, sec;
    for (size_t i{0}; i < size; i += 2) {
        fst.push_back(line[i]);
        sec.push_back(line[i + 1]);
    }
    fft<T>(fst);
    fft<T>(sec);
    const double angle{ntwoPI / static_cast<double>(size)};
    const auto w = complex<double>{std::cos(angle), std::sin(T * angle)};
    auto x = complex<double>{1.0f, 0.0f};
    for (size_t i{0}; i < size / 2; i++) {
        const auto added = x * sec[i];
        line[i] = fst[i] + added;
        line[i + size / 2] = fst[i] - added;
        x = x * w;
    }
}

vector<int32_t> multiply(const vector<int32_t> &one, const vector<int32_t> &sec) {
    assert(one.size() == sec.size());
    const auto ori_len = one.size();
    const auto multi_len = one.size() * 2;
    vector<complex<double>> one_(multi_len, {0.0f, 0.0f}), sec_(multi_len, {0.0f, 0.0f});
    for (size_t i{0}; i < ori_len; ++i) {
        one_[i] = one[i];
        sec_[i] = sec[i];
    }
    fft<1>(one_);
    fft<1>(sec_);
    vector<complex<double>> result(multi_len, {0.0f, 0.0f});
    for (size_t i{0}; i < multi_len; i++) {
        result[i] = one_[i] * sec_[i];
    }
    fft<-1>(result);
    for (size_t i{0}; i < multi_len; i++) {
        result[i] /= static_cast<double>(multi_len);
    }
    vector<int32_t> will_return{};
    will_return.reserve(multi_len);
    for (const auto &item: result) {
        will_return.emplace_back(lround(item.real()));
    }
    for (size_t i{1}; i < multi_len; i++) {
        will_return[i] += will_return[i - 1] / base;
        will_return[i - 1] %= base;
    }
    return will_return;
    //TODO,去零,写样例,debug.
}
}
