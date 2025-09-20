// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <numeric>

namespace leetcode_985 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> sumEvenAfterQueries(vector<int32_t> &nums, const vector<vector<int32_t>> &queries) {
        vector<int32_t> willreturn;
        vector<int32_t> mut_nums{nums};
        willreturn.reserve(queries.size());
        int32_t sums{0};
        for (const auto num: mut_nums) {
            sums += ((num % 2 == 0) ? num : 0);
        }
        for (const auto &query: queries) {
            //for (int32_t i{0}; i < queries.size(); i++) {
            const auto val{query[0]};
            const auto index{query[1]};
            const auto lastIdx{mut_nums[index]};
            if (lastIdx % 2 == 0) {
                if (val % 2 == 0) {
                    sums += val;
                } else {
                    sums -= lastIdx;
                }
            } else if (val % 2 != 0) {
                sums += (lastIdx + val);
            }
            mut_nums[index] += val;
            willreturn.push_back(sums);
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
