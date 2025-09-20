// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_309 {
using std::vector;
#endif

class Solution {
public:
    int32_t maxProfit(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        vector<int32_t> dpBuy(p_size + 1, 0), dpSell(p_size + 1, 0);
        dpBuy[0] = 0; // 0 day之前无法有任何操作
        dpSell[0] = 0; // 0 day之前无法有任何操作
        dpBuy[1] = -prices[0]; // 1 day 购入
        dpSell[1] = 0; // 无法sell,没东西
        for (size_t i{2}; i <= p_size; i++) {
            const auto price{prices[i - 1]};
            dpBuy[i] = std::max(dpBuy[i - 1], dpSell[i - 2] - price); // 只有卖出后有冷冻期,买入时没有
            dpSell[i] = std::max(dpSell[i - 1], dpBuy[i - 1] + price);
        }
        return dpSell.back();
    }

    int32_t maxProfit2(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        int32_t buy1{-prices[0]}, buy2{0};
        int32_t sell0{0}, sell1{0}, sell2{0};
        for (size_t i{1}; i < p_size; i++, buy1 = buy2, sell1 = sell2) {
            const auto price{prices[i]};
            buy2 = std::max(buy1, sell0 - price); //
            sell2 = std::max(sell1, buy1 + price);
            sell0 = sell1;
        }
        return sell2;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
