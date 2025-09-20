// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 10:24:28
 * @LastEditors  : nanoseeds
 */
#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H

#include <iostream>

const int Len = 40;
struct CandyBar {
    char brand[Len];
    double weight;
    int calorie;
};

// prompt the user to enter each of the preceding items of information and
// store them in the CandyBar structure
int setCandyBar(CandyBar &snack);

void showCandyBar(const CandyBar &snack);

#endif //EXC_CANDYBAR_H
