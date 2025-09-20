/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-09 09:57:28
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:48:32
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
#define CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H

#include "c_stereoShape_lab13_01.h"

class CCube : public CStereoShape {
private:
    double length{0.0f};
    double width{0.0f};
    double height{0.0f};
public:
    CCube() = default;

    CCube(double len, double wid, double heig);

    // 拷贝构造函数 Copy Constructor
    CCube(const CCube &CC);

    double GetArea() override;

    double GetVolume() override;

    void Show() override;
};


#endif //CS205_C_CPP_LAB13_EXERCISE_CCUBE_LAB13_02_H
