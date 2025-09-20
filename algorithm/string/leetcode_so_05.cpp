// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <string>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_so_05 {
using std::string;
#endif

class Solution {
public:
    string replaceSpace(const string &str) {
        size_t space{0};
        for (const auto ch: str) {
            if (ch == ' ') {
                space++;
            }
        }
        const auto str_size{str.size()};
        string will_return;
        will_return.resize((space << 1) + str_size);
        for (size_t r{str_size}, r_will{will_return.size() - 1}; r > 0; --r, --r_will) {
            if (str[r - 1] != ' ') {
                will_return[r_will] = str[r - 1];
            } else {
                will_return[r_will] = '0';
                --r_will;
                will_return[r_will] = '2';
                --r_will;
                will_return[r_will] = '%';
            }
        }
        return will_return;
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
