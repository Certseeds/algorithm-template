
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1392 {
#endif

using std::string;
using std::vector;

class Solution {
private:
    string longestPrefix_naive(const string &s) {
        int32_t count{0};
        for (int32_t i{0}; i < s.size() - 1; i++) {
            if (0 == std::memcmp(&s[0], &s[s.size() - 1 - i], (i + 1))) {
                count = i + 1;
            }
        }
        return s.substr(0, count);
    }

    string longestPrefix_hash(const string &s) {
        size_t count{0};
        constexpr const auto prime{1000'000'007}, prime2{1000'000'009};
        size_t hashPrefix{0}, hashPostfix{0}, hashMultiply{1};
        size_t hashPrefix2{0}, hashPostfix2{0}, hashMultiply2{1};
        for (size_t i{0}; i < s.size() - 1; i++) {
            hashPrefix = (hashPrefix * 26 + s[i]) % prime;
            hashPrefix2 = (hashPrefix2 * 26 + s[i]) % prime2;
            hashPostfix = (hashPostfix + (s[s.size() - 1 - i]) * hashMultiply) % prime;
            hashPostfix2 = (hashPostfix2 + (s[s.size() - 1 - i]) * hashMultiply2) % prime2;
            hashMultiply = (hashMultiply * 26) % prime;
            hashMultiply2 = (hashMultiply2 * 26) % prime2;
            if (hashPrefix == hashPostfix && hashPrefix2 == hashPostfix2) { // 双哈希
                count = i + 1;
            }
        }
        return s.substr(0, count);
    }

public:
    string longestPrefix(const string &s) {
        return longestPrefix_hash(s);
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
