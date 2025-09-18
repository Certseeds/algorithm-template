// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/

#include <vector>
#include <string>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_91 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    int32_t numDecodings(const string &str) {
        const auto str_size{str.size()};
        if (str_size == 1) {
            return '1' <= str[0] && str[0] <= '9';
        }
        vector<int32_t> dp(str_size + 1, 0);
        dp[0] = 1; // 前0个字符 有且只有一种编码方式
        dp[1] = '1' <= str[0] && str[0] <= '9'; // 第一个字符需要在[1,9]
        for (size_t i{2}; i <= str_size; i++) {
            const auto nowChar{str[i - 1]};
            const auto lastChar{str[i - 2]};
            if ('1' <= nowChar && nowChar <= '9') {
                dp[i] += dp[i - 1];
            }
            const auto combine{(lastChar - '0') * 10 + (nowChar - '0')};
            if (10 <= combine && combine <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
