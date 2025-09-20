// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:03:19
 * @LastEditors  : nanoseeds
 */
#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double re, double im) : real(re), imag(im) {}

Complex::Complex(const Complex &s) : Complex(s.real, s.imag) {}

Complex Complex::operator+(const Complex &other) const {
    return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::operator+(double r) const {
    return Complex(this->real + r, this->imag);
}

Complex operator+(double r, const Complex &other) {
    return other + r;
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
}

Complex Complex::operator-(double r) const {
    return Complex(this->real - r, this->imag);
}

Complex operator-(double r, const Complex &other) {
    return Complex(r - other.real, other.imag);
}

Complex Complex::operator*(const Complex &other) const {
    return Complex(this->real * other.real - this->imag * other.imag,
                   this->real * other.imag + this->imag * other.real);
}

Complex Complex::operator*(double r) const {
    return Complex(this->real * r, this->imag * r);
}

Complex operator*(double r, const Complex &other) {
    return other * r;
}

Complex Complex::operator~() const {
    return Complex(this->real, -1 * this->imag);
}

bool Complex::operator==(const Complex &other) const {
    return this->real == other.real && this->imag == other.imag;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &output, const Complex &other) {
    output << other.real << "+" << other.imag << "i";
    return output;
}

std::istream &operator>>(std::istream &in, Complex &other) {
    std::cout << "real: ";
    in >> other.real;
    std::cout << "imaginary: ";
    in >> other.imag;
    return in;
}

