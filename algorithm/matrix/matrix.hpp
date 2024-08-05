// SPDX-License-Identifier: AGPL-3.0-or-later
/*  CS203_DSAA_template
    Copyright (C) 2020-2023 nanoseeds Wjia wuyuhao
*/

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_MATRIX_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_MATRIX_HPP

#include <algorithm>
#include <complex>
#include <cstdint>
#include <functional>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>
#include <cmath>
#include "expression_template.hpp"
#include "template_helper.hpp"


#ifdef  _HAVE_OPENCV_

#include <opencv2/opencv.hpp>

#endif
namespace Mat_pro {
#ifdef  _HAVE_OPENCV_
using cv::Mat;
enum class CV_TYPE : int32_t {
    UINT8_T = 0,
    INT8_T = 1,
    UINT16_T = 2,
    INT16_T = 3,
    INT32_T = 4,
    FLOAT32_T = 5,
    FLOAT64_T = 6,
    NO_TYPE = std::numeric_limits<int32_t>::max()
};
#endif

using std::endl, std::pow, std::vector;

static constexpr const double_t eps{0.000001};

struct Matrix_Shape_Not_Match_Exception : public std::exception {
    char will_return[300] = "\0";

    explicit Matrix_Shape_Not_Match_Exception(const char *message, const char *file_name, int32_t Line) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        sprintf_s(will_return, "%s,Shape not Match in %d line , %s file", message, Line, file_name);
#else
        sprintf(will_return, "%s,Shape not Match in %d line , %s file", message, Line, file_name);
#endif
    }

    [[nodiscard]] const char *what() const noexcept override {
        return will_return;
    }
};

/** @related: get from https://blog.csdn.net/qq_31175231/article/details/77479692
 */
using EXPRESSION::Expression;
using OPERATOR::Add, OPERATOR::Minus, OPERATOR::Minimum, OPERATOR::Maximum;
using EXPRESSION::UnOperatorBinary::min, EXPRESSION::UnOperatorBinary::max;

template<typename T>
class Matrix : public Expression<Matrix<T>> {
private:
    vector<vector<T>> vec;
public:

    explicit Matrix() : Matrix(0, 0) {};

    explicit Matrix(int32_t rows, int32_t cols);

    // 拷贝构造函数 Copy Constructor
    Matrix(const Matrix<T> &mat) {
        this->operator=<Matrix<T>>(mat);
    }

    Matrix<T> &operator=(const Matrix<T> &mat) {
        this->operator=<Matrix<T>>(mat);
        return *this;
    }

    // 拷贝赋值运算符 Copy Assignment operator
    template<typename ExpType>
    Matrix(const Expression<ExpType> &src) {
        this->operator=<ExpType>(src);
    }

    template<typename ExpType>
    Matrix<T> &operator=(const Expression<ExpType> &src) {
        const ExpType &srcReal = src.cast();
        this->vec.resize(srcReal.rows());
        for (size_t i{0}; i < srcReal.rows(); i++) {
            this->vec[i].resize(srcReal.cols());
            for (size_t j{0}; j < srcReal.cols(); j++) {
                this->vec[i][j] = srcReal.value(i, j); // binary expression value work function
            }
        }
        return *this;
    }

    // 移动构造函数运算符 Move Constructor
    Matrix(Matrix<T> &&mat) noexcept {
        this->operator=<Matrix<T>>(mat);
        mat.vec.resize(0);
    }

    template<typename ExpType>
    Matrix(Expression<ExpType> &&src) {
        this->operator=<ExpType>(src);
    }

    // 移动赋值运算符 Move Assignment operator
    Matrix<T> &operator=(Matrix<T> &&mat) noexcept {
        Matrix<T> &temp = this->operator= <Matrix<T>>(mat);
        mat.vec.resize(0);
        return temp;
    }

    template<typename ExpType>
    Matrix<T> &operator=(Expression<ExpType> &&src) {
        if (this == reinterpret_cast<Matrix<T> *>(&src)) {
            return *this;
        }
        const ExpType &srcReal = src.cast();
        this->vec.resize(srcReal.rows());
        for (size_t i{0}; i < srcReal.rows(); i++) {
            this->vec[i].resize(srcReal.cols());
            for (size_t j{0}; j < srcReal.cols(); j++) {
                this->vec[i][j] = srcReal.value(i, j); // binary expression value work function
            }
        }
        return *this;
    }

    // computing function
    T value(size_t i, size_t j) const { return vec[i][j]; }

    explicit Matrix<T>(const vector<vector<T>> &vec) {
        this->vec = vector<vector<T >>(vec);
    }

    explicit Matrix<T>(vector<vector<T>> &&vec) {
        this->vec = std::move(vec);
    }

    explicit Matrix<T>(const std::initializer_list<std::initializer_list<T>> &list);

    // only for
    explicit Matrix<T>(const std::initializer_list<T> &list);

    inline T get_inside(int32_t rows, int32_t cols) const;

    static Matrix<T> zeros(int32_t rows, int32_t cols);

    static Matrix<T> ones(int32_t rows, int32_t cols);

    static Matrix<T> values(int32_t rows = 0, int32_t cols = 0, T = static_cast<T>(0));

    static Matrix<T> eye(int32_t s);

    static Matrix<T> eye_value(int32_t s, T t);

    static bool inside_equal(const Matrix<T> &mat1, const Matrix<T> &mat2);

    friend std::ostream &operator<<(std::ostream &output, const Matrix<T> &mat) {
        for (const auto &i: mat.vec) {
            for (const auto &j: i) {
                output << j << " ";
            }
            output << endl;
        }
        return output;
    }

    [[nodiscard]] inline size_t rows() const;

    [[nodiscard]] inline size_t cols() const;

    Matrix<T> transpose() const;

    ~Matrix() = default;

    [[nodiscard]] inline bool is_empty() const;

    [[nodiscard]] inline bool is_square() const { return this->rows() == this->cols(); };

    inline static Matrix<T>
    operator_table(const Matrix<T> &mat1, const Matrix<T> &mat2,
                   const std::function<T(const T &t1, const T &t2)> &func);

    typename vector<T>::const_iterator get_row_iter_begin(size_t rows) const;

    typename vector<T>::const_iterator get_row_iter_end(size_t rows) const;

    /**@related: https://stackoverflow.com/questions/30736951/templated-class-check-if-complex-at-compile-time
             * */
    Matrix<T> conj() const;

    T max() const;

    T min() const;

    T sum() const;

    template<typename T1 =T>
    requires (!is_complex<T1>)
    auto avg() {
        static_assert(!is_complex<T1>, "Divide_Result_t<T1, double_t> avg()");
        T1 sums = this->sum();
        return sums / static_cast<double_t>(this->rows() * this->cols());
    }

    template<is_complex T1 = T>
    auto avg() const {
        static_assert(is_complex<T1>, "T1 avg()");
        T1 sums = this->sum();
        const auto size = static_cast<double_t>(this->rows() * this->cols());
        const complex_inside_t<T1> real = sums.real() / size;
        const complex_inside_t<T1> imag = sums.imag() / size;
        return T1{real, imag};
    }

    T row_max(int32_t row) const;

    T col_max(int32_t col) const;

    T row_min(int32_t row) const;

    T col_min(int32_t col) const;

    T row_sum(int32_t row) const;

    T col_sum(int32_t col) const;

    template<typename T1 = T>
    requires (!is_complex<T1>)
    auto row_avg(int32_t row) -> divide_t<T1> const {
        if (row > this->rows()) {
            return -1;
        }
        return this->row_sum(row) / static_cast<double_t>(this->cols());
        //        return 1;
    }

    template<is_complex T1 = T>
    T1 row_avg(int32_t row) const {
        if (row > this->rows() || this->is_empty()) {
            return static_cast<T1>(-1);
        }
        T1 sums = this->row_sum(row);
        const auto col = static_cast<double_t>(this->cols());
        const complex_inside_t<T1> real = sums.real() / col;
        const complex_inside_t<T1> imag = sums.imag() / col;
        return T1{real, imag};
        // return std::complex(static_cast<double>(2), static_cast<double >(3));
    }

    template<typename T1 = T>
    requires (!is_complex<T1>)
    auto col_avg(int32_t col) -> divide_t<T1> const {
        if (col <= 0 || col > this->cols()) {
            return -1;
        }
        return this->col_sum(col) / static_cast<double>(this->rows());
    }

    template<is_complex T1 = T>
    T1 col_avg(int32_t col) const {
        if (col <= 0 || col > this->cols()) {
            return -1;
        }
        const T1 sums = this->col_sum(col);
        const auto size = static_cast<double_t>(this->rows());
        const complex_inside_t<T1> real = sums.real() / size;
        const complex_inside_t<T1> imag = sums.imag() / size;
        return T1{real, imag};
    }

    T dot(const Matrix<T> &mat2);

    T trace() const;

    T determinant() const;

    Matrix<T> inverse() const;//逆

    Matrix<T> convolution(const Matrix<T> &kernel, int32_t padding = 0, int32_t stride = 1) const;

    [[nodiscard]] Matrix<T>
    convolution_mul(const Matrix<T> &kernel, int32_t padding = 0, int32_t stride = 1, int32_t demension = 1) const;

    Matrix<T> reshape(int32_t row, int32_t col) const;                              //重整
    Matrix<T> slice(int32_t row1, int32_t row2) const;                              //切片
    Matrix<T> slice(int32_t row1, int32_t row2, int32_t col1, int32_t col2) const;  //切片


    vector<vector<double_t>> transform() const;

    Matrix<double_t> Householder(int32_t col, int32_t ele) const;

    Matrix<double_t> Hessenberg() const;

    Matrix<double_t> Givens(int32_t col, int32_t begin, int32_t end) const;

    Matrix<double_t> QR_iteration() const;

    vector<double_t> eigenvalue() const;

    // Matrix<double_t> LU_decomposition() const;

    Matrix<double_t> Gauss() const;

    Matrix<double_t> row_elimination(int32_t row, double_t ele) const;

    Matrix<double_t> row_elimination(int32_t row, int32_t col, int32_t remove_row) const;

    Matrix<T> row_exchange(int32_t row1, int32_t row2) const;

    Matrix<double_t> Elimination() const;

    inline Matrix<double_t> Nullspace() const;

    Matrix<double_t> eigenvector() const;

    Matrix<T> joint(Matrix<T> matrix) const;

    Matrix<T> mul(const Matrix<T> &mat2);

    /**
     * Matrix / number, return a Matrix.
     * same type.
     * */
    Matrix<T> operator/(const T &t2) {
        const auto func = [t2](const T &t1) { return t1 / t2; };
        Matrix<T> will_return(this->rows(), this->cols());
        for (size_t i{0}; i < this->rows(); ++i) {
            std::transform(this->vec[i].begin(), this->vec[i].end(), will_return.vec[i].begin(), func);
        }
        return will_return;
    }
};// namespace Mat_pro

template<typename T>
Matrix<T>::Matrix(int32_t rows, int32_t cols) {
    this->vec = vector<vector<T >>(std::max(rows, 0), vector<T>(std::max(cols, 0)));
}


template<typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &list) {
    this->vec = vector<vector<T>>(0);
    for (auto i = list.begin(); i != list.end() - 1; i++) {
        if ((*i).size() != (*(i + 1)).size()) {
            return;
        }
    }
    this->vec = vector<vector<T >>(list.size());
    for (auto i = list.begin(); i != list.end(); i++) {
        this->vec[i - list.begin()] = *i;
    }
}

// only for
template<typename T>
Matrix<T>::Matrix(const std::initializer_list<T> &list) {
    this->vec = vector<vector<T >>(1);
    this->vec[0] = list;
}

template<typename T>
T Matrix<T>::get_inside(int32_t rows, int32_t cols) const {
    return this->vec[rows][cols];
}

template<typename T>
typename vector<T>::const_iterator Matrix<T>::get_row_iter_begin(size_t rows) const {
    if (rows >= this->rows()) {
        return this->vec.front().cbegin();
    }
    return this->vec[rows].cbegin();
}

template<typename T>
typename vector<T>::const_iterator Matrix<T>::get_row_iter_end(size_t rows) const {
    if (rows >= this->rows()) {
        return this->vec.back().cend();
    }
    return this->vec[rows].cend();
}

template<typename T>
inline bool Matrix<T>::is_empty() const {
    return vec.empty() || vec.front().empty();
}

template<typename T>
Matrix<T> Matrix<T>::zeros(int32_t rows, int32_t cols) {
    return Matrix<T>::values(rows, cols, static_cast<T>(0));
}

template<typename T>
Matrix<T> Matrix<T>::ones(int32_t rows, int32_t cols) {
    return Matrix<T>::values(rows, cols, static_cast<T>(1));
}

template<typename T>
Matrix<T> Matrix<T>::values(int32_t rows, int32_t cols, T t) {
    Matrix<T> will_return(rows, cols);
    for (auto &i: will_return.vec) {
        i = vector<T>(cols, t);
    }
    return will_return;
}

template<typename T>
Matrix<T> Matrix<T>::eye_value(int32_t s, T t) {
    Matrix<T> will_return(s, s);
    for (int32_t i{0}; i < s; ++i) {
        will_return.vec[i][i] = t;
    }
    return will_return;
}

template<typename T>
Matrix<T> Matrix<T>::eye(int32_t s) {
    return Matrix<T>::eye_value(s, static_cast<T>(1));
}

template<typename T>
inline Matrix<T> Matrix<T>::operator_table(const Matrix<T> &mat1, const Matrix<T> &mat2,
                                           const std::function<T(const T &t1, const T &t2)> &func) {
    if (!size_equal(mat1, mat2)) {
        throw Matrix_Shape_Not_Match_Exception("two matrix do not equal size", __FILE__, __LINE__);
    }
    Matrix<T> will_return(mat1.rows(), mat1.cols());
    for (size_t i{0}; i < mat1.rows(); ++i) {
        std::transform(mat1.vec[i].begin(), mat1.vec[i].end(),
                       mat2.vec[i].begin(), will_return.vec[i].begin(), func);
    }
    return will_return;
}

template<typename T>
inline size_t Matrix<T>::rows() const {
    return this->vec.size();
}

/**
 * if the it's empty,then is_empty is true,
 * */
template<typename T>
inline size_t Matrix<T>::cols() const {
    if (this->rows() == 0) {
        return static_cast<size_t>(0);
    }
    return this->vec.front().size();
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    if (this->is_empty()) {
        return Matrix<T>();
    }
    Matrix<T> will_return(this->cols(), this->rows());
    for (size_t i{0}; i < this->rows(); ++i) {
        for (size_t j{0}; j < this->cols(); ++j) {
            will_return.vec[j][i] = this->vec[i][j];
        }
    }
    return will_return;
}


template<typename T>
struct number : public Expression<number<T>> {
private:
    T num{};
public:
    explicit number<T>(T t) : num(t) {}

    // work function, computing this expression at position i, import for lazy computing

    T value(size_t i, size_t j) const { return this->num;}

    //before invoke, invoke the ~number
    // 感觉是优化错误

    size_t rows() const { return 0x3f3f3f3f; }

    size_t cols() const { return 0x3f3f3f3f; }
};

template<opencv_type T>
static number<T> make_number(T t){
    return number<T>(t);
}

template<typename T1, typename T2>
inline EXPRESSION::BinaryOp<Add, T1, T2>
operator+(const Expression<T1> &lhs, const Expression<T2> &rhs) {
    return expToBinaryOp<Add>(lhs, rhs);
}

/**
 * matrix + matrix, must equal.
 *  * input mat1,mat2 and will_return's type is same.
 * */


/**
 * matrix - matrix, must equal.
 * input mat1,mat2 and will_return's type is same.
 * */
template<typename T1, typename T2>
inline EXPRESSION::BinaryOp<Minus, T1, T2>
operator-(const Expression<T1> &lhs, const Expression<T2> &rhs) {
    return expToBinaryOp<Minus>(lhs, rhs);
}


/**
 * matrix * number, need T1 can * T2
 * */
template<typename T1, typename T2>
auto operator*(const Matrix<T1> &mat1, const T2 &t2) {
    vector<vector<Multiply_Result_t<T1, T2>>> temp(mat1.rows(), vector<Multiply_Result_t<T1, T2>>(mat1.cols()));
    for (uint32_t i = 0; i < temp.size(); ++i) {
        for (uint32_t j = 0; j < temp[i].size(); ++j) {
            temp[i][j] = mat1.get_inside(i, j) * t2;
        }
    }
    return Matrix<Multiply_Result_t<T1, T2>>(std::move(temp));
}

template<typename T1, typename T2>
auto operator*(const T1 &t1, const Matrix<T2> &mat2) {
    return mat2 * t1;
}

/**
 * matrix * vector
 * @param1: Matrix<T1> m_n
 * @Param2; vector<T2> length is n
 * @return: Matrix<decltype(T1*T2)> m_1,(rows is m,cols is 1)
 * */
template<typename T1, typename T2>
auto operator*(const Matrix<T1> &mat1, const vector<T2> &t2) -> Matrix<Multiply_Result_t<T1, T2>> {
    if (static_cast<unsigned >(mat1.cols()) != t2.size()) {
        throw Matrix_Shape_Not_Match_Exception(
                "shape not match,matrix can not multiply vector", __FILE__, __LINE__);
    }
    vector<vector<Multiply_Result_t<T1, T2>>> temp(1, vector<Multiply_Result_t<T1, T2>>(mat1.rows()));
    for (uint32_t i{0}; i < temp.size(); ++i) {
        temp[0][i] = std::inner_product(mat1.get_row_iter_begin(i), mat1.get_row_iter_end(i), t2.begin(),
                                        static_cast<Multiply_Result_t<T1, T2>>(0));
    }
    return Matrix<Multiply_Result_t<T1, T2>>(std::move(temp));
}

/**
 * matrix * vector
 * @Param1; vector<T1> length is m
 * @param2: Matrix<T2> m_n
 * @return: Matrix<decltype(T1*T2)> 1_n,(rows is 1,cols is n)
 * */
template<typename T1, typename T2>
auto operator*(const vector<T1> &t1, const Matrix<T2> &mat2) -> Matrix<Multiply_Result_t<T1, T2>> {
    if (t1.size() != mat2.rows()) {
        throw Matrix_Shape_Not_Match_Exception(
                "shape not match,vector can not multiply matrix", __FILE__, __LINE__);
    }
    vector<vector<Multiply_Result_t<T1, T2>>> temp(mat2.cols(), vector<Multiply_Result_t<T1, T2>>(1));
    auto transfor = mat2.transpose();
    for (size_t i{0}; i < transfor.rows(); ++i) {
        temp[i][0] = std::inner_product(transfor.get_row_iter_begin(i), transfor.get_row_iter_end(i), t1.cbegin(),
                                        static_cast<Multiply_Result_t<T1, T2>>(0));
    }
    return Matrix<Multiply_Result_t<T1, T2>>(std::move(temp));
}

/**
 *  number * matrix , need T1 can * T2
 * */
// used to  -> Matrix<Multiply_Result_t_Macro> ;


template<typename T>
Matrix<T> operator*(const Matrix<T> &mat1, const Matrix<T> &mat2) {
    if (mat1.cols() != mat2.rows()) {
        throw Matrix_Shape_Not_Match_Exception(
                "shape not match,matrix1 & 2 can not multiply", __FILE__, __LINE__);
    }
    Matrix<T> temp = mat2.transpose();
    vector<vector<T>> will_return(mat1.rows(), vector<T>(mat2.cols()));
    for (size_t i{0}; i < mat1.rows(); ++i) {
        for (size_t j{0}; j < mat2.cols(); ++j) {
            will_return[i][j] = std::inner_product(mat1.get_row_iter_begin(i), mat1.get_row_iter_end(i),
                                                   temp.get_row_iter_begin(j), static_cast<T>(0));
            // transform_reduce can not use.
        }
    }
    return Matrix<T>(std::move(will_return));
}

// Matrix_n_m, Matrix_n_m, result is Matrix_N_M
template<typename T>
Matrix<T> Matrix<T>::mul(const Matrix<T> &mat2) {
    return Matrix<T>::operator_table(*this, mat2, std::multiplies<>());
}

// UNTODO T1 and T2
template<typename T>
T Matrix<T>::dot(const Matrix<T> &mat2) {
    if (!size_equal(*this, mat2)) {
        throw Matrix_Shape_Not_Match_Exception(
                "size do not equal bewtween this and Mat2", __FILE__, __LINE__);
    }
    T will_return(0);
    for (size_t i{0}; i < mat2.rows(); ++i) {
        will_return = std::inner_product(this->get_row_iter_begin(i), this->get_row_iter_end(i),
                                         mat2.get_row_iter_begin(i), will_return);
    }
    return will_return;
}

/**
 * kron
 * @param1: Matrix_m_n T1
 * @param2: Matrix_k_p T2
 * @return: Matrix_(mk)_(np) decltype(T1*T2)
 * */
template<typename T1, typename T2>
auto kron(const Matrix<T1> &mat1, const Matrix<T2> &mat2) -> Matrix<Multiply_Result_t<T1, T2>> {
    vector<vector<Multiply_Result_t<T1, T2>>> will_return(
            mat1.rows() * mat2.rows(), vector<Multiply_Result_t<T1, T2>>(mat1.cols() * mat2.cols()));
    for (size_t i{0}; i < mat1.rows(); ++i) {
        for (size_t j{0}; j < mat1.cols(); ++j) {
            for (size_t k{0}; k < mat2.rows(); ++k) {
                for (size_t m{0}; m < mat2.cols(); ++m) {
                    will_return[i * mat1.rows() + k][j * mat1.cols() + m] =
                            mat1.get_inside(i, j) * mat2.get_inside(k, m);
                }
            }
        }
    }
    return Matrix<Multiply_Result_t<T1, T2>>(std::move(will_return));
}

/**
 * kron
 * @param1: vector_1_3 T1
 * @param2: vector_1_3 T2
 * @return: vector_1_3 decltype(T1*T2)
 * */
template<typename T1, typename T2>
auto cross(const vector<T1> &vec1, const vector<T2> &vec2) -> vector<Multiply_Result_t<T1, T2>> {
    vector<Multiply_Result_t<T1, T2>> will_return(3);
    if (vec1.size() == 3 && vec2.size() == 3) {
        will_return[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
        will_return[1] = vec1[0] * vec2[2] - vec1[2] * vec2[0];
        will_return[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    }
    return std::move(will_return);
}

/**
    * Equal must use to compare two un_empty matrix,
    * so, if one of the matrix is empty , it will be false.
    * only un_empty, rows and columns both equal can be equal.
    */
template<typename T1, typename T2>
bool size_equal(const Matrix<T1> &mat1, const Matrix<T2> &mat2) {
    return !mat1.is_empty() && !mat2.is_empty() \
 && mat1.rows() == mat2.rows() \
 && mat1.cols() == mat2.cols();
}

/** judge is equal
 * @param1: Matrix_m_n T
 * @param2: Matrix_m_n T
 * @return: bool
 * */
template<typename T>
bool Matrix<T>::inside_equal(const Matrix<T> &mat1, const Matrix<T> &mat2) {
    if (!size_equal(mat1, mat2)) {
        return false;
    }
    for (int32_t i{0}; i < mat1.rows(); ++i) {
        if (!std::equal(mat1.vec[i].begin(), mat1.vec[i].end(), mat2.vec[i].begin(), mat2.vec[i].end())) {
            return false;
        }
    }
    return true;
}

template<typename T>
T Matrix<T>::trace() const {
    T will_return{0};
    if (this->is_square()) {
        for (int32_t i{0}; i < this->rows(); ++i) {
            will_return += this->vec[i][i];
        }
    }
    return will_return;
}

template<typename T>
T determinant_in(const vector<vector<T>> &matrix) {
    if (matrix.size() == 1) {
        return matrix.front().front();
    }
    uint32_t size_m = matrix.size();
    vector<vector<T>> submatrix(size_m - 1, vector<T>(size_m - 1, static_cast<T>(0)));
    T will_return(0);
    for (uint32_t i{0}; i < size_m; ++i) {
        for (uint32_t j{0}; j < size_m - 1; ++j) {
            for (uint32_t k{0}; k < size_m - 1; ++k) {
                submatrix[j][k] = matrix[(((i > j) ? 0 : 1) + j)][k + 1];
            }
        }
        will_return += ((i % 2) ? -1 : 1) * matrix[i].front() * determinant_in(submatrix);
    }
    return will_return;
}

template<typename T>
T Matrix<T>::determinant() const {
    if (!this->is_square()) {
        throw Matrix_Shape_Not_Match_Exception(
                "this Matrix is not Squre, can not get determinant", __FILE__, __LINE__);
        //return will_return;
    }
    return determinant_in(this->vec);
}

template<typename T>
Matrix<T> Matrix<T>::inverse() const {
    //可逆条件
    if (this->is_square() && this->rows() > 1 && this->determinant() != 0) {
        static constexpr T zeroNumber{0};
        std::vector<std::vector<T>> result_vector(this->rows(), std::vector<T>(this->cols(), zeroNumber));
        for (size_t i{0}; i < this->rows(); i++) {
            for (size_t j{0}; j < this->cols(); j++) {
                //vector<vector<T>> submatrix(this->rows() - 1, vector<T>(this->cols() - 1, static_cast<T>(0)));
                vector<vector<T >> submatrix(this->vec);
                submatrix.erase(submatrix.begin() + i);
                for (int m{1}; m < this->rows(); ++m) {
                    submatrix[m - 1].erase(submatrix[m - 1].begin() + j);
                }
                result_vector[j][i] =
                        (((i + j) % 2) ? -1 : 1) * determinant_in(submatrix);//子矩阵展开得到伴随矩阵
            }
        }
        Matrix<T> will_return = Matrix<T>{result_vector};
        will_return = will_return / this->determinant();
        //will_return[i][j] = res[i][j] / this->determinant();//逆
        return will_return;
    } else if (this->is_square() && this->rows() == 1 && this->determinant() != 0) {
        return Matrix<T>::values(1, 1, static_cast<T>(1) / this->vec[0][0]);
    }
    return Matrix<T>(1, 1);
}

template<typename T>
Matrix<T> Matrix<T>::conj() const {
    vector<vector<T>> vvc(this->rows(), vector<T>(this->cols()));
    if constexpr (is_complex<T>) {
        for (int32_t i{0}; i < this->rows(); ++i) {
            for (int32_t j{0}; j < this->cols(); ++j) {
                vvc[i][j] = std::conj(this->vec[i][j]);
            }
        }
    } else if constexpr (has_conj<T>) {
        for (int32_t i{0}; i < this->rows(); ++i) {
            for (int32_t j{0}; j < this->cols(); ++j) {
                vvc[i][j] = this->vec[i][j].conj();
            }
        }
    } else if constexpr (!is_complex<T> && !has_conj<T>) {
        vvc = this->vec;
    }
    return Matrix<T>(std::move(vvc));
}

template<typename T>
T Matrix<T>::max() const {
    if (!this->is_empty()) {
        T will_return = this->vec.front().front();
        for (const auto &iter: this->vec) {
            will_return = std::max(*std::max_element(std::begin(iter), std::end(iter)), will_return);
        }
        return will_return;
    }
    return static_cast<T>(0);
}

template<typename T>
T Matrix<T>::min() const {
    if (!this->is_empty()) {
        T will_return = this->vec.front().front();
        for (const auto &iter: this->vec) {
            will_return = std::min(*std::min_element(std::begin(iter), std::end(iter)), will_return);
        }
        return will_return;
    }
    return static_cast<T>(0);
}

template<typename T>
T Matrix<T>::sum() const {
    T will_return = static_cast<T>(0);
    for (const auto &item: this->vec) {
        will_return += std::accumulate(std::begin(item), std::end(item), static_cast<T>(0));
    }
    return will_return;
}

template<typename T>
T Matrix<T>::row_max(int32_t row) const {
    if (row <= 0 || row > this->rows()) {
        throw std::invalid_argument("row out of range(it begin at 1)");
    }
    return *std::max_element(this->get_row_iter_begin(row - 1), this->get_row_iter_end(row - 1));
}

template<typename T>
T Matrix<T>::row_min(int32_t row) const {
    if (row <= 0 || row > this->rows()) {
        throw std::invalid_argument("row out of range(it begin at 1)");
    }
    return *std::min_element(this->get_row_iter_begin(row - 1),
                             this->get_row_iter_end(row - 1));
}

template<typename T>
T Matrix<T>::row_sum(int32_t row) const {
    if (row <= 0 || row > this->rows()) {
        throw std::invalid_argument("row out of range(it begin at 1)");
    }
    return std::accumulate(this->get_row_iter_begin(row - 1), this->get_row_iter_end(row - 1), static_cast<T>(0));
}

template<typename T>
T Matrix<T>::col_max(int32_t col) const {
    if (col <= 0 || col > this->cols()) {
        throw std::invalid_argument("col out of range(it begin at 1)");
    }
    T max_v = vec.front()[col - 1];
    for (int32_t i{0}; i < this->rows(); ++i) {
        max_v = std::max(max_v, vec[i][col - 1]);
    }
    return max_v;
}

template<typename T>
T Matrix<T>::col_min(int32_t col) const {
    if (col <= 0 || col > this->cols()) {
        throw std::invalid_argument("col out of range(it begin at 1)");
    }
    T min_v = vec.front()[col - 1];
    for (int32_t i{0}; i < this->rows(); ++i) {
        min_v = std::min(min_v, vec[i][col - 1]);
    }
    return min_v;
}

template<typename T>
T Matrix<T>::col_sum(int32_t col) const {
    if (col <= 0 || col > this->cols()) {
        throw std::invalid_argument("col out of range(it begin at 1)");
    }
    T sum(0);
    for (int32_t i{0}; i < this->rows(); ++i) {
        sum += vec[i][col - 1];
    }
    return sum;
}

/**get convolution of Matrix and kernel
 * @param1: this: Matrix: m_n T
 * @param2: mat2: Matrix: f1_f2 T, addvise f1=f2 and they are odd.
 * @param3: padding: int32_t the size of padding.<br> default{0}
 * @param4: stride: int32_t the stride of each step.<br> default = 1
 * @return: Matrix: x1_x2 T</br>
 * <br>x1 = ⌊(m+2p-f_1)/s⌋+1</br>
 * <br>x2 = ⌊(n+2p-f_2)/s⌋+1</br>
 * */
template<typename T>
Matrix<T> Matrix<T>::convolution(const Matrix<T> &kernel, int32_t padding, int32_t stride) const {
    const auto rows{static_cast<int32_t>(this->rows())},
            cols{static_cast<int32_t>(this->cols())},
            kernel_rows{static_cast<int32_t>(kernel.rows())},
            kernel_cols{static_cast<int32_t>(kernel.cols())};
    if (padding < 0 || stride < 0
        || rows + 2 * padding < kernel_rows
        || cols + 2 * padding < kernel_cols
        || !kernel.is_square()) {
        throw std::invalid_argument("input parameter happen error");
    }
    padding = std::max(padding, kernel_rows - 1);
    //padding = std::max(padding, std::max(kernel_rows, kernel_cols));
    int32_t new_row = floor((rows + 2 * padding - kernel_rows) / stride) + 1;
    int32_t new_col = floor((cols + 2 * padding - kernel_cols) / stride) + 1;
    vector<vector<T>> will_return(new_row, vector<T>(new_col, static_cast<T>(0)));
    vector<vector<T>> big_vec(rows + padding * 2,
                              vector<T>(cols + padding * 2, static_cast<T>(0)));
    for (int32_t i{padding}; i < rows + padding; ++i) {
        for (int32_t j{padding}; j < cols + padding; ++j) {
            big_vec[i][j] = this->vec[i - padding][j - padding];
        }
    }
    for (int32_t k{0}; k < new_row; k++) {
        for (int32_t i{0}; i < new_col; i++) {
            for (int32_t j{0}; j < kernel_rows; ++j) {
                will_return[k][i] += std::inner_product(std::begin(kernel.vec[j]), std::end(kernel.vec[j]),
                                                        std::begin(big_vec[k * stride + j]) + i * stride,
                                                        static_cast<T>(0));
            }
        }
    }
    return Matrix<T>(std::move(will_return));
}

template<typename T>
Matrix<T>
Matrix<T>::convolution_mul(const Matrix<T> &kernel, int32_t padding, int32_t stride, int32_t demension) const {
    vector<Matrix<T>> mats;
    if (this->cols() % demension != 0) {
        throw std::invalid_argument("Demension not match matrix size");
    }
    for (int32_t i{0}; i < demension; ++i) {
        vector<vector<T>> temp(this->rows(), vector<T>(this->cols() / demension));
        for (int32_t j{0}; j < this->rows(); ++j) {
            for (int32_t k{0}; k < this->cols() / demension; ++k) {
                temp[j][k] = this->get_inside(j, k * demension + i);
            }
        }
        mats.emplace_back(temp);
    }
    for (int32_t i{0}; i < demension; ++i) {
        mats[i] = mats[i].convolution(kernel, padding, stride);
    }
    vector<vector<T>> will_return(this->rows(), vector<T>(this->cols()));
    for (int32_t j{0}; j < this->rows(); ++j) {
        for (int32_t k{0}; k < this->cols(); ++k) {
            will_return[j][k] = mats[k % demension].get_inside(j, k / demension);
        }
    }
    return Matrix<T>(will_return);
}

template<typename T>
Matrix<T> Matrix<T>::reshape(int32_t row, int32_t col) const {
    int32_t col_num = this->cols();
    int32_t num = this->rows() * col_num;
    if (row * col != num || num <= 0) {
        throw std::invalid_argument("can not reshape to rectangle");
        return Matrix<T>(*this);
    }
    vector<vector<T>> res(row, vector<T>(col, static_cast<T>(0)));
    for (int32_t i{0}; i < num; i++) {
        res[i / col][i % col] = this->get_inside(i / this->cols(), i % col_num);
    }
    return Matrix<T>(std::move(res));
}

template<typename T>
Matrix<T> Matrix<T>::slice(int32_t row1, int32_t row2) const {
    if (row1 < 0 || row2 >= this->rows()) {
        return Matrix<T>(*this);
    }
    vector<vector<T>> will_return(row2 - row1 + 1, vector<T>(this->cols()));
    for (int32_t i = row1; i < row2; i++) {
        will_return[i - row1] = this->vec[i];
    }
    return Matrix<T>(std::move(will_return));
}

template<typename T>
Matrix<T> Matrix<T>::slice(int32_t row1, int32_t row2, int32_t col1, int32_t col2) const {
    if (row1 < 0 || row2 >= this->rows() || col1 < 0 || col2 >= this->cols() || row1 > row2 || col1 > col2) {
        return Matrix<T>(*this);
    }
    vector<vector<T>> will_return(row2 - row1 + 1, vector<T>(col2 - col1 + 1));
    for (int32_t i = row1; i < row2; i++) {
        for (int32_t j = col1; j < col2; j++) {
            will_return[i - row1][j - col1] = vec[i][j];
        }
    }
    return Matrix<T>(std::move(will_return));
}

#ifdef  _HAVE_OPENCV_

template<typename T>
Matrix<T> cv_to_mat(const Mat &m) {
    vector<vector<T>> will_return(m.rows, vector<T>(m.cols * m.channels()));
    for (int32_t i{0}; i < m.rows; ++i) {
        auto temp_head = m.ptr(i);
        for (int32_t j{0}; j < m.cols * m.channels(); ++j) {
            switch (m.type() % 8) {
                case static_cast<int32_t>(CV_TYPE::FLOAT32_T): {
                    will_return[i][j] = from_char_array<float>(temp_head + j * m.elemSize1());
                    break;
                }
                case static_cast<int32_t>(CV_TYPE::FLOAT64_T): {
                    will_return[i][j] = from_char_array<double>(temp_head + j * m.elemSize1());
                    break;
                }
                default: {
                    will_return[i][j] = temp_head[j * m.elemSize1()];
                    break;
                }
            }
        }
    }
    return Matrix<T>(std::move(will_return));
}

template<opencv_type T>
Mat mat_to_cv(const Matrix<T> &matrix, int32_t demen) requires opencv_type<T> {
    CV_TYPE type{CV_TYPE::NO_TYPE};
    if constexpr (is_same_v<T, uint8_t>) {
        type = CV_TYPE::UINT8_T;
    } else if constexpr (is_same_v<T, int8_t>) {
        type = CV_TYPE::INT8_T;
    } else if constexpr (is_same_v<T, uint16_t>) {
        type = CV_TYPE::UINT16_T;
    } else if constexpr (is_same_v<T, int16_t>) {
        type = CV_TYPE::INT16_T;
    } else if constexpr (is_same_v<T, int32_t>) {
        type = CV_TYPE::INT32_T;
    } else if constexpr (is_same_v<T, float>) {
        type = CV_TYPE::FLOAT32_T;
    } else if constexpr (is_same_v<T, double>) {
        type = CV_TYPE::FLOAT64_T;
    }
    const auto type_int32{static_cast<int32_t>(type)};
    if (matrix.cols() % demen != 0) {
        throw std::invalid_argument("demension not match matrix size");
    }
    Mat will_return(matrix.rows(), matrix.cols() / demen, type_int32 + (demen - 1) * 7);
    vector<Mat> mats;
    for (int32_t k{0}; k < demen; ++k) {
        mats.push_back(Mat(matrix.rows(), matrix.cols() / demen, type_int32));
    }
    for (int32_t i{0}; i < matrix.rows(); ++i) {
        for (int32_t j{0}; j < matrix.cols() / demen; ++j) {
            for (int32_t k{0}; k < demen; ++k) {
                mats.at(k).at<T>(i, j) = matrix.get_inside(i, j * demen + k);
            }
        }
    }
    cv::merge(mats, will_return);
    return will_return;
}

#endif

/**
 * Householder reduces elements after ele in col column to zero
 * this function is to reduce one column in the matrix
 */
template<typename T>
Matrix<double_t> Matrix<T>::Householder(int32_t col, int32_t ele) const {
    double_t square{0};
    for (uint32_t i = ele - 1; i < vec.size(); ++i) {
        square += pow(vec[i][col - 1], 2);
    }
    double_t mod = vec[ele - 1][col - 1] > 0 ? pow(square, 0.5) : -pow(square, 0.5);
    double_t modulus = mod * (mod + vec[ele - 1][col - 1]);
    vector<vector<double_t>> U(this->rows(), vector<double_t>(1));
    for (int32_t j{0}; j < this->rows(); ++j) {
        if (j > ele - 1) {
            U[j][0] = this->get_inside(j, col - 1);
        } else {
            U[j][0] = 0;
        }
    }
    U[ele - 1][0] = this->get_inside(ele - 1, col - 1) + mod;
    return Matrix<double_t>::eye(this->rows()) - Matrix<double_t>(U) * Matrix<double_t>
            (U).transpose() / modulus;
}

/**
 * every column is reduced by Householder
 * after reduction, this function returns a Hessenberg matrix
 */
template<typename T>
Matrix<double_t> Matrix<T>::Hessenberg() const {
    if (!this->is_square()) {
        throw std::invalid_argument("Need to ensure matrix is sequre");
        //return Matrix<double_t>::eye_value(this->rows(), 0);
    }
    Matrix<double_t> left_H = Matrix<double_t>::eye(this->rows());
    Matrix<double_t> right_H = Matrix<double_t>::eye(this->rows());
    vector<vector<double_t>> v = this->transform();
    Matrix<double_t> H = left_H * Matrix<double_t>(v) * right_H;
    for (int32_t i = 1; i < this->rows() - 1; ++i) {
        if (abs(H.get_inside(i + 1, i - 1)) > eps) {
            left_H = left_H * H.Householder(i, i + 1);
            right_H = H.Householder(i, i + 1) * right_H;
            H = left_H * Matrix<double_t>(v) * right_H;
        }
    }
    return H;
}

/**
 * Givens transformation is to set Hessenberg matrix to upper triangular matrix
 * this function carries out one rotation to one column
 */
template<typename T>
Matrix<double_t> Matrix<T>::Givens(int32_t col, int32_t begin, int32_t end) const {
    Matrix<double_t> R = Matrix<double_t>::eye(this->rows());
    double_t r = pow(pow(vec[begin - 1][col - 1], 2) + pow(vec[end - 1][col - 1], 2), 0.5);
    double_t c{1}, s{0};
    if (abs(r) > eps) {
        c = vec[begin - 1][col - 1] / r;
        s = vec[end - 1][col - 1] / r;
    }
    R.vec[begin - 1][begin - 1] = c;
    R.vec[begin - 1][end - 1] = s;
    R.vec[end - 1][begin - 1] = -s;
    R.vec[end - 1][end - 1] = c;
    return R;
}

/**
 * try Givens to Hessenberg matrix several times and reduce the matrix to upper triangular matrix
 * then we realize QR decomposition
 * return R*Q matrix, the next Hessenberg matrix to reduce
 */
template<typename T>
Matrix<double_t> Matrix<T>::QR_iteration() const {
    Matrix<double_t> R = this->Hessenberg();
    Matrix<double_t> Q = Matrix<double_t>::eye(vec.size());
    for (int32_t i{1}; i < vec.size(); ++i) {
        Matrix<double_t> temp_R = R.Givens(i, i, i + 1);
        R = temp_R * R;
        Q = Q * temp_R.transpose();
    }
    return R * Q;
}

/**
 * continue to reduce the Hessenberg matrix returned by QR_iteration
 * iterate QR decomposition several times and the diagonal elements approach to elgenvalues
 * specific algorithm can refer to
 * https://www.cnblogs.com/chenying99/articles/4967960.html
 */
template<typename T>
vector<double_t> Matrix<T>::eigenvalue() const {
    if (!this->is_square()) {
        return vector<double_t>(1);
    }
    vector<double_t> eigenvalues(this->rows());
    static constexpr int32_t iter_times = 150;
    Matrix<double_t> H = this->QR_iteration();
    for (int32_t i{0}; i < iter_times; ++i) {
        H = H.QR_iteration();
    }
    for (int32_t j{0}; j < this->rows(); ++j) {
        eigenvalues[j] = H.get_inside(j, j);
    }
    return eigenvalues;
}

/**
 * firstly sort eigenvalues to check repeat eigenvalues
 * only calculate the nullspace of repeat eigenvalues for one time
 * joint every nullspace of non-repeat eigenmatrices to get eigenvector matrix
 * algorithm for calculating eigenvectors is similar to normal calculation from eigenmatrices
 */
template<typename T>
Matrix<double_t> Matrix<T>::eigenvector() const {
    vector<double_t> eigenvalues = this->eigenvalue();
    vector<vector<double_t>> v = this->transform();
    std::sort(eigenvalues.begin(), eigenvalues.end());
    int32_t begin{0}, repeat{0};
    for (int end = 1; end < this->rows(); ++end) {
        if (round(eigenvalues[begin] * 10) / 10 == round(eigenvalues[end] * 10) / 10) {
            repeat++;
        } else {
            eigenvalues[begin + 1] = eigenvalues[end];
            begin++;
        }
    }
    Matrix<double_t> vectors(this->rows(), this->rows());
    int32_t size = vec.size() - repeat;
    for (int32_t i{0}; i < size; ++i) {
        vector<vector<double_t>> eigenmatrix = this->transform();
        double_t eigenvalue = eigenvalues[i];
        for (uint32_t j{0}; j < vec.size(); ++j) {
            eigenmatrix[j][j] = round((eigenmatrix[j][j] - eigenvalue) * 10) / 10;
        }
        if (i == 0) {
            vectors = Matrix<double_t>(eigenmatrix).Nullspace();
        } else {
            vectors = vectors.joint(Matrix<double_t>(eigenmatrix).Nullspace());
        }
    }
    return vectors;
}

/**
 * this function is to realize Gaussian elimination
 * return Row-Echelon Form and eliminate every pivot to one
 */
template<typename T>
Matrix<double_t> Matrix<T>::Gauss() const {
    vector<vector<double_t>> v = this->transform();
    Matrix<double_t> REF(v);
    //int32_t row = 0;
    for (int32_t row{0}, find{0}; row < this->rows(); ++row) {
        double_t element = 1;
        bool flag = false;
        for (uint32_t i = find; i < vec.size(); ++i) {
            if (abs(REF.get_inside(i, row)) > eps) {
                element = REF.get_inside(i, row);
                REF = REF.row_exchange(i, find);
                flag = true;
                break;
            }
        }
        if (flag) {
            REF = REF.row_elimination(find, element);
            for (uint32_t i = find + 1; i < vec.size(); ++i) {
                REF = REF.row_elimination(i, row, find);
            }
            find++;
        }
    }
    return REF;
}

/**
 * this function carries out elimination based on Gaussian elimination
 * return least line matrix
 */
template<typename T>
Matrix<double_t> Matrix<T>::Elimination() const {
    Matrix<double_t> R = this->Gauss();
    for (int32_t i{0}; static_cast<size_t>(i) < vec.size(); ++i) {
        for (int32_t j{0}; static_cast<size_t>(j) < vec[0].size(); ++j) {
            if (abs(R.get_inside(i, j)) > eps) {
                for (int32_t k = i - 1; k >= 0; --k) {
                    R = R.row_elimination(k, j, i);
                }
                break;
            }
        }
    }
    return R;
}

/**
 * after reducing the matrix to least line matrix
 * this function returns its nullspace matrix
 */
template<typename T>
inline Matrix<double_t> Matrix<T>::Nullspace() const {
    Matrix<double_t> matrix = this->Elimination();
    vector<int32_t> pivots(this->cols(), 0);
    int32_t null_num = this->cols();
    for (int32_t i{0}; i < this->rows(); ++i) {
        for (int32_t j{0}; j < this->cols(); ++j) {
            if (abs(matrix.get_inside(i, j)) > eps) {
                pivots[j] = 1;
                null_num--;
                break;
            }
        }
    }
    vector<vector<double_t>> vectors(this->rows(), vector<double_t>(null_num, 0));
    int32_t col{0};
    for (uint32_t i{0}; i < vec[0].size(); ++i) {
        if (pivots[i] == 0) {
            for (int32_t j{0}; j < null_num; ++j) {
                if (j == col) {
                    vectors[i][j] = 1;
                }
            }
            col++;
        } else {
            for (uint32_t k{0}; k < vec[0].size(); ++k) {
                if (pivots[k] == 0) {
                    for (int32_t j{0}; j < null_num; ++j) {
                        vectors[i][j] = -matrix.get_inside(i, k);
                    }
                }
            }
        }
    }
    return Matrix<double_t>(vectors);
}

/**
 * transform T matrix to double matrix
 */
template<typename T>
vector<vector<double_t>> Matrix<T>::transform() const {
    vector<vector<double_t>> v(this->rows());
    for (int32_t i{0}; i < this->rows(); ++i) {
        v[i] = vector<double_t>(this->get_row_iter_begin(i), this->get_row_iter_end(i));
    }
    return v;
}

/**
 * exchange row1 with row2
 */
template<typename T>
Matrix<T> Matrix<T>::row_exchange(int32_t row1, int32_t row2) const {
    Matrix<T> will_return(*this);
    if (row1 != row2) {
        std::swap(will_return.vec[row1], will_return.vec[row2]);
    }
    return will_return;
}

/**
 * joint every nullspace of each eigenmatrix
 * finally get an eigenvector matrix
 */
template<typename T>
Matrix<T> Matrix<T>::joint(Matrix<T> matrix) const {
    if (this->rows() != matrix.rows() && !this->is_empty()) {
        return Matrix<T>(*this);
    }
    vector<vector<T>> will_return(this->vec);
    for (size_t i{0}; i < this->rows(); ++i) {
        will_return[i].insert(will_return[i].end(), matrix.get_row_iter_begin(i), matrix.get_row_iter_end(i));
    }
    return Matrix<T>(std::move(will_return));
}

/**
 * divide ele from every element of this row except zero
 */
template<typename T>
Matrix<double_t> Matrix<T>::row_elimination(int32_t row, double_t ele) const {
    Matrix<double_t> matrix(this->transform());
    for (size_t i{0}; i < vec[0].size(); ++i) {
        if (std::abs(ele) <= eps) {
            matrix.vec[row][i] = 0;
        } else {
            matrix.vec[row][i] = static_cast<double>(this->get_inside(row, i)) / ele;
        }
    }
    return matrix;
}

/**
 * reduce the col of row to zero by reducing remove_row
 * example:
 * row elements: 1 2 3 4  col: 2 (start form index 0)
 * remove_row elements: 0 1 3 4
 * after reducing from remove_row: 1 1 0 0
 */
template<typename T>
Matrix<double_t> Matrix<T>::row_elimination(int32_t row, int32_t col, int32_t remove_row) const {
    Matrix<double_t> matrix(this->transform());
    double_t temp = vec[row][col];
    for (uint32_t i{0}; i < vec[0].size(); ++i) {
        matrix.vec[row][i] = this->get_inside(row, i) - temp * vec[remove_row][i];
    }
    return matrix;
}

}
#endif  //CS203_DSAA_TEMPLATE_ALGORITHM_CS205_PROJECT_2020S_SRC_MATRIX_HPP
