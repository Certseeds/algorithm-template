
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>

namespace leetcode_811 {
using std::vector;
using std::string;
using std::unordered_map;
using std::make_pair;
#endif

class Solution {
private:
    inline int32_t getNumber(const string &str) {
        return (std::stoi(str.substr(0, str.find(' '))));
    }

    vector<string> getDomains(string &str) {
        str = (str.substr(str.find(' ') + 1, str.size()));
        vector<string> willreturn{str};
        while (count(str.begin(), str.end(), '.') != 0) {
            str = str.substr(str.find('.') + 1, str.size());
            willreturn.push_back(str);
        }
        return willreturn;
    }

public:
    vector<string> subdomainVisits(const vector<string> &cpd) {
        vector<string> willreturn;
        unordered_map<string, int> umaps;
        const auto m = cpd.size();
        if (m == 0) {
            return willreturn;
        }
        for (size_t i{0}; i < m; ++i) {
            string element = cpd[i];
            const auto number = getNumber(element);
            vector<string> domain = getDomains(element);
            const auto n = domain.size();
            for (size_t j{0}; j < n; ++j) {
                if (umaps.count(domain[j]) == 0) {
                    umaps.insert(make_pair(domain[j], number));
                } else {
                    umaps[domain[j]] += number;
                }
            }
        }
        for (auto &umap: umaps) {
            willreturn.push_back(std::to_string(umap.second) + " " + umap.first);
        }
        return willreturn;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
