// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <cstdint>
#include <cstddef>
#include <vector>
namespace leetcode_162 {
using std::vector;

#endif


class Solution {
public:
    int32_t findPeakElement(const vector<int32_t> &nums) {
        const auto nums_size = nums.size();
        if (nums_size == 1 || nums.front() > nums[1]) {
            return 0;
        }
        if (nums[nums_size - 2] < nums.back()) {
            return static_cast<int32_t>(nums_size - 1);
        }
        size_t left{0}, step{[nums_size] {
            size_t step{1};
            while (step < nums_size) {
                step *= 2;
            }
            return step / 2;
        }()};
        const auto judge = [nums, nums_size](size_t order) {
            if (order == 0 || order == nums_size - 1) {
                return -1;
            }
            return (nums[order] > nums[order - 1] && nums[order] > nums[order + 1]) ? static_cast<int32_t>(order)
                                                                                    : -1;
        };
        while (left < nums_size && step > 0) {
            if (judge(left) != -1) {
                return static_cast<int32_t>(left);
            }
            if (left + step >= 1 && left + step < nums_size && nums[left + step - 1] < nums[left + step]
                && left + step + 1 < nums_size && nums[left + step] < nums[left + step + 1]) {
                left += step;
            } else {
                step /= 2;
            }// 核心思想,找一个最后一个处于 "上升状态" 的节点
        }
        return static_cast<int32_t>(left) + 1;
    }

    int32_t findPeakElement2(const vector<int32_t> &nums) {
        constexpr const static auto nege1{static_cast<int32_t>(-1)};
        const auto nums_size = nums.size();
        if (nums_size == 1) {
            return 0;
        }
        if (nums.front() > nums[1]) {
            return 0;
        }
        if (nums[nums_size - 2] < nums.back()) {
            return static_cast<int32_t>(nums_size - 1);
        }
        size_t left{0}, right{nums_size - 1}, mid;
        const auto judge = [nums, nums_size](size_t order) {
            if (order == 0 || order == nums_size - 1) {
                return nege1;
            }
            return (nums[order] > nums[order - 1] && nums[order] > nums[order + 1]) ? static_cast<int32_t>(order)
                                                                                    : nege1;
        };
        while (left < right) {
            if (mid = (right - left) / 2 + left;judge(mid) != -1) {
                return judge(mid);
            } else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        } // 核心思想,先排除边界条件
        // 之后 寻找第一个
        return static_cast<int32_t>(left);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
