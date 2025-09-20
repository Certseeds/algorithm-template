// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstddef>
#include <limits>

namespace leetcode_1362 {
using std::array;
#endif
using num_type = int64_t;

class Solution {
    array<num_type, 2> closetDivisors_inside(num_type num) {
        assert(num > 0);
        num_type a{0}, b{0};
        num_type min_diff{std::numeric_limits<int64_t>::max()};
        const auto sqrt_num = static_cast<num_type>(std::sqrt(num));
        for (num_type i{sqrt_num}; i > 0; i--) {
            if (num % i == 0) {
                const auto j = num / i;
                return {std::min(i, j), std::max(i, j)};
            }
        }
        return {0, 0};
        // 复杂度是 O(sqrt(num))
        // if num is 10^9, sqrt(num) is 10^5
    }
public:
    array<num_type, 2> closetDivisors(num_type num) {
        const auto result1 = closetDivisors_inside(num + 1);
        const auto result2 = closetDivisors_inside(num + 2);
        if (std::abs(result1[0] - result1[1]) < std::abs(result2[0] - result2[1])) {
            return result1;
        }
        return result2;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
