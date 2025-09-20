/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:50:49
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int sub_main_02_03();

#ifndef UNIT_TESTING_LAB_02
#define UNIT_TESTING_LAB_02

int main() {
    const int32_t will_return = sub_main_02_03();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_02

int sub_main_02_03() {
    char ch = '0';
    int in = -1;
    float fl = 0;
    cout << " Please Enter a Character : ";
    cin >> ch;
    cout << " Please Enter an Integer Value : ";
    cin >> in;
    cout << " Please Enter Float Value : ";
    cin >> fl;
    cout << endl;
    cout << " The variables you entered were : \n";
    cout << " The Character Value that you Entered is : ";
    printf("%c\n", ch);
    cout << " The Integer Value that you Entered is : ";
    printf("%d\n", in);
    cout << " The Float Value that you Entered is : ";
    printf("%f\n", fl);
    return 0;
}
