// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

namespace leetcode_1002 {
using std::array;
using std::string;
using std::vector;
#endif

class Solution {
public:
    vector<string> commonChars(const vector<string> &words) {
        static constexpr const size_t chars{26};
        array<uint8_t, chars> arr{0};
        std::fill(arr.begin(), arr.end(), 100);
        for (const auto &word: words) {
            array<uint8_t, chars> nums{0};
            for (const auto &ch: word) {
                ++nums[ch - 'a'];
            }
            for (size_t i{0}; i < chars; ++i) {
                arr[i] = std::min(nums[i], arr[i]);
            }
        }
        vector<string> will_return{};
        for (char i{'a'}; i <= 'z'; ++i) {
            const auto ch = arr[i - 'a'];
            for (size_t j{1}; j <= ch; j++) {
                will_return.push_back(string{i});
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
