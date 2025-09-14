// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <string>
#include <array>
#include <cstdint>

namespace leetcode_500 {
using std::vector;
using std::string;
using std::array;
#endif


class Solution {
public:
    vector<string> findWords(const vector<string> &words) {
        static constexpr const array<int, 58> chars = {
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
                2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
                1, 3, 1, 3, 1, 3,
                0, 0, 0, 0, 0, 0,
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
                2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
                1, 3, 1, 3, 1, 3};
        const auto words_size{words.size()};
        vector<string> willreturn;
        for (size_t i{0}; i < words_size; i++) {
            bool judge = true;
            for (size_t j{0}, size2{words[i].size() - 1}; j < size2; j++) {
                if (chars[words[i][j] - 65] != chars[words[i][j + 1] - 65]) {
                    judge = false;
                    break;
                }
            }
            if (judge) {
                willreturn.push_back(words[i]);
            }
        }
        return willreturn;
    }
};
}
