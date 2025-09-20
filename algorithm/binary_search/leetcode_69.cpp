// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <algorithm>
#include <vector>
#include <cstdint>
// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace leetcode_69 {
using std::vector;

#endif


class Solution {
public:
    int32_t mySqrt(int32_t x) {
        if (x == 0) {
            return 0;
        } else if (x <= 3) {
            return 1;
        }
        size_t begin{1}, end{static_cast<size_t>(x - 1)}, middle{0};
        while (begin <= end) {
            middle = begin + (end - begin) / 2;
            const size_t mul{middle * middle},
                    mul2{mul + (middle << 1) + 1};
            if (mul <= static_cast<size_t>(x) && static_cast<size_t>(x) < mul2) {
                return static_cast<int32_t>(middle);
            }
            if (mul > static_cast<size_t>(x)) {
                end = middle - 1;
            } else if (mul < static_cast<size_t>(x)) {
                begin = middle + 1;
            }
        }
        return -1;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
