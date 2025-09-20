// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 11:08:55
 * @LastEditors  : nanoseeds
 */
#include "c_sphere_lab13_03.h"
#include <cmath>
#include <iostream>

CSphere::CSphere(double rad) {
    this->radius = rad;
}

CSphere::CSphere(const CSphere &CC) {
    this->radius = CC.radius;
}

double CSphere::GetArea() {
    return 4.0f * M_PI * pow(this->radius, 2);
}

double CSphere::GetVolume() {
    return 4.0f / 3.0f * M_PI * pow(this->radius, 3);
}

void CSphere::Show() {
    std::cout << "radius is " << this->radius << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
