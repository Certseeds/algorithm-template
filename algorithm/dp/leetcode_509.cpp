// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef CS203_DSAA_TEST_MACRO

#include <array>
#include <cstdint>
#include <cstddef>

namespace leetcode_509 {
using std::array;
#endif

class Solution {
private:
    static constexpr const size_t max{31};

    static constexpr auto func() {
        std::array<int32_t, max> fib{0};
        fib[1] = 1;
        for (size_t i{2}; i < max; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib;
    }

public:
    int32_t fib(int32_t n) {
        static constexpr const std::array<int32_t, func().size()> arr = func();
        return arr[n];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
