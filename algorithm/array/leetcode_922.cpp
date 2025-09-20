// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <vector>
#include <cstdint>
#include <algorithm>

namespace leetcode_922 {
using std::vector;
#endif

class Solution {
public:
    vector<int32_t> sortArrayByParityII(vector<int32_t> &nums) {
        vector<int32_t> will_return{nums};
        const auto nums_size{will_return.size()};
        size_t sing{0};
        int64_t doub{static_cast<int64_t>(nums_size) - 1};
        for (; sing < nums_size && will_return[sing] % 2 == 0; sing += 2) {}
        for (; doub > 0 && will_return[doub] % 2 == 1; doub -= 2) {}
        while (sing < nums_size && doub > 0) {
            std::swap(will_return[sing], will_return[doub]);
            for (; sing < nums_size && will_return[sing] % 2 == 0; sing += 2) {}
            for (; doub > 0 && will_return[doub] % 2 == 1; doub -= 2) {}
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
