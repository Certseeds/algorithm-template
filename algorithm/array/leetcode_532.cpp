// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <unordered_map>
#include <numeric>
#include <cstdint>

namespace leetcode_532 {
using std::vector;
using std::unordered_map;

#endif


class Solution {
public:
    int32_t findPairs(const vector<int32_t> &nums, int32_t k) {
        if (k < 0) {
            return 0;
        }
        unordered_map<int32_t, int32_t> umap;
        int32_t count = 0;
        for (const auto num: nums) {
            umap[num]++;
        }
        if (k == 0) {
            return std::accumulate(umap.cbegin(), umap.cend(), 0,
                                   [](const auto base, const auto value) { return base + (value.second > 1); });
        }
        for (auto i: umap) {
            count += (umap.count(i.first + k) > 0);
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif

