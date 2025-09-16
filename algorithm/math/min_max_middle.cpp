// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
#include <random>
#include <cassert>

namespace leetcode_minmax {
using std::vector;
#endif

struct minmax {
    int32_t min, max;

    bool operator==(const minmax &inAx) const {
        return this->min == inAx.min && this->max == inAx.max;
    }
};

class Solution {
public:
    int32_t minV(const vector<int32_t> &values) {
        int32_t minV{std::numeric_limits<int32_t>::max()};
        for (const auto &value: values) {
            minV = std::min(minV, value);
        }
        return minV;
    }

    int32_t maxV(const vector<int32_t> &values) {
        int32_t maxV{std::numeric_limits<int32_t>::min()};
        for (const auto &value: values) {
            maxV = std::max(maxV, value);
        }
        return maxV;
    }

    minmax minMaxV(const vector<int32_t> &values) {
        int32_t minV{std::numeric_limits<int32_t>::max()}, maxV{std::numeric_limits<int32_t>::min()};
        const auto values_size{values.size()}, values_size_{(values_size / 2) * 2};
        if (values_size != values_size_) {
            minV = values.back();
            maxV = values.back();
        }
        for (size_t i{0}; i < values_size_; i += 2) {
            if (values[i] < values[i + 1]) {
                minV = std::min(minV, values[i]);
                maxV = std::max(maxV, values[i + 1]);
            } else {
                minV = std::min(minV, values[i + 1]);
                maxV = std::max(maxV, values[i]);
            }
        }
        return {minV, maxV};
    }

    int32_t partition(vector<int32_t> &values, int32_t begin, int32_t end) {
        const auto x{values[end]};
        auto i{begin - 1};
        for (int32_t j{begin}; j < end; ++j) {
            if (values[j] <= x) {
                i++;
                std::swap(values[i], values[j]);
            }
        }
        std::swap(values[i + 1], values[end]);
        return i + 1;
    }

    int32_t random_partition(vector<int32_t> &values, int32_t begin, int32_t end) {
        std::random_device rd;   // non-deterministic generator
        std::mt19937 gen{rd()};  // to seed mersenne twister.
        std::uniform_int_distribution<> dist{begin, end}; // distribute results between 1 and 6 inclusive.
        const auto i{dist(gen)};
        std::swap(values[end], values[i]);
        return partition(values, begin, end);
    }

    //O(n)复杂度获取 values中 [begin,end]上, (从零开始计数的) ith value
    int32_t middleV(vector<int32_t> &values, int32_t begin, int32_t end, int32_t ith) {

        assert(0 <= begin && begin <= end);
        assert(end < static_cast<int32_t>(values.size()));
        if (begin == end) {
            return values[begin];
        }
        const auto q = random_partition(values, begin, end);
        const auto k{q - begin + 1};
        if (ith == k) {
            return values[q];
        } else if (ith < k) {
            return middleV(values, begin, q - 1, ith);
        }
        return middleV(values, q + 1, end, ith - k);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
