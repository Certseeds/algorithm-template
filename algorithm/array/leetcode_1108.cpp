// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <string>
#include <array>

namespace leetcode_1108 {
using std::string;
#endif

class Solution {
public:
    string defangIPaddr(const string &address) {
        const int32_t add_size{static_cast<int>(address.size())};
        string will_return(add_size + 6, ' ');
        std::array<int, 5> position{-1, 0, 0, 0, add_size};
        // .255.100.50.0.
        for (int32_t i{0}, cnt{1}; i < add_size; ++i) {
            if (address[i] == '.') {
                position[cnt] = i;
                cnt++;
            }
        }
        auto iter = will_return.begin();
        for (size_t i{0}; i < 3; ++i) {
            for (int32_t j = position[i] + static_cast<int>(1); j < position[i + 1]; ++j) {
                (*iter) = address[j];
                ++iter;
            }
            (*iter) = '[';
            ++iter;
            (*iter) = '.';
            ++iter;
            (*iter) = ']';
            ++iter;
        }
        for (int32_t j = position[3] + static_cast<int>(1); j < position[4]; ++j) {
            (*iter) = address[j];
            ++iter;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
