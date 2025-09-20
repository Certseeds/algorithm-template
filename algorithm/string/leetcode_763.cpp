// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <string>
#include <vector>
#include <array>
#include <algorithm>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_763 {
using std::string;
using std::vector;
using std::array;
#endif

class Solution {
public:
    vector<int32_t> partitionLabels(const string &S) {
        array<size_t, 26> vals{0};
        vector<int32_t> willreturn{};
        for (size_t i{0}; i < S.size(); i++) {
            vals[S[i] - 'a'] = i; // chara -> rightest pos
        }
        for (size_t left{0}, right{0}, i{0}; i < S.size(); i++) {
            right = std::max(right, vals[S[i] - 'a']);
            // this and the next judge means, if the left's range final in here.
            if (right == i) {
                willreturn.push_back(right - left + 1);
                left += willreturn.back();
            }
        }
        return willreturn;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
