/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanos
 * @Date: 2021-04-02 09:50:56
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2021-2023  nanos

*/
#include "kmp.hpp"

namespace string_search {

int strStr_kmp(const string &h, const string &n);

vector<int32_t> get_next(const string &h);

int strStr(const std::string &h, const std::string &n) {
    return strStr_kmp(h, n);
}

int strStr_kmp(const string &h, const string &n) {
    if (n.empty()) {
        return 0;
    } else if (h.size() < n.size()) {
        return -1;
    }
    int32_t x{0}, y{0};
    int32_t hsize{static_cast<int32_t>(h.size())}, nsize{static_cast<int32_t>(n.size())};
    vector<int32_t> next = get_next(n);
    while ((x < hsize) && (y < nsize)) {
        if (y == -1 || h[x] == n[y]) {
            x++;
            y++;
        } else {
            y = next[y];
        }
    }
    if (y == nsize) {
        return x - y;
    }
    return -1;
}

vector<int32_t> get_next(const string &h) {
    vector<int32_t> will_return(h.size(), -1);
    int64_t x = -1;
    size_t y = 0;
    while (y < h.size() - 1) {
        if (x == -1 || h[x] == h[y]) {
            x++;
            y++;
            will_return[y] = x;
        } else {
            x = will_return[x];
        }
    }
    return will_return;
}
}
