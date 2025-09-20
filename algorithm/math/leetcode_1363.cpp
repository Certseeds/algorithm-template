
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <array>

namespace leetcode_1363 {
using std::vector;
using std::string;
#endif

static inline string removeLastZeros(const string &input) {
    if (input.empty()) {
        return input;
    }
    const auto length{input.length()};
    size_t pre_zeros{0};
    for (size_t i{0}; i < length; i++) {
        if (input[i] == '0') {
            pre_zeros += 1;
        } else {
            break;
        }
    }
    if (pre_zeros == length) {
        return "0";
    }
    const auto will_return{input.substr(pre_zeros, length - pre_zeros)};
    return will_return;
}

class Solution {
public:
    string largestMultipleOfThree(const vector<int32_t> &digits) {
        const auto sums = std::accumulate(digits.begin(), digits.end(), 0);
        if (sums % 3 == 0) {
            string result{};
            vector<int32_t> sorted{digits};
            std::sort(sorted.begin(), sorted.end(), std::greater<>());
            for (const auto &digit: sorted) {
                result += std::to_string(digit);
            }
            return removeLastZeros(result);
        }
        vector<int32_t> triples{}, triples_plusone{}, triples_plustwo{};
        for (const auto &digit: digits) {
            if (digit % 3 == 0) {
                triples.push_back(digit);
            } else if (digit % 3 == 1) {
                triples_plusone.push_back(digit);
            } else {
                triples_plustwo.push_back(digit);
            }
        }
        std::sort(triples_plusone.begin(), triples_plusone.end(), std::greater<>());
        std::sort(triples_plustwo.begin(), triples_plustwo.end(), std::greater<>());

        if (sums % 3 == 1) {
            if (triples_plusone.empty()) {
                if (triples_plustwo.size() < 2) {
                    return {};
                }
                triples_plustwo.pop_back();
                triples_plustwo.pop_back();
            } else {
                triples_plusone.pop_back();
            }
            for (const auto plusone: triples_plusone) {
                triples.push_back(plusone);
            }
            for (const auto plustwo: triples_plustwo) {
                triples.push_back(plustwo);
            }
            std::sort(triples.begin(), triples.end(), std::greater<>());
            string result{};
            for (const auto &digit: triples) {
                result += std::to_string(digit);
            }
            return removeLastZeros(result);
        } else if (sums % 3 == 2) {
            if (triples_plustwo.empty()) {
                if (triples_plusone.size() < 2) {
                    return {};
                }
                triples_plusone.pop_back();
                triples_plusone.pop_back();
            } else {
                triples_plustwo.pop_back();
            }
            for (const auto plusone: triples_plusone) {
                triples.push_back(plusone);
            }
            for (const auto plustwo: triples_plustwo) {
                triples.push_back(plustwo);
            }
            std::sort(triples.begin(), triples.end(), std::greater<>());
            string result{};
            for (const auto &digit: triples) {
                result += std::to_string(digit);
            }
            return removeLastZeros(result);
        }
        return {};
    }

};

class Optimize {
public:
    string largestMultipleOfThree(const vector<int32_t> &digits) {
        const auto sums = std::accumulate(digits.begin(), digits.end(), 0);
        std::array<int32_t, 10> cnt{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (const auto &digit: digits) {
            cnt[digit] += 1;
        }
        if (sums % 3 == 1) {
            if ((cnt[1] + cnt[4] + cnt[7]) >= 1) {
                for (const auto num: {1, 4, 7}) {
                    cnt[num] -= 1;
                    break;
                }
            } else if ((cnt[2] + cnt[5] + cnt[8]) >= 2) {
                for (uint8_t x{0}; x < 2u; x++) {
                    for (const auto num: {2, 5, 8}) {
                        cnt[num] -= 1;
                        break;
                    }
                }
            } else {
                return {};
            }
        } else if (sums % 3 == 2) {
            if ((cnt[2] + cnt[5] + cnt[8]) >= 1) {
                for (const auto num: {2, 5, 8}) {
                    cnt[num] -= 1;
                    break;
                }
            } else if ((cnt[1] + cnt[4] + cnt[7]) >= 2) {
                for (uint8_t x{0}; x < 2u; x++) {
                    for (const auto num: {1, 4, 7}) {
                        cnt[num] -= 1;
                        break;
                    }
                }
            } else {
                return {};
            }
        }
        string result{};
        for (int32_t i{9}; i >= 0; i--) {
            result += std::string(cnt[i], static_cast<char>('0' + i));
        }
        return leetcode_1363::removeLastZeros(result);
    }
};
}
