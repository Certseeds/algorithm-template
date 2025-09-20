// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:03:28
 * @LastEditors  : nanoseeds
 */
#include "complex.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a is " << a << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * b is " << 2 * b << endl;
    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is" << (b != c) << endl;
    cout << "a==c is" << (a == c) << endl << endl;
    Complex d;
    cout << "Enter a complex number : " << endl;
    cin >> d;
    cout << "d is " << d << endl;
    return 0;
}
