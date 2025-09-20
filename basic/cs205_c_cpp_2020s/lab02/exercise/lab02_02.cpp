/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:33
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-28 16:19:14
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

static constexpr const int32_t hours_number = 24;
static constexpr const int32_t minute_number = 60;
static constexpr const int32_t second_number = 60;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int sub_main_02_02();

#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02

int main() {
    const int32_t will_return = sub_main_02_02();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_02

int sub_main_02_02() {
    int64_t seconds = 0;
    while (0 == seconds || cin.fail()) {
        cout << "Enter the number of Seconds:";
        cin >> seconds;
        if (0 != seconds) {
            cout << seconds;
        }
        cin.clear();
        cin.ignore(INT8_MAX, '\n');
        cin.sync();
    }
    int64_t days = seconds / (hours_number * minute_number * second_number);
    seconds = seconds % (hours_number * minute_number * second_number);
    int64_t hours = seconds / (minute_number * second_number);
    seconds %= (minute_number * second_number);
    int64_t minutes = seconds / second_number;
    seconds %= second_number;
    cout << " " << "seconds = " << days << " days, " << hours;
    cout << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
    return 0;
}
