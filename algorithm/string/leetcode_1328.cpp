// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <string>
#include <cstddef>

#ifdef ALGORITHM_TEST_MACRO
namespace leetcode_1328 {
using std::string;
#endif

class Solution {
public:
    string breakPalindrome(const string &palindrome) {
        if (palindrome.size() == 1) {
            return "";
        }
        string will_return{palindrome};
        const auto length{palindrome.size()};
        const auto mid{length / 2};
        const auto addition = (length % 2 == 0 ? 0 : 1);
        for (size_t iter{0}; iter < mid; ++iter) {
            if (will_return[iter] > 'a') {
                will_return[iter] = 'a';
                return will_return;
            }
        }
        for (size_t iter{mid + addition}; iter < length; ++iter) {
            if (will_return[iter] > 'a') {
                will_return[iter] = 'a';
                return will_return;
            }
        }
        for (size_t iter{length}; iter > mid + addition; --iter) {
            if (will_return[iter - 1] == 'a') {
                will_return[iter - 1] = 'b';
                return will_return;
            }
        }
        for (size_t iter{mid}; iter > 0; --iter) {
            if (will_return[iter - 1] == 'a') {
                will_return[iter - 1] = 'b';
                return will_return;
            }
        }
        // will_return[length - 1]='b';
        //    return will_return;
        return "";
    }
};

#ifdef ALGORITHM_TEST_MACRO
}
#endif
