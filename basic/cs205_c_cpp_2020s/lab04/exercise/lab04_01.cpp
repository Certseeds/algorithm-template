// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include "pizza.hpp"

using std::cin;
using std::cout;
using std::endl;

int sub_main_04_01();

#ifndef UNIT_TESTING_LAB_04
#define UNIT_TESTING_LAB_04

int main() {
    const int32_t will_return = sub_main_04_01();
    cin.get();
    cin.get();
    return will_return;
}

#endif // !UNIT_TESTING_LAB_04

int sub_main_04_01() {
    char *pizza_company = new char[lab04_01_max_length];
    memset(pizza_company, '\0', lab04_01_max_length);
    double diameter = 0.0f;
    double weight = 0.0f;
    cout << "Input name of the pizza : ";
    cin.getline(pizza_company, lab04_01_max_length);
    cout << "Input the diameter of pizza : ";
    cin >> diameter;
    cout << "Input the weight of pizza : ";
    cin >> weight;
    const auto *const pz = new pizza(pizza_company, diameter, weight);
    cout << "Name of the pizza : ";
    cout << pz->name << endl;
    cout << "diameter of the pizza : ";
    cout << (*(pz->diameter)) << endl;
    cout << "weight of the pizza : ";
    cout << (*(pz->weight)) << endl;
    delete pz;
    delete[] pizza_company;
    return 0;
}
