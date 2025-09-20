// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <array>
#include <cstddef>
#include <cstdint>

namespace leetcode_1137 {
using std::array;
#endif


class Solution {
private:
    static constexpr const size_t maxV{38};

    static constexpr auto func() {
        array<int32_t, maxV> fib{0};
        fib[1] = 1;
        fib[2] = 1;
        for (size_t i{3}; i < maxV; i++) {
            fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
        }
        return fib;
    }

public:
    int32_t tribonacci(int32_t n) {
        static constexpr const array<int32_t, func().size()> arr = func();
        return arr[n];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
