// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/

#include <cstddef>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <tuple>

namespace dp {
namespace divide_bar { // Introduction to Algorithms Edition3 Chapter15.1

namespace iter {
class Solution {
public:
    int64_t maxProfit(const std::vector<int64_t> &divide_profits, size_t length) {
        const auto minIter{std::min(divide_profits.size(), length)};
        std::vector<int64_t> profits_table(length + 1, -0x3f3f3f);
        profits_table[0] = 0;
        for (size_t i{0}; i < minIter; ++i) {
            profits_table[i + 1] = divide_profits[i];
        }
        for (size_t i{2}; i <= length; ++i) {
            for (size_t j{1}; j < (i / 2 + 1); ++j) {
                profits_table[i] = std::max(profits_table[i], profits_table[j] + profits_table[i - j]);
            }
        }
        return profits_table.back();
    }
};
}

namespace with_solution {
class Solution {
public:
    std::tuple<int64_t, std::vector<int64_t>> maxProfit(const std::vector<int64_t> &divide_profits, size_t length) {
        const auto minIter{std::min(divide_profits.size(), length)};
        std::vector<int64_t> profits_table(length + 1, -0x3f3f3f);
        std::vector<std::vector<int64_t>> segment_table(length + 1);
        profits_table[0] = 0;
        segment_table[0] = {};
        for (size_t i{0}; i < minIter; ++i) {
            profits_table[i + 1] = divide_profits[i];
            segment_table[i + 1].push_back(static_cast<int64_t>(i + 1));
        }
        for (size_t i{2}; i <= length; ++i) {
            size_t left{0}, right{0};
            for (size_t j{1}; j < (i / 2 + 1); ++j) {
                const auto sums = profits_table[j] + profits_table[i - j];
                if (sums > profits_table[i]) { // 相对倾向于保留大块
                    profits_table[i] = sums;
                    left = j;
                    right = i - j;
                }
            }
            if (left != 0 && right != 0) {
                auto mid = segment_table[left];
                mid.insert(mid.end(), segment_table[right].cbegin(), segment_table[right].cend());
                segment_table[i] = mid; // 操作完成之后赋值,防止操作自己
            }
        }
        return std::make_tuple(profits_table.back(), segment_table.back());
    }
};
}

namespace rec {
class Solution {
public:
    int64_t maxProfit(const std::vector<int64_t> &divide_profits, size_t length) {
        return 0;
    }
};
}

}
}

