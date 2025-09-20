// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

namespace leetcode_896 {
using std::vector;
#endif

class Solution {
public:
    bool isMonotonic(const vector<int> &nums) {
        const auto nums_size{nums.size()};
        if (nums_size == 0 || nums_size == 1) {
            return true;
        }
        static constexpr const auto compare = [](const auto x, const auto y) -> int32_t {
            if (x > y) {
                return 1;
            } else if (x < y) {
                return -1;
            }
            return 0;
        };
        int counts{0};
        int maxv{std::numeric_limits<int16_t>::min()}, minv{std::numeric_limits<int16_t>::max()};
        for (size_t i{1}; i < nums_size; ++i) {
            counts = compare(nums[i], nums[i - 1]);
            maxv = std::max(maxv, counts);
            minv = std::min(minv, counts);
            if (maxv == 1 && minv == -1) {
                return false;
            }
        }
        return true;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
