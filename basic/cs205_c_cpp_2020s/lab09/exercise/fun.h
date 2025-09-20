// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-18 09:07:41
 * @LastEditors  : nanoseeds
 */
#ifndef CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
#define CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H

// copy with reference notation
void CopyArray(double(&target)[5], double (&source)[5]);

// copy with pointer notation
void CopyArray(double *target, const double *source, int len);

// copy with two pointers
void CopyArray(double *target, const double *source_start, const double
*source_end);

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int
len);

#endif //CS205_C_CPP_LAB09_EXERCISE_QUESTION1_FUN_H
