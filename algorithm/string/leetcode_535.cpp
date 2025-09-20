// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#include <string>
#include <unordered_map>

#ifdef CS203_DSAA_TEST_MACRO
namespace leetcode_535 {
using std::string;
using std::unordered_map;
#endif

class Solution {
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
    static constexpr const char *const chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static constexpr const size_t url_len = 6;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (long_to_short.count(longUrl)) {
            return long_to_short[longUrl];
        }
        string shortUrl;
        do {
            shortUrl = "http://tinyurl.com/";
            for (size_t i = 0; i < url_len; ++i) {
                shortUrl += chars[rand() % 62];
            }
        } while (short_to_long.count(shortUrl));
        long_to_short[longUrl] = shortUrl;
        short_to_long[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
