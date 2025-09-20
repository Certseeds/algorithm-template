// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 09:07:41
 * @LastEditors  : nanoseeds
 */
#include "fun.h"
#include <iostream>
#include <iomanip>

void CopyArray(double(&target)[5], double (&source)[5]) {
    for (int i = 0; i < 5; ++i) {
        target[i] = source[i];
    }
}

// copy with pointer notation
void CopyArray(double *target, const double *source, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end) {
    for (int i = 0; i <= (source_end - source_start); ++i) {
        target[i] = source_start[i];
    }
}

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len) {
    const int interval = 20;
    std::cout << std::setw(interval) << "target1|" << std::setw(interval)
              << "target2|" << std::setw(interval) << "target3|" << std::endl;
    for (int i = 0; i < len; ++i) {
        std::cout << std::setw(interval - 1) << target1[i] << "|" << std::setw(interval - 1)
                  << target2[i] << "|" << std::setw(interval - 1) << target3[i] << "|" << std::endl;
    }
}
