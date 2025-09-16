// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <unordered_map>

namespace leetcode_781 {
using std::vector;
using std::unordered_map;
#endif

class Solution {
public:
    int32_t numRabbits(const vector<int32_t> &answers) {
        unordered_map<int32_t, int32_t> umap;
        for (const auto &num: answers) {
            ++umap[num];
        }
        int32_t will_return{0};
        for (const auto &[key, value]: umap) {
            const auto key1 = key + 1;
            will_return += key1 * (value / key1 + static_cast<int32_t>(value % key1 != 0));
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
