// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <algorithm>
#include <cstdint>
#include <vector>

namespace leetcode_670 {
using std::vector;
#endif

class Solution {
   public:
    int32_t maximumSwap(int32_t num) {
        vector<int32_t> nums_{};
        while (num > 0) {
            nums_.push_back(num % 10);
            num /= 10;
        }
        vector<int32_t> nums{nums_.crbegin(), nums_.crend()};
        int32_t maximum{num};
        const auto vec_to_number = [](const vector<int32_t> &vec) {
            int32_t i{0};
            for (const int iter : vec) {
                i *= 10;
                i += iter;
            }
            return i;
        };
        for (size_t i{nums.size()}; i > 0; --i) {
            size_t change = i - 1;
            for (size_t j{i - 1}; j > 0; --j) {
                if (nums[j - 1] < nums[i - 1]) {
                    change = j - 1;
                }
            }
            std::swap(nums[i - 1], nums[change]);
            const auto number = vec_to_number(nums);
            std::swap(nums[i - 1], nums[change]);
            maximum = std::max(number, maximum);
        }
        return maximum;
    }

    int32_t maximumSwap2(int32_t num) {
        vector<int32_t> nums_{};
        while (num > 0) {
            nums_.push_back(num % 10);
            num /= 10;
        }
        vector<int32_t> nums{nums_.crbegin(), nums_.crend()};
        const auto vec_to_number = [](const vector<int32_t> &vec) {
            int32_t i{0};
            for (const int iter : vec) {
                i *= 10;
                i += iter;
            }
            return i;
        };
        size_t max_loca{nums.size() - 1};
        size_t small{0}, big{0};
        for (size_t i{nums.size()}; i > 0; --i) {
            if (nums[i - 1] > nums[max_loca]) {
                max_loca = i - 1;
            } else if (nums[i - 1] < nums[max_loca]) {
                // 触发条件是 “发现右侧寻找到的最大值的左侧存在一个比他小的数字”
                small = i - 1;
                big = max_loca;
            }
            // equal条件下，max_loca优先采用右侧的数值,无需更新max_local
            // 倘若更新，岂不是big在small相同或左侧。
        }
        std::swap(nums[small], nums[big]);
        return vec_to_number(nums);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
