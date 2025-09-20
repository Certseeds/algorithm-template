// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <limits>

namespace leetcode_29 {
#endif

class Solution {
public:
    int divide(int32_t dividend, int32_t divisor) {
        if (dividend == divisor) {
            return 1;
        } else if (divisor == std::numeric_limits<int32_t>::min()) {
            return 0;
        } else if (divisor == 1) {
            return dividend;
        }
        int32_t will_return{0}, signs{1};
        if (dividend == std::numeric_limits<int32_t>::min()) {
            if (divisor == -1) {
                return std::numeric_limits<int32_t>::max();
            }
            will_return += 1;
            // pay attention to the `sign` function
            dividend += sign(divisor) * divisor;
        }
        signs *= sign(dividend) * sign(divisor);
        dividend *= sign(dividend);
        divisor *= sign(divisor);
        while (dividend >= divisor) {
            short temp{0};
            //cout << dividend << " " << divisor << endl;
            while (dividend >= divisor) {
                //cout << dividend << " " << temp << " " << divisor << endl;
                if ((dividend >> 1) < (divisor << temp)) {
                    dividend -= (divisor << temp);
                    will_return += (1 << temp);
                    break;
                }
                temp++;
            }
        }
        return will_return * signs;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
