// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <functional>

namespace leetcode_893 {
using std::array;
using std::unordered_set;
using std::vector;
using std::string;
#endif

class Solution {
public:
    int numSpecialEquivGroups(const vector<string> &words) {
        struct hasher {
            size_t operator()(const std::array<int32_t, 52> &p) const {
                size_t i{0};
                for (auto t: p) {
                    i = 31 * i + std::hash<int32_t>()(t);
                }
                return i;
            }
        };

        const auto words_size{words.size()};
        if (words_size == 0) {
            return 0;
        }
        unordered_set<array<int32_t, 52>, hasher> will_return{};
        const auto word_size{words.front().size()};
        for (size_t i{0}; i < words_size; ++i) {
            array<int32_t, 52> charElement{0};
            const auto &word = words[i];
            for (size_t j{0}; j < word_size; ++j) {
                charElement[((j % 2) ? 0 : 26) + word[j] - 'a']++;
            }
            will_return.insert(charElement);
        }
        return static_cast<int32_t>(will_return.size());
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
