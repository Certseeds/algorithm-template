// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:48:32
 * @LastEditors  : nanoseeds
 */
#include "c_cube_lab13_02.h"
#include <iostream>


CCube::CCube(double len, double wid, double heig) {
    this->length = len;
    this->width = wid;
    this->height = heig;
}

CCube::CCube(const CCube &CC) {
    this->length = CC.length;
    this->width = CC.width;
    this->height = CC.height;
}

double CCube::GetArea() {
    return this->length * this->width * this->height;
}

double CCube::GetVolume() {
    return 2 * this->length * this->width \
 + 2 * this->width * this->height \
 + 2 * this->length * this->height;
}

void CCube::Show() {
    std::cout << "length is " << this->length << "\n";
    std::cout << "width is " << this->width << "\n";
    std::cout << "height is " << this->height << "\n";
    std::cout << "Area is " << this->GetArea() << "\n";
    std::cout << "Volumn is " << this->GetVolume() << "\n";
}
