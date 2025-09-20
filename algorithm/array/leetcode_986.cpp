// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <algorithm>

namespace leetcode_986 {
using std::vector;
#endif

class Solution {
public:
    vector<vector<int32_t>>
    intervalIntersection(const vector<vector<int32_t>> &fst, const vector<vector<int32_t>> &snd) {
        vector<vector<int32_t>> will_return;
        const auto fst_size{fst.size()}, snd_size{snd.size()};
        const auto judgement = [&fst, &snd](size_t pre, size_t post) -> vector<int32_t> {
            const auto &fst_element{fst[pre]}, &snd_element{snd[post]};
            return {std::max(fst_element[0], snd_element[0]),
                    std::min(fst_element[1], snd_element[1])};
        };
        for (size_t x{0}, y{0}, judge{0}; x < fst_size && y < snd_size;) {
            if (fst[x][1] < snd[y][0]) {
                ++x;
            } else if (fst[x][0] > snd[y][1]) {
                ++y;
            } else {
                const vector<int32_t> temp = judgement(x, y);
                will_return.emplace_back(temp);
                judge = ((temp[1] >= fst[x][1]) == 1 ? 1 : 0);
                x += judge;
                y += (1 - judge);
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
