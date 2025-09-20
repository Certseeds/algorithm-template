// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int sub_main_04_03();

#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04

int main() {
    const int32_t will_return = sub_main_04_03();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_04
static constexpr const int32_t lab04_03_range = 5;

int sub_main_04_03() {
    auto *five_array = new int32_t[lab04_03_range];
    int32_t *temp = five_array;
    memset(five_array, 0, lab04_03_range * sizeof(int32_t));
    for (int32_t i = 0; i < lab04_03_range; i++) {
        cout << "Input number " << i << " : ";
        cin >> (*temp);
        temp++;
        cin.get();
    }
    for (int32_t i = 0; i < lab04_03_range; i++) {
        temp--;
        cout << "number " << i << " is : ";
        cout << (*temp) << endl;
    }
    delete[] five_array;
    return 0;
}
