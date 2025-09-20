
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_1408 {
using std::string;
using std::vector;
#endif

class Solution {
public:
    vector<string> stringMatching(const vector<string> &words) {
        vector<string> strs{words};
        std::sort(strs.begin(), strs.end(), [](const string &s1, const string &s2) { return s1.length() < s2.length(); });
        union hashunion {
            struct {
                int32_t hash1{0};
                int32_t hash2{0};
            } twohash;
            int64_t hashnum{};
        };
        std::unordered_set<size_t> uset{};
        std::unordered_set<string> will_return{};
        std::unordered_map<string, int64_t> tohash{};
        std::unordered_map<int64_t, string> fromhash{};
        constexpr const auto hash1{1000'000'007}, hash2{1000'000'009};
        for (const auto &str: strs) {
            hashunion str_hash{};
            for (const auto ch: str) {
                const int64_t one{str_hash.twohash.hash1}, two{str_hash.twohash.hash2};
                str_hash.twohash.hash1 = static_cast<int32_t>((one * 26 + (ch - 'a' + 1)) % hash1);
                str_hash.twohash.hash2 = static_cast<int32_t>((two * 27 + (ch - 'a' + 1)) % hash2);
            }
            const auto &hashnum = str_hash.hashnum;
            tohash[str] = hashnum;
            fromhash[hashnum] = str;
            if (uset.empty()) {
                uset.insert(str.length());
                continue;
            }
            for (const auto &len: uset) {
                if (len == str.length()) {
                    continue;
                }
                hashunion part_hash{};
                int64_t multi1{1}, multi2{1};
                for (size_t i{0}; i < len; i++) {
                    const int64_t one{part_hash.twohash.hash1}, two{part_hash.twohash.hash2};
                    part_hash.twohash.hash1 = static_cast<int32_t>((one * 26 + (str[i] - 'a' + 1)) % hash1);
                    part_hash.twohash.hash2 = static_cast<int32_t>((two * 27 + (str[i] - 'a' + 1)) % hash2);
                    multi1 = (multi1 * 26) % hash1;
                    multi2 = (multi2 * 27) % hash2;
                }
                if (fromhash.count(part_hash.hashnum) != 0) {
                    will_return.insert(fromhash[part_hash.hashnum]);
                }
                for (size_t i{len}; i < str.length(); i++) {
                    const int64_t one{part_hash.twohash.hash1}, two{part_hash.twohash.hash2};
                    part_hash.twohash.hash1 =
                            static_cast<int32_t>(((one * 26 + (str[i] - 'a' + 1)) % hash1 -
                                                  ((str[i - len] - 'a' + 1) * multi1) % hash1) % hash1);
                    if (part_hash.twohash.hash1 < 0) {
                        part_hash.twohash.hash1 += hash1;
                    }
                    part_hash.twohash.hash2 =
                            static_cast<int32_t>(((two * 27 + (str[i] - 'a' + 1)) % hash2 -
                                                  ((str[i - len] - 'a' + 1) * multi2) % hash2) % hash2);
                    if (part_hash.twohash.hash2 < 0) {
                        part_hash.twohash.hash2 += hash2;
                    }
                    if (fromhash.count(part_hash.hashnum) != 0) {
                        will_return.insert(fromhash[part_hash.hashnum]);
                        if (fromhash[part_hash.hashnum] == "auze") {
                            const auto x = 1;
                        }
                    }
                }
            }
            uset.insert(str.length());
        }
        return {will_return.begin(), will_return.end()};
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
