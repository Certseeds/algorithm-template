// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds


#ifdef ALGORITHM_TEST_MACRO
#include <vector>
#include <cstdint>
#include <tuple>
#include <algorithm>
namespace leetcode_1104 {
using std::vector;

#endif


class Solution {
public:
    vector<int32_t> pathInZigZagTree(int32_t label) {
        // 第一步,先把在哪一行计算出来
        const auto input{label};
        const auto [level, number] = [input]() {
            int32_t lev{0}, num{0};
            for (; num < input; ++lev) {
                num += (1 << lev);
            }
            return std::make_tuple(lev, num);
        }();
        // 拿到最后一行从0开始,从左向右数的序数
        const auto final_order = [](auto num_diff, auto lev) {
            if (lev % 2 == 0) {
                return (1 << lev) - num_diff - 1;
            } else {
                return num_diff;
            }
        }(number - input, level - 1);
        // 得到每一行自0开始,从左向右的序数(反向排列,一会儿需要用crbegin())
        vector<int32_t> each_level{};
        for (auto order_num{final_order}, lev{0}; lev < level; order_num /= 2, ++lev) {
            each_level.push_back(order_num);
        }
        // 一行一行的对应到数字
        vector<int32_t> will_return{};
        for (auto [lev, min, iter] {std::make_tuple(0, 1, each_level.crbegin())}; lev < level; ++lev, ++iter) {
            if (lev % 2 == 0) {
                will_return.push_back(min + *iter);
            } else {
                will_return.push_back(min - *iter + (1 << lev) - 1);
            }
            min += (1 << lev);
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
