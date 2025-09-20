// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <unordered_set>

namespace leetcode_929 {
using std::unordered_set;
using std::vector;
using std::string;
#endif

class Solution {
private:
    string transfer(const string &str) {
        string re{};
        const auto str_size{str.size()};
        re.resize(str_size);
        for (size_t i{0}, count{0}; i < str_size; ++i) {
            switch (str[i]) {
                case '.': {
                    continue;
                }
                case '+': {
                    for (; i < str_size && str[i] != '@'; ++i) {}
                    --i;
                    break;
                }
                case '@': {
                    for (; i < str_size; ++i, ++count) { re[count] = str[i]; }
                    re.resize(count);
                    return re;
                }
                default: {
                    re[count] = str[i];
                    ++count;
                }
            }
        }
        return "";
    }

public:
    int32_t numUniqueEmails(const vector<string> &emails) {
        unordered_set<string> uset;
        for (const auto &email: emails) {
            uset.insert(transfer(email));
        }
        return uset.size();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
