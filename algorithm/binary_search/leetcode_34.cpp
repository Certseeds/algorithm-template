// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <algorithm>
#include "basic.hpp"

namespace leetcode_34 {

using std::vector;
using binary_search::binary_search_pos;
#endif

class Solution {
public:
    vector<int32_t> searchRange(const vector<int32_t> &nums, int32_t target) {
        if (nums.empty()) {
            return vector<int32_t>{-1, -1};
        }
        if (binary_search_pos(nums, target, 0, static_cast<int32_t>(nums.size())) == -1) {
            return vector<int32_t>{-1, -1};
        }
        const auto minv{static_cast<int32_t>(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin())},
                maxv{static_cast<int32_t>(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin())};
        return vector<int32_t>{minv, maxv - 1};
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
