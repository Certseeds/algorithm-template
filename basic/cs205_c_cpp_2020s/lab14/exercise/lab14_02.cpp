// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-05-23 11:16:48
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

template<typename T1>
void useMatrixTemplate(Matrix<T1> &M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]);

int main() {
    string str1[MAXROWS][MAXCOLS]
            {
                    {"Congra", "y",   "ar"},
                    {"alm",    "don", "La"}
            };
    string str2[MAXROWS][MAXCOLS]
            {
                    {"tulations", "ou",    "e"},
                    {"ost",       "e the", "b!"}
            };
    int num1[MAXROWS][MAXCOLS]
            {
                    {1, 2, 3},
                    {4, 5, 6}
            };
    int num2[MAXROWS][MAXCOLS]
            {
                    {6, 5, 4},
                    {3, 2, 1}
            };
    double dou1[MAXROWS][MAXCOLS]
            {
                    {1.6f, 2.5f, 3.4f},
                    {4.3f, 5.2f, 6.1f}
            };
    double dou2[MAXROWS][MAXCOLS]
            {
                    {6.1f, 5.2f, 4.3f},
                    {3.4f, 2.5f, 1.6f}
            };
    Matrix<string> stringMatrix;
    Matrix<int> intMatrix;
    Matrix<double> doubleMatrix;
    cout << "\nDemonstrating with string matrix:" << endl;
    useMatrixTemplate(stringMatrix, str1, str2);
    cout << "\nDemonstrating with int matrix:" << endl;
    useMatrixTemplate(intMatrix, num1, num2);
    cout << "\nDemonstrating with double matrix:" << endl;
    useMatrixTemplate(doubleMatrix, dou1, dou2);
    cout << "\n" << endl;
    return 0;
}

template<typename T1>
void useMatrixTemplate(Matrix<T1> &M, T1 array1[][MAXCOLS], T1 array2[][MAXCOLS]) {
    M.setMatrix(array1);
    cout << "\nMatrix set to first array" << endl;
    M.printMatrix();
    M.addMatrix(array2);
    cout << "\nMatrix incremented by second array" << endl;
    M.printMatrix();
}
