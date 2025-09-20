/**
 * @Github: https://github.com/Certseeds/algorithm_template
 * @Author: nanos
 * @Date: 2021-08-14 17:38:35
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
#include <algorithm>
#include <array>
#include <forward_list>
#include <iostream>

namespace moderncpp::chap04 {
using std::cout, std::endl;

int32_t main() {
    std::array<int32_t, 13> arr{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    // 必须手动填长度,有点难受,不知道什么时候会出自动推导长度的版本
    std::sort(arr.begin(), arr.end());
    std::forward_list<int32_t> flist{};
    for (auto &&v: arr) {
        flist.push_front(v);
    }
    return 0;
}

}

int32_t main() {
    return moderncpp::chap04::main();
}
