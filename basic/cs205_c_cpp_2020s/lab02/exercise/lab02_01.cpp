/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-02-28 07:49:01
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-28 09:59:17
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <vector>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int sub_main_02_01();

#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02

int main() {
    const int32_t will_return = sub_main_02_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_02

int sub_main_02_01() {
    cout << "Result:" << endl;
    printf("%-2s%-s %-2s%s  %s%-5s%s\n", "x", "value",
           "y", "value", "Expressions", " ", "Result");
    //cout << "x value y value  Expressions   Result"<<endl;
    static constexpr const int x = 10;
    static constexpr const int y = 5;
    static constexpr const char *const str1[5]{"y+3", "y-2", "y*5", "x/y", "x%y"};
    vector<int> str2{y + 3, y - 2, y * 5, x / y, x % y};
    for (int i = 0; i < 5; i++) {
        printf("%-3d|%4s%-2d|%6s", x, " ", y, " ");
        printf("x=%-14s|x=%-4d", str1[i], str2[i]);
        cout << endl;
    }
    return 0;
}
