// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <unordered_map>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1 {
using std::unordered_map;
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> twoSum(const vector<int32_t> &nums, int32_t target) {
        const auto nums_size{nums.size()};
        unordered_map<int32_t, int32_t> umaps;
        for (size_t i{0}; i < nums_size; i++) {
            if (umaps.find(target - nums[i]) != std::end(umaps)) {
                return {static_cast<int32_t>(i), umaps[target - nums[i]] - 1};
            }
            umaps[nums[i]] = static_cast<int32_t>(i) + 1;
        }
        return {};
    }
};

/*
if the number is not so big, it's better to use brute force,
if number > 50,choose hashmap.
 */
#ifdef CS203_DSAA_TEST_MACRO
}
#endif