// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <string>
#include <array>
#include <cstdint>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_771 {
using std::string;
using std::array;
#endif

class Solution {
public:
    int numJewelsInStones(const string &jewels, const string &stones) {
        std::array<uint8_t, 256> umap{false};
        int count = 0;
        for (const auto jewel: jewels) {
            umap[jewel] = true;
        }
        for (const auto stone: stones) {
            count += (umap[stone]);
        }
        return count;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
