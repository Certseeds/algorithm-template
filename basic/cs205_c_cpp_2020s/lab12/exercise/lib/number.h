// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-07 22:04:08
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB12_EXERCISE_NUMBER_H
#define CS205_C_CPP_LAB12_EXERCISE_NUMBER_H

#include <iostream>
#include <cstdint>

class Number {
private:
    int64_t number;
public:
    explicit Number() : number(0) {};

    explicit Number(int64_t v) : number(v) {};

    // 拷贝构造函数 Copy Constructor
    Number(const Number &s) = default;

    // 移动构造函数
    Number(Number &&s) = delete;

    // 拷贝赋值运算符 Copy Assignment operator
    Number &operator=(const Number &) = delete;

    // 移动赋值运算符 Move Assignment operator
    Number &operator=(Number &&data) = delete;

    Number operator++();

    Number operator++(int);

    Number operator--();

    Number operator--(int);

    friend std::ostream &operator<<(std::ostream &os, const Number &other);

};


#endif //CS205_C_CPP_LAB12_EXERCISE_NUMBER_H
