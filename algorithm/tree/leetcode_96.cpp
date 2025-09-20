// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <unordered_map>
#include <array>
#include <cstdint>
namespace leetcode_96 {
using std::unordered_map;
#endif

class Solution {
public:
    int32_t numTrees(int32_t n) {
        static unordered_map<int32_t, int32_t> umap;
        if (n <= 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        if (umap.count(n) != 0) {
            return umap[n];
        }
        int32_t will_return{0};
        for (int32_t i{0}; i < n; i++) {
            const auto fir{numTrees(i)};
            umap[i] = fir;
            const auto sec{numTrees(n - i - 1)};
            umap[n - i - 1] = sec;
            will_return += (fir * sec);
        }
        // 这题需要用DP,关键在于 [m,m+k]和[n,n+k] 这两个范围的节点形成的子树完全同构, 数量是一致的,可以复用
        return will_return;
    }
};
constexpr std::array<int32_t, 20> numTreesFunc() {
    std::array<int32_t, 20> arr{1, 1, 2};
    for (size_t i{3}, arr_size{arr.size()}; i < arr_size; i++) {
        int32_t count{0};
        for (size_t j{0}; j < i; j++) {
            count += arr[j] * arr[i - j - 1];
        }
        arr[i] = count;
    }
    return arr;
}

int32_t numTreesConstexpr(int32_t n) {
    // ensure function run in compile time
    static constexpr const std::array<int32_t, numTreesFunc().size()> arr{numTreesFunc()};
    // constexpr,很神奇吧
    return arr[n];
}
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
