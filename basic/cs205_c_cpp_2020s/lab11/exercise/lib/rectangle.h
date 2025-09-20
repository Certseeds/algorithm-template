// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-30 21:35:56
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
#define CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H


class rectangle {
private:
    double width = 1;
    double height = 1;
public:
    rectangle();

    rectangle(double w, double h);

    double getArea();

    double getPerimeter();

    void display();
};


#endif //CS205_C_CPP_LAB11_EXERCISE_RECTANGLE_H
