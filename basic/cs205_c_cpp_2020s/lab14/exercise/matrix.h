// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-23 11:20:35
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
#define CS205_C_CPP_LAB14_EXERCISE_MATRIX_H

#include <iostream>
#include <cstdint>

static constexpr const int32_t MAXROWS = 2;
static constexpr const int32_t MAXCOLS = 3;

// header file for lab14_02.cpp
template<typename T>
class Matrix {
private:
    T matrix[MAXROWS][MAXCOLS];
    int32_t rows;
    int32_t cols;
public:
    Matrix();

    void printMatrix();

    void setMatrix(T mat[][MAXCOLS]); //set the Array to what is sent
    void addMatrix(T mat[][MAXCOLS]); //add an array to matrix
    void addMatrix(Matrix otherMatrix);
};

template<typename T>
Matrix<T>::Matrix() {
    rows = MAXROWS;
    cols = MAXCOLS;
}

template<typename T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template<typename T>
void Matrix<T>::setMatrix(T mat[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = mat[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::addMatrix(T mat[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += mat[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::addMatrix(Matrix<T> otherMatrix) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += otherMatrix[i][j];
        }
    }
}

#endif //CS205_C_CPP_LAB14_EXERCISE_MATRIX_H
