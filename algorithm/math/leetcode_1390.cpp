
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <cmath>

namespace leetcode_1390 {
using std::vector;
#endif

class Solution {
public:
    int32_t sumFourDivisors(const vector<int32_t> &nums) {
        int32_t will_return{0};
        for (const auto &num: nums) {
            int32_t count{0}, sum{0};
            for (int32_t i{1}; i <= std::sqrt(num) && count <= 4; ++i) {
                if (num % i == 0) {
                    count += 1;
                    sum += i;
                    if (i * i != num) {
                        count += 1;
                        sum += num / i;
                    }
                }
            }
            if (count == 4) {
                will_return += sum;
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
