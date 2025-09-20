// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1366 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    string rankTeams(const vector<string> &votes) {
        if (votes.empty() || votes.front().empty()) {
            return {};
        }
        struct sorted {
            std::vector<int32_t> vec_votes{};
            char ch{'A'};
            int16_t count{0};
        };
        const auto votes_size{votes.size()};
        const auto vote_of_each{votes.front().size()};
        constexpr const auto groups{26};
        vector<sorted> voted_array(groups);
        for (size_t i{0}; i < groups; ++i) {
            voted_array[i].ch += i;
            voted_array[i].vec_votes.resize(vote_of_each);
        }
        for (size_t i{0}; i < vote_of_each; ++i) {
            for (size_t j{0}; j < votes_size; ++j) {
                const auto ch{votes[j][i] - 'A'};
                voted_array[ch].vec_votes[i] += 1;
                voted_array[ch].count += 1;
            }
        }
        // or can filter count = 0 in there
        std::sort(voted_array.begin(), voted_array.end(), [vote_of_each](auto obj1, auto obj2) {
            for (size_t i{0}; i < vote_of_each; ++i) {
                if (obj1.vec_votes[i] != obj2.vec_votes[i]) {
                    return obj1.vec_votes[i] > obj2.vec_votes[i];
                }
            }
            return obj1.ch < obj2.ch;
        });
        string will_return{};
        for (const auto &voted: voted_array) {
            if (voted.count != 0) {
                will_return += voted.ch;
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
