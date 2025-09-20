// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>

namespace leetcode_263 {
#endif

class Solution {
   private:
    bool isUgly2(const int32_t n) {
        if (n <= 6) {
            return true;
        } else if (n % 2 == 0) {
            return isUgly2(n >> 1);
        } else if (n % 3 == 0) {
            return isUgly2(n / 3);
        } else if (n % 5 == 0) {
            return isUgly2(n / 5);
        }
        return false;
    }
   public:
    bool isUgly(int32_t n) {
        if (n <= 0) {
            return false;
        }
        return isUgly2(n);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
