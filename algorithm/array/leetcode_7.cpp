// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <array>
#include <vector>
#include <limits>
#include <cstdint>

namespace leetcode_7 {
using std::vector;
using std::array;
#endif


class Solution {
public:
    int32_t reverse(int32_t x) {
        if (x == std::numeric_limits<int32_t>::min()) {
            return 0;
        } else if (x < 0) {
            return -reverse3(-x);
        }
        std::array<uint8_t, 10> nums{0};
        int32_t count{0};
        while (x > 0) {
            nums[count] = x % 10;
            x /= 10;
            count++;
        }
        int32_t i{0};
        while (i < count && nums[i] == 0) {
            i++;
        }
        int32_t will_return = 0;
        for (; i < count; i++) {
            if (will_return > (std::numeric_limits<int32_t>::max() - nums[i]) / 10) {
                return 0;
            }
            will_return = will_return * 10 + nums[i];
        }
        return static_cast<int32_t>(will_return);
        // 不用64bit版
    }

    int32_t reverse2(int32_t x) {
        if (x == std::numeric_limits<int32_t>::min()) {
            return 0;
        } else if (x < 0) {
            return -1 * reverse3(-x);
        }
        vector<int32_t> nums;
        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int32_t i{0};
        while (i < static_cast<int>(nums.size()) && nums[i] == 0) {
            i++;
        }
        long will_return = 0;
        for (; i < static_cast<int>(nums.size()); i++) {
            will_return = will_return * 10 + nums[i];
            if (will_return > std::numeric_limits<int32_t>::max()) {
                return 0;
            }
        }
        return static_cast<int32_t>(will_return);
    }

    int32_t reverse3(int32_t x) {
        if (x == std::numeric_limits<int32_t>::min()) {
            return 0;
        } else if (x < 0) {
            return -reverse3(-x);
        }
        vector<uint8_t> vec;
        vec.reserve(32);
        while (x > 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        int32_t will_return = 0;
        for (const auto &i: vec) {
            if (will_return > std::numeric_limits<int32_t>::max() / 10) {
                return 0;
            }
            will_return = 10 * will_return + i;
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
