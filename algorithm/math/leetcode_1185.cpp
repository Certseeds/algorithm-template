// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <string>
#include <array>
#include <cassert>

namespace leetcode_1185 {
using std::string;

inline constexpr const std::array<const char *const, 7> weekStrs
        {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int32_t getYearDays(int32_t year) {
    assert(1971 <= year & year <= 2100);
    if (year == 2100) {
        return 365;
    }else if (year % 4 == 0) {
        return 366;
    }
    return 365;
}

int32_t getMonthDays(int32_t year, int32_t month) {
    assert(1 <= month & month <= 12);
    const auto yearDays = getYearDays(year);
    if (month == 2 && yearDays == 366) {
        return 29;
    }
    constexpr const std::array<int32_t, 13> monthDays{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 7*31+5*30+28=187+180+28=365
    return monthDays[month];
}
#endif

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1993 08 15 是sunday周日
        // 1993 08 01 是周日
        // 1993 01 01 间隔 31+28+31+30+31+30+31= 212天 %7 == 2天,因此是周五
        // 1971 01 01 间隔 22年,其中有1972,1976,1980,1984,1988,1992六个闰年,所以是22*365+6=7300+730+6=8036天 % 7 = 336 % 7 = 56 % 7 = 0,所以也是周五
        const auto yearDays{[](const auto lastYear) {
            int32_t will_return{0};
            for (auto begin{1971}; begin < lastYear; ++begin) {
                will_return += getYearDays(begin);
            }
            return will_return;
        }(year)};
        const auto monthDays{[](const auto lastMonth, const auto year) {
            int32_t will_return{0};
            for (auto begin{1}; begin < lastMonth; ++begin) {
                will_return += getMonthDays(year, begin);
            }
            return will_return;
        }(month, year)};
        const auto daysDiff{day - 1};
        const auto choice{(yearDays + monthDays + daysDiff + 5) % 7};
        return weekStrs[choice];
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
