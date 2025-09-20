// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include "pizza.hpp"

pizza::pizza() {
    name = new char[lab04_01_max_length];
    memset(name, '\0', lab04_01_max_length);
    diameter = new double;
    weight = new double;
}

pizza::pizza(char *n, double d, double w) {
    name = new char[lab04_01_max_length];
    diameter = new double;
    weight = new double;
    memset(name, '\0', lab04_01_max_length);
    memcpy(name, n, strlen(n) * sizeof(char));
    (*diameter) = d;
    (*weight) = w;
}

pizza::~pizza() {
    delete[] name;
    delete diameter;
    delete weight;
}
