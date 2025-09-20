// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>
#include <cmath>

namespace leetcode_448 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> findDisappearedNumbers(const vector<int32_t> &nums) {
        vector<int32_t> res, num{nums};
        const auto nums_size{nums.size()};
        for (size_t i{0}; i < nums_size; i++) {
            const int32_t m = abs(num[i]) - 1; // index start from 0
            num[m] = num[m] > 0 ? -num[m] : num[m];
        }
        for (size_t i{0}; i < nums_size; i++) {
            if (num[i] > 0) {
                res.push_back(static_cast<int32_t>(i + 1));
            }
        }
        return res;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
