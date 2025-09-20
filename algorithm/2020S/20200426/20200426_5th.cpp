// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023  nanoseeds
*/
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

int main() {
    uint32_t q{0};
    std::cin >> q;
    for (uint32_t i{0}; i < q; ++i) {
        int64_t x{0};
        int32_t k{0};
        std::cin >> x >> k;
        int32_t times{0};
        std::stack<int32_t> sta;
        while (x > 0) {
            sta.push(x & 1);
            x /= 2;
            times++;
        }
        if (k >= times) {
            std::cout << -1 << std::endl;
            continue;
        }
        uint64_t will_cout = 0;
        for (int32_t j{0}; j + 1 < k; ++j) {
            will_cout += sta.top();
            sta.pop();
            will_cout *= 2;
        }
        will_cout += sta.top();
        //cout << times << endl;
        std::cout << will_cout << std::endl;
    }
}
