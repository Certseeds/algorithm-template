// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_1362_test.hpp"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <limits>

namespace leetcode_1362 {
using num_type = int64_t;
array<num_type, 2> closetDivisors_inside(num_type num) {
    assert(num > 0);
    num_type a{0}, b{0};
    num_type min_diff{std::numeric_limits<int64_t>::max()};
    const auto sqrt_num = static_cast<num_type>(std::sqrt(num));
    for (num_type i{sqrt_num}; i > 0; i--) {
        if (num % i == 0) {
            const auto j = num / i;
            return {std::min(i,j), std::max(i,j)};
        }
    }
    return {0,0};
    // 复杂度是 O(sqrt(num))
    // if num is 10^9, sqrt(num) is 10^5
}
// 将数字分解成多个质因数, 之后多个质因数之间组合, 找出差最小的两个

array<num_type, 2> leetcode_1362::closetDivisors(num_type num){
    const auto result1 = closetDivisors_inside(num + 1);
    const auto result2 = closetDivisors_inside(num + 2);
    if (std::abs(result1[0] - result1[1]) < std::abs(result2[0] - result2[1])) {
        return result1;
    }
    return result2;
}

}
