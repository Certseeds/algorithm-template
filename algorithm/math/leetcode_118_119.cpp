// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_118 {
using std::vector;
#endif

inline vector<int32_t> generate_help(vector<int32_t> vec, size_t order) {
    vector<int32_t> will_return{vec.cbegin(), vec.cend()};
    will_return.push_back(1);
    for (size_t i{1}; i < order; i++) {
        will_return[i] = vec[i - 1] + vec[i];
    }
    return will_return;
}


class Solution {
public:
    vector<vector<int32_t>> generate(int32_t numRows) {
        vector<vector<int32_t>> will_return{};
        vector<int32_t> temp{};
        for (int32_t i{0}; i < numRows; i++) {
            temp = generate_help(temp, i);
            will_return.emplace_back(temp);
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}

namespace leetcode_119 {
using std::vector;
#endif

class Solution119 {
public:
    vector<int32_t> getRow(int32_t rowIndex) {
        vector<int32_t> will_return(rowIndex + 1, 1);
        for (int32_t i{1}; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                will_return[j] += will_return[j - 1];
            }
        }
        return will_return;
    }

    /**
     * C^{N}_{M} = (m!) / ((n!) * (m-n)!)  <br>
     * C^{N+1}_{M} / C^{N}_{M} = (M-N)/(N+1) <br>
     * C^{N+1}_{M} = ((M-N)/(N+1)) * C^{N}_{M}
     * */
    vector<int32_t> getRowN(int32_t rowIndex) {
        vector<int32_t> will_return(rowIndex + 1, 1);
        for (int32_t i{1}; i <= rowIndex; i++) {
            const int64_t temp = static_cast<int64_t>(will_return[i - 1] ) * static_cast<int64_t>(rowIndex + 1 - i) / i;
            will_return[i] = static_cast<int32_t>(temp);
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
