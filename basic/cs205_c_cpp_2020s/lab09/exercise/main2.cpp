// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 10:27:24
 * @LastEditors  : nanoseeds
 */
#include "CandyBar.h"
#include <iostream>
#include <string>

int main() {
    CandyBar *cb = new CandyBar[5];
    uint32_t number;
    std::cout << "Please enter the number of candybar:" << std::endl;
    std::cin >> number;
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        if (0 != setCandyBar(cb[i])) {
            delete[] cb;
            return 0;
        }
    }
    for (uint32_t i = 0; i < number; ++i) {
        std::cout << "CandyBar[" << i << "]" << std::endl;
        showCandyBar(cb[i]);
    }
    delete[] cb;
    return 0;
}
