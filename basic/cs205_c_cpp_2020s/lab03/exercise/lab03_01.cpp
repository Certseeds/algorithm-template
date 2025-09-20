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
using std::string;

int sub_main_03_01();

#ifndef UNIT_TESTING_LAB_03
#define UNIT_TESTING_LAB_03

int main() {
    const int32_t will_return = sub_main_03_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_03

int sub_main_03_01() {
    const CandyBar snack{"Mocha Munch", 2.3, 350};
    cout << "Brand: " << snack.name << endl;
    cout << "Weight: " << snack.weight << endl;
    cout << "Calorie: " << snack.calories << endl;
    return 0;
}
