// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace leetcode_890 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    bool match(const string &word, const string &pattern) {
        const auto word_size{word.size()};
        if (word_size != pattern.size()) {
            return false;
        }
        std::array<int32_t, 26> charCount{0};
        for (const auto ch: pattern) {
            charCount[ch - 'a']++;
        }
        std::array<int32_t, 26> mapToPattern{0}, patternToMap{0};

        for (size_t i{0}; i < word_size; ++i) {
            const auto ch_order = word[i] - 'a';
            const auto pattern_order = pattern[i] - 'a';
            if (mapToPattern[ch_order] == 0 && patternToMap[pattern_order] == 0) {
                mapToPattern[ch_order] = pattern_order + 1;
                patternToMap[pattern_order] = ch_order + 1;
            }
            if (mapToPattern[ch_order] == 0) {
                return false;
            }
            charCount[mapToPattern[ch_order] - 1] -= 1;
        }
        return std::all_of(charCount.cbegin(), charCount.cend(), [](const auto x) { return x == 0; });
    }

    vector<string> findAndReplacePattern(const vector<string> &words, const string &pattern) {
        vector<string> will_return{};
        std::array<int32_t, 26> charCount{0};
        for (const auto ch: pattern) {
            charCount[ch - 'a']++;
        }
        const auto pattern_size{pattern.size()};
        const auto match = [charCount, pattern_size](const string &word, const string &pattern) {
            const auto word_size{word.size()};
            if (word_size != pattern_size) {
                return false;
            }
            std::array<int32_t, 26> charCountT{charCount}, mapToPattern{0}, patternToMap{0};
            for (size_t i{0}; i < word_size; ++i) {
                const auto ch_order = word[i] - 'a';
                const auto pattern_order = pattern[i] - 'a';
                if (mapToPattern[ch_order] == 0 && patternToMap[pattern_order] == 0) {
                    mapToPattern[ch_order] = pattern_order + 1;
                    patternToMap[pattern_order] = ch_order + 1;
                }
                if (mapToPattern[ch_order] == 0) {
                    return false;
                }
                charCountT[mapToPattern[ch_order] - 1] -= 1;
            }
            return std::all_of(charCountT.cbegin(), charCountT.cend(), [](const auto x) { return x == 0; });
        };
        for (const auto &word: words) {
            if (match(word, pattern)) {
                will_return.push_back(word);
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
