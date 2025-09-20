// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-30 21:35:56
 * @LastEditors  : nanoseeds
 */
#include "rectangle.h"
#include <iostream>
#include <iomanip>

rectangle::rectangle() {

}

rectangle::rectangle(double w, double h) : width(w), height(h) {

}

double rectangle::getArea() {
    return this->width * this->height;
}

double rectangle::getPerimeter() {
    return 2 * (this->width + this->height);
}

void rectangle::display() {
    std::cout << "-------------" << std::endl;
    std::cout << "Width:      " << std::setiosflags(std::ios::left) << this->width << std::endl;
    std::cout << "Height:     " << std::setiosflags(std::ios::left) << this->height << std::endl;
    std::cout << "Area:       " << std::setiosflags(std::ios::left) << this->getArea() << std::endl;
    std::cout << "Perimeter:  " << std::setiosflags(std::ios::left) << this->getPerimeter() << std::endl;
}
