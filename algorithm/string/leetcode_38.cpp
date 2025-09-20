// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#include <string>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_38 {
using std::string;
#endif

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str1{countAndSay(n - 1)};
        string will_return{};
        const auto str1_size{str1.size()};
        for (size_t i{0}; i < str1_size;) {
            int32_t length{0};
            while (str1[i + length] == str1[i]) {
                length++;
            }
            will_return.append(1, length + '0');
            will_return.append(1, str1[i]);
            i += length;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
