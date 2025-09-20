/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-02-28 09:09:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 08:50:49
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include "CandyBar.h"

using std::cin;
using std::cout;
using std::endl;

int sub_main_03_03();

#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03

int main() {
    const int32_t will_return = sub_main_03_03();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_03

int sub_main_03_03() {
    const CandyBar cb_array[3]{
            {"Mona coke", 3,    31},
            {"Mona coke", 11.2, 45},
            {"Mona coke", 91.1, 92}
    };
    for (const auto &i: cb_array) {
        cout << "Brand: " << i.name << endl;
        cout << "Weight: " << i.weight << endl;
        cout << "Calorie: " << i.calories << endl;
    }
    return 0;
}
