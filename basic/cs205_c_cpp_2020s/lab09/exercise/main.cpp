// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 09:07:31
 * @LastEditors  : nanoseeds
 */
#include "fun.h"

int main() {
    double source[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    double target1[5];
    double *target2 = new double[5];
    double *target3 = new double[5];
    CopyArray(target1, source);
    CopyArray(target2, source, 5);
    CopyArray(target3, source, &source[4]);
    PrintArray((double *) (&target1), target2, target3, 5);
    delete[] target2;
    delete[] target3;
    return 0;
}
