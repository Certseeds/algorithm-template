// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <algorithm>

namespace leetcode_27 {
using std::vector;
#endif

class Solution {
public:
    int32_t removeElement(vector<int32_t> &vec, int32_t val) {
        vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
        return vec.size();
    }

    int32_t removeElement2(vector<int32_t> &vec, int32_t val) {
        const size_t vec_size{vec.size()};
        int32_t order{0};
        for (size_t begin{0}; begin < vec_size; begin++) {
            if (vec[begin] != val) {
                vec[order] = vec[begin];
                order++;
            }
        }
        vec.resize(order);
        return order;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
