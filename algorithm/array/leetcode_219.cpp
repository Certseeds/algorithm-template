// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <unordered_map>
#include <cstdint>

namespace leetcode_219 {
using std::vector;
using std::unordered_map;
#endif

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int32_t> &nums, int32_t k) {
        unordered_map<size_t, int32_t> umap;
        const int32_t nums_size{static_cast<int32_t>(nums.size())};
        for (int32_t i{0}; i < nums_size; i++) {
            if (umap[nums[i]] != 0 && (i - umap[nums[i]]) < k) {
                return true;
            }
            umap[nums[i]] = i + 1;
        }
        return false;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
