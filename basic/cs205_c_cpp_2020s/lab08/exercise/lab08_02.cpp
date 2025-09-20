// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-10 22:52:12
 * @LastEditors  : nanoseeds
 */
#include <iostream>

static constexpr const int32_t max_size = 5;

template<class T>
T max5(T *array) {
    T max_v = array[0];
    for (int32_t i = 1; i < max_size; i++) {
        if (array[i] > max_v) {
            max_v = array[i];
        }
    }
    return max_v;
}

int main() {
    int32_t int_array1[]{159, 73, 778, 5, 75};
    double double_array1[]{1.2, -0.23, 6.32, -11.27, 19.8};
    std::cout << "Max int : " << max5(int_array1) << std::endl;
    std::cout << "Max Double: " << max5(double_array1) << std::endl;
    int32_t int_array2[]{1, 2, 3, 4, 5};
    double double_array2[]{1.1f, 2.0f, 3.0f, 4.0f, 5.5f};
    std::cout << "Max int: " << max5(int_array2) << std::endl;
    std::cout << "Max Double: " << max5(double_array2) << std::endl;
    return 0;
}

