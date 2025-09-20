// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-02 20:04:25
 * @LastEditors  : nanoseeds
 */
#include <iostream>

int32_t Fill_array(double arr[], int32_t size);

void Show_array(const double *arr, int32_t size);

void Reverse_array(double *arr, int32_t size);

using std::cin;
using std::cout;
using std::endl;

int main() {
    int32_t size;
    cout << "Enter the size of the array: ";
    cin >> size;
    auto *arr = new double[size];
    size = Fill_array(arr, size);
    Show_array(arr, size);
    Reverse_array(arr, size);
    Show_array(arr, size);
    Reverse_array(arr + 1, size - 2);
    Show_array(arr, size);
    delete[] arr;
    return 0;
}

int32_t Fill_array(double arr[], int32_t size) {
    for (int32_t i = 0; i < size; i++) {
        cout << "Enter value #" << (i + 1) << " :";
        cin >> arr[i];
        if (cin.fail()) {
            return i;
        }
    }
    return size;
}

void Show_array(const double *arr, int32_t size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void Reverse_array(double *arr, int32_t size) {
    if (0 >= size) {
        return;
    }
    double temp = *(arr + size - 1);
    *(arr + size - 1) = *arr;
    *arr = temp;
    Reverse_array(arr + 1, size - 2);
}
