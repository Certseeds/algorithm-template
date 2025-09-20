// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-16 14:06:45
 * @LastEditors  : nanoseeds
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using matrix_t = vector<vector<double>>;

double matrix_determinant(const matrix_t &matrix);

double matrix_trace(const matrix_t &matrix);

matrix_t matrix_add(const matrix_t &matrix1, const matrix_t &matrix2);

matrix_t matrix_minus(const matrix_t &matrix1, const matrix_t &matrix2);

matrix_t matrix_sig_multiply(const matrix_t &matrix1, const matrix_t &matrix2);

matrix_t matrix_multiply(const matrix_t &matrix1, const matrix_t &matrix2);

inline bool is_rectangle(const matrix_t &matrix);

bool is_sequre(const matrix_t &matrix);

void get_matrix(matrix_t &matrix, ifstream &file);

void output_matrix(const string &str, const matrix_t &matrix);

int main() {
//    char buf[114514];
//    getcwd(buf, sizeof(buf));
//    printf("current working directory : %s\n", buf);
    std::ifstream file1("./Matrix1.txt");
    std::ifstream file2("./Matrix2.txt");
    if (!file1.is_open() || !file2.is_open()) {
        return -1;
    }
    matrix_t matrix1;
    matrix_t matrix2;
    get_matrix(matrix1, file1);
    get_matrix(matrix2, file2);
    output_matrix("The first matrix is:", matrix1);
    output_matrix("The second matrix is:", matrix2);
    if (!is_rectangle(matrix1) || !is_rectangle(matrix2) ||
        matrix1.size() != matrix2.size() ||
        matrix1.front().size() != matrix2.front().size()) {
        cout << "matrix's size not equal or not sequre" << endl;
    }
    matrix_t addi = matrix_add(matrix1, matrix2);
    output_matrix("The addition of the two matrices is:", addi);
    matrix_t minu = matrix_minus(matrix1, matrix2);
    output_matrix("The subtraction of the two matrices is:", minu);
    matrix_t multip = matrix_multiply(matrix1, matrix2);
    output_matrix("The matrix multiplication of the two matrices is:", multip);
    matrix_t single_multiply = matrix_sig_multiply(matrix1, matrix2);
    output_matrix("The element-wise multiplication of the two matrices is", single_multiply);
    if (is_sequre(matrix1)) {
        cout << "The first matrix is square!" << endl;
        cout << "The determinant of the first matrix is:" << matrix_determinant(matrix1) << endl;
        cout << "The trace of the first matrix is:" << matrix_trace(matrix1) << endl;
    } else {
        cout << "The first matrix is not square!" << endl;
    }
    if (is_sequre(matrix2)) {
        cout << "The second matrix is square!" << endl;
        cout << "The determinant of the second matrix is:" << matrix_determinant(matrix2) << endl;
        cout << "The  trace of the second matrix is:" << matrix_trace(matrix2) << endl;
    } else {
        cout << "The second matrix is not square!" << endl;
    }

    return 0;
}

double matrix_determinant(const matrix_t &matrix) {
    uint32_t size_m = matrix.size();
    if (size_m == 1) {
        return matrix.front().front();
    }
    matrix_t submatrix(size_m - 1, vector<double>(size_m - 1, 0.0f));
    double sum = 0;
    for (uint32_t i = 0; i < size_m; ++i) {
        for (uint32_t j = 0; j < size_m - 1; ++j) {
            for (uint32_t k = 0; k < size_m - 1; ++k) {
                submatrix[j][k] = matrix[(((i > j) ? 0 : 1) + j)][k + 1];
            }
        }
        sum += ((i % 2) ? -1 : 1) * matrix[i].front() * matrix_determinant(submatrix);
    }
    return sum;
}

double matrix_trace(const matrix_t &matrix) {
    double will_return = 0.0f;
    for (uint32_t i = 0; i < matrix.size(); ++i) {
        will_return += matrix[i][i];
    }
    return will_return;
}

matrix_t matrix_multiply(
        const matrix_t &matrix1,
        const matrix_t &matrix2) {
    matrix_t will_return;
    if (!is_sequre(matrix1) || !is_sequre(matrix2)) {
        throw std::invalid_argument("matrix not sequre");
    }
    // m*n,n*p -> m*p
    int32_t m = matrix1.size();
    int32_t n = matrix1.front().size();
    int32_t p = matrix2.front().size();
    will_return = matrix_t(m, vector<double>(p, 0.0f));
    for (int32_t i = 0; i < m; ++i) {
        for (int32_t j = 0; j < p; ++j) {
            for (int32_t k = 0; k < n; ++k) {
                will_return[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    return will_return;
}

inline matrix_t matrix_operator(
        const matrix_t &mat1,
        const matrix_t &mat2,
        const std::function<double(const double &t1, const double &t2)> &func) {
    if (!is_sequre(mat1) ||
        !is_sequre(mat2) ||
        mat1.size() != mat2.size()) {
        throw std::invalid_argument("two matrix do not equal size");
    }
    matrix_t will_return(mat1);
    for (uint32_t i = 0; i < mat1.size(); ++i) {
        std::transform(mat1[i].cbegin(), mat1[i].cend(),
                       mat2[i].cbegin(), will_return[i].begin(), func);
    }
    return will_return;
}

matrix_t matrix_add(
        const matrix_t &matrix1,
        const matrix_t &matrix2) {
    return matrix_operator(matrix1, matrix2, std::plus<>());
}

matrix_t matrix_minus(
        const matrix_t &matrix1,
        const matrix_t &matrix2) {
    return matrix_operator(matrix1, matrix2, std::minus<>());
}

matrix_t matrix_sig_multiply(
        const matrix_t &matrix1,
        const matrix_t &matrix2) {
    return matrix_operator(matrix1, matrix2, std::multiplies<>());
}

void output_matrix(const string &str, const matrix_t &matrix) {
    cout << str << endl;
    for (uint32_t i = 0; i < matrix.size(); ++i) {
        for (uint32_t j = 0; j < matrix[0].size() - 1; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i].back() << endl;
    }
}

inline bool is_sequre(const matrix_t &matrix) {
    if (matrix.size() == 0 || matrix.front().size() == 0) {
        return false;
    }
    for (const auto &i: matrix) {
        if (i.size() != matrix.size()) {
            return false;
        }
    }
    return true;
}

inline bool is_rectangle(const matrix_t &matrix) {
    if (matrix.size() == 0 || matrix.front().size() == 0) {
        return false;
    }
    for (auto iter = matrix.cbegin(); iter != matrix.cend() - 1; ++iter) {
        if (iter->size() != (iter + 1)->size()) {
            return false;
        }
    }
    return true;
}

void get_matrix(matrix_t &matrix, ifstream &file) {
    while (!file.eof()) {
        vector<double> line;
        string temp;
        std::getline(file, temp);
        if (temp.empty()) {
            break;
        }
        vector<int32_t> positive;
        positive.push_back(-1);
        for (uint32_t i = 0; i < temp.size(); ++i) {
            if (' ' == temp[i]) {
                positive.push_back(i);
            }
        }
        positive.push_back(temp.size());
        for (uint32_t i = 0; i < positive.size() - 1; ++i) {
            int32_t temp_size = positive[i + 1] - positive[i];
            string temp2 = temp.substr(positive[i] + 1, temp_size - 1);
            line.push_back(std::atof(temp2.c_str()));
        }
        matrix.push_back(line);
    }
}
