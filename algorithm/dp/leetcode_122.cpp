// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <stack>
#include <algorithm>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_122 {
using std::vector;
using std::stack;
#endif

class Solution {
public:
    int32_t maxProfit(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        // 样例 1-2-3-4-5
        // 不考虑1买入,2卖出
        // 而是考虑 1买入,
        //         2卖出,2买入
        //         3卖出,3买入
        //         4卖出,4买入
        //         5卖出
        // 这样的一串流程,并且只在卖出时计费
        int32_t will_return{0};
        stack<int32_t> sta;
        for (size_t i{0}; i < p_size; i++) {
            int32_t perf{0};
            const auto price = prices[i];
            if (!sta.empty() && price > sta.top()) {
                perf = price - sta.top();
                sta.pop();
            }
            sta.push(price);
            will_return += perf;
        }
        return will_return;
    }

    int32_t maxProfit2(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        int32_t willreturn{0}, temp{0};
        for (size_t i{1}; i < p_size; i++) {
            temp = prices[i] - prices[i - 1];
            if (temp > 0) {
                willreturn += temp;
            }
        }
        return willreturn;
    }

    int32_t maxProfit3(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        vector<int32_t> dpBuy(p_size + 1, 0), dpSell(p_size + 1, 0);
        // dpBuy[i], 第i天之后, 购入股票状态下的最大收益
        // dpSell[i], 第i天之后, 出售股票状态下的最大收益
        dpBuy[0] = 0; // 0 day之前无法有任何操作
        dpSell[0] = 0; // 0 day之前无法有任何操作
        dpBuy[1] = -prices[0]; // 1 day 购入
        dpSell[1] = 0; // 无法sell,没东西
        for (size_t i{2}; i <= p_size; i++) {
            const auto price{prices[i - 1]};
            dpBuy[i] = std::max(dpBuy[i - 1], dpSell[i - 1] - price); //
            dpSell[i] = std::max(dpSell[i - 1], dpBuy[i - 1] + price);
        }
        return dpSell.back();
    }

    int32_t maxProfit4(const vector<int32_t> &prices) {
        const auto p_size{prices.size()};
        if (p_size <= 1) {
            return 0;
        }
        // 忽略掉了第0天 => 第一天的变动
        int32_t buyLast{-prices[0]}, buyNow{0};
        int32_t sellLast{0}, sellNow{0};
        // dpBuy[i], 第i天之后, 购入股票状态下的最大收益
        // dpSell[i], 第i天之后, 出售股票状态下的最大收益
        for (size_t i{1}; i < p_size; i++, sellLast = sellNow, buyLast = buyNow) {
            const auto price{prices[i]};
            buyNow = std::max(buyLast, sellLast - price); //
            sellNow = std::max(sellLast, buyLast + price);
        }
        return sellNow;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
