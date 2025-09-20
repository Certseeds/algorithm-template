// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:04:08
 * @LastEditors  : nanoseeds
 */
#include "number.h"

Number Number::operator++() { // 前缀
    return Number(++number);
}

Number Number::operator++(int) {
    return Number(number++);
}

Number Number::operator--() { // 前缀
    return Number(--number);
}

Number Number::operator--(int) {
    return Number(number--);
}

std::ostream &operator<<(std::ostream &os, const Number &other) {
    os << "x = " << other.number;
    return os;
}
