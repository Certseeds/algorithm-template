// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 10:25:34
 * @LastEditors  : nanoseeds
 */
#include "CandyBar.h"
#include <iostream>
#include <cstring>

int setCandyBar(CandyBar &snack) {
    while ((getchar()) != '\n');
    char name[40];
    double weight;
    int calorie;
    std::cout << "Enter brand name of a Candy bar: ";
    std::cin.getline(name, Len);
    if (0 == std::strlen(name)) {
        std::cout << std::endl;
        std::cout << "empty name detected!" << std::endl;
        return -1;
    }
    std::cout << "Enter weight name of the candy bar: ";
    std::cin >> weight;
    std::cout << "Enter calories (an integer value) in the candy bar: ";
    std::cin >> calorie;
    std::memcpy(snack.brand, name, Len);
    snack.weight = weight;
    snack.calorie = calorie;
    return 0;
}

void showCandyBar(const CandyBar &snack) {
    std::cout << "Brand: " << snack.brand << std::endl;
    std::cout << "Weight: " << snack.weight << std::endl;
    std::cout << "Calorie: " << snack.calorie << std::endl;
}
