// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag array
//@Tag 数组
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_811_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_811_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_811.cpp"

namespace leetcode_811 {
using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_811]", "[test_811]") {
    Solution solution;
    static constexpr const std::array<const char *const, 1> inputs{"9001 discuss.leetcode.com"};
    static constexpr const std::array<const char *const, 3> results{
            "9001 leetcode.com", "9001 discuss.leetcode.com", "9001 com"
    };
    CHECK_THAT((vector<string>{results.cbegin(), results.cend()}),
               UnorderedEquals(solution.subdomainVisits({inputs.cbegin(), inputs.cend()})));
}

TEST_CASE("test case 2 [test_811]", "[test_811]") {
    Solution solution;
    static constexpr const std::array<const char *const, 4> inputs{"900 google.mail.com", "50 yahoo.com",
                                                                   "1 intel.mail.com", "114514 wiki.org"};
    static constexpr const std::array<const char *const, 7> results{
            "901 mail.com", "50 yahoo.com", "900 google.mail.com",
            "114514 wiki.org", "114514 org", "1 intel.mail.com", "951 com"
    };
    CHECK_THAT((vector<string>{results.cbegin(), results.cend()}),
               UnorderedEquals(solution.subdomainVisits({inputs.cbegin(), inputs.cend()})));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_811_TEST_HPP
