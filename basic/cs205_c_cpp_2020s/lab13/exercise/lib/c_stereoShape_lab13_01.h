// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-17 10:28:20
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
#define CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H

inline static constexpr const double M_PI = 3.1415926535897932384;

class CStereoShape {
private:
    inline static int numberOfObject = 0;
    // or static int numberOfObject;
    // && int CStereoShape::numberOfObject = 0;
public:
    CStereoShape();

    virtual ~CStereoShape();

    virtual double GetArea();

    virtual double GetVolume();

    virtual void Show();

    static int GetNumOfObject();

};


#endif //CS205_C_CPP_LAB13_EXERCISE_CSTEREOSHAPE_LAB13_01_H
