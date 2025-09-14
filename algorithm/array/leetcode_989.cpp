// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/

#include <vector>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_989 {
using std::vector;
#endif

class Solution {
public:
    std::vector<int32_t> addToArrayForm(std::vector<int32_t> &num, int32_t k) {
        vector<int32_t> will_return{num};
        const auto num_size{num.size()};
        int32_t last{0};
        for (size_t i{will_return.size()}; i >= 1; --i) {
            last += k % 10;
            k = k / 10;
            will_return[i - 1] += last;
            last = (will_return[i - 1] >= 10);
            will_return[i - 1] = will_return[i - 1] % 10;
        }
        while (k > 0 || last > 0) {
            last += k % 10;
            k /= 10;
            will_return.emplace(will_return.begin(), last % 10);
            last = last / 10;
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
