// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 11:08:55
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H
#define CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H

#include "c_stereoShape_lab13_01.h"

class CSphere : public CStereoShape {
private:
    double radius{0};
public:
    CSphere() = default;

    explicit CSphere(double rad);

    // 拷贝构造函数 Copy Constructor
    CSphere(const CSphere &CC);

    double GetArea() override;

    double GetVolume() override;

    void Show() override;
};


#endif //CS205_C_CPP_LAB13_EXERCISE_CSPHERE_LAB13_03_H
