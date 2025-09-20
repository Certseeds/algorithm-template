// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

namespace leetcode_914 {
using std::array;
using std::unordered_map;
using std::unordered_set;
using std::vector;
#endif

class Solution {
private:
    void getPrime(int32_t value, unordered_map<int32_t, size_t> &uset) {
        for (int32_t begin{2}; begin <= value; ++begin) {
            if (value % begin == 0) {
                ++uset[begin];
            }
        }
    }

public:
    bool hasGroupsSizeX(const vector<int32_t> &deck) {
        if (deck.size() < 2) {
            return false;
        }
        int maxv{0};
        unordered_map<int32_t, int32_t> umap;
        for (const auto i: deck) {
            umap[i]++;
            maxv = std::max(umap[i], maxv);
        }
        unordered_map<int32_t, size_t> umap2;
        for (const auto [key, value]: umap) {
            getPrime(value, umap2);
        }
        return std::any_of(umap2.cbegin(), umap2.cend(), [&umap](std::pair<int32_t, size_t> pai) {
            return pai.second == umap.size();
        });
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
