// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 11:31:19
 * @LastEditors  : nanoseeds
 */
#include "c_cube_lab13_02.h"
#include "c_sphere_lab13_03.h"
#include <iostream>

int main() {
    CCube a_cube{4.0f, 5.0f, 6.0f};
    CSphere c_sphere{7.9f};
    CStereoShape *p = &a_cube;
    p->Show();
    p = &c_sphere;
    p->Show();
    std::cout << CStereoShape::GetNumOfObject();
    return 0;
}
