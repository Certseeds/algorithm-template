

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>

namespace leetcode_1402 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxSatisfaction(const vector<int32_t> &satisfaction) {
        vector<int32_t> vec{};
        std::map<int32_t, int32_t, std::greater<>> map{};
        for (const auto x: satisfaction) {
            if (x >= 0) {
                vec.push_back(x);
            } else {
                map[x]++; // 又或者可以从中心向两边分别遍历
            }
        }
        std::sort(vec.begin(), vec.end(), [](const auto a, const auto b) { return a < b; });
        const auto size{vec.size()};
        int32_t mul1{0},sum1{0};
        for (size_t i{size}; i > 0; i--) {
            mul1 = mul1 + (vec[i - 1]) * static_cast<int32_t>(i);
            sum1 = sum1 + (vec[i - 1]) ;
        }// 后面排序根本就不会变化
        // 只有前面会变化, 但是排序是从小到大固定的, 问题只是到哪里停罢了
        for (const auto &[k, v]: map) {
            for (int32_t i{0}; i < v; i++) {
                const auto diff = k + sum1;
                if (diff > 0) {
                    mul1 += diff;
                    sum1 += k;
                } else {
                    break;
                }
            }
        }
        return mul1;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
