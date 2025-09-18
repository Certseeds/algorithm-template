// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <cstddef>
#include <cstdint>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>

namespace dp {
namespace matrix_multiply {

namespace iter {
class Solution {
public:
    int64_t min_multiply(const std::vector<std::tuple<int32_t, int32_t>> &mats) {
        const auto mats_size{mats.size()};
        std::vector<std::vector<int64_t>> times(mats_size, std::vector<int64_t>(mats_size, 0x3f3f3f3f));
        // i < j, times[i][j] = min of matrix multiply times between i to j
        for (auto iter{0ull}; iter < mats_size; ++iter) {
            times[iter][iter] = 0; //
        }
        const auto func = [&mats](size_t i, size_t j, size_t k) {
            const auto [fstCol, fstRow] = mats[i];
            const auto [sndCol1, sndRow1] = mats[j];
            const auto [trdCol, trdRow] = mats[k];
            return fstCol * sndRow1 * trdRow;
        };
        // k-i>j-1-i , k-i>k-j,所以可以从右上的行到左下角,一行行的获取
        for (size_t i{mats_size - 1}; i != 0; --i) { // 代表左上到右下一行的元素数量
            const auto step = mats_size - i; // 代表一步的步长
            for (size_t j{0}; j + step < mats_size; ++j) { // 确保最后一步不越界
                const auto x = j;
                const auto y = j + step;
                for (size_t k{x}; k < y; ++k) {// 代表中间点
                    const auto sums = times[x][k] + times[k + 1][y] + func(x, k, y);
                    if (sums < times[x][y]) {
                        times[x][y] = sums;
                    }
                }
            }
        }
        return times[0].back();
    }
};
}
const auto higherFunction = [](const auto &mats) {
    return [&mats](size_t i, size_t j, size_t k) {
        const auto [fstCol, fstRow] = mats[i];
        const auto [sndCol1, sndRow1] = mats[j];
        const auto [trdCol, trdRow] = mats[k];
        return fstCol * sndRow1 * trdRow;
    };
}; // lambda表达式我的超人
namespace rec {
class Solution {
private:
    int64_t min_multiply_helper(size_t x, size_t y, std::vector<std::vector<int64_t>> &dp,
                                const std::function<int64_t(size_t, size_t, size_t)> &func) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }
        int64_t value{0x3f3f3f3f};
        for (size_t k{x}; k < y; ++k) {
            value = std::min(value,
                             min_multiply_helper(x, k, dp, func) +
                             min_multiply_helper(k + 1, y, dp, func) +
                             func(x, y, k)

            );
        } // 递归实现,简单易懂
        dp[x][y] = value;
        return value;
    }

public:
    int64_t min_multiply(const std::vector<std::tuple<int32_t, int32_t>> &mats) {
        const auto mats_size{mats.size()};
        std::vector<std::vector<int64_t>> dp(mats_size, std::vector<int64_t>(mats_size, 0));
        for (size_t iter{0}; iter < mats_size; ++iter) {
            dp[iter][iter] = 1;
        }
        return min_multiply_helper(0, mats_size - 1, dp, higherFunction(mats));
    }
};
}

}
}
