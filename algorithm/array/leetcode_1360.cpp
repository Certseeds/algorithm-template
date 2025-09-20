// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <numeric>
#include <cstdint>
#include <cstddef>
#include <string>
#include <array>

namespace leetcode_1360 {
using std::string;
using std::array;
#endif

static constexpr const std::array<int32_t, 13> days_of_365{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 365};
static constexpr const std::array<int32_t, 13> days_of_366{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 366};

std::array<int32_t, 13> year_days(int32_t year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return days_of_366;
    }
    return days_of_365;
}

class Solution {
public:
    int32_t daysBetweenDates(const string &date1, const string &date2) {
        const auto value = date1.compare(date2);
        if (value > 0) {
            return daysBetweenDates(date2, date1);
        }
        const auto yy1{std::stoi(date1.substr(0, 4))}, yy2{std::stoi(date2.substr(0, 4))};
        const auto mm1{std::stoi(date1.substr(5, 7))}, mm2{std::stoi(date2.substr(5, 7))};
        const auto dd1{std::stoi(date1.substr(8, 10))}, dd2{std::stoi(date2.substr(8, 10))};
        const auto days_of_year1{year_days(yy1)}, days_of_year2{year_days(yy2)};
        const auto days_of_begin1{dd1 + std::accumulate(days_of_year1.begin(), days_of_year1.begin() + mm1 - 1, 0)};
        const auto days_of_begin2{dd2 + std::accumulate(days_of_year2.begin(), days_of_year2.begin() + mm2 - 1, 0)};
        const auto days_between_years = [](int32_t begin, int32_t end) {
            int32_t will_return{0};
            for (int32_t x{begin}; x < end; x++) {
                will_return += year_days(x).back();
            }
            return will_return;
        }(yy1, yy2);
        const auto days = days_between_years + days_of_begin2 - days_of_begin1;
        // 先归零, 统一计算到1月1号有多少天, 然后计算间隔多少year
        return days;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
