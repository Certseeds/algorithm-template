// SPDX-License-Identifier: AGPL-3.0-or-later
/*  algorithm_template
    Copyright (C) 2020-2023 nanoseeds
*/

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_MATRIX_EXPRESSION_TEMPLATE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_MATRIX_EXPRESSION_TEMPLATE_HPP

#include "template_helper.hpp"

namespace OPERATOR {


struct Add {
    template<typename T1>
    static T1 Op(T1 a, T1 b) {
        return a + b;
    }
};

struct Minus {
    template<typename T1>
    static T1 Op(T1 a, T1 b) {
        return a - b;
    }
};

// define Minimum
struct Minimum {
    template<typename T1>
    static T1 Op(T1 a, T1 b) {
        return a < b ? a : b;
    }
};

struct Maximum {
    template<typename T1>
    static T1 Op(T1 a, T1 b) {
        return a > b ? a : b;
    }
};
}

namespace EXPRESSION {
using OPERATOR::Add, OPERATOR::Minus, OPERATOR::Minimum, OPERATOR::Maximum;
// this is expression, all expressions must inherit it

template<typename T>
struct Expression {

    // returns const reference of the actual type of this expression
    const T &cast() const { return static_cast<const T &>(*this); }

    size_t rows() const { return cast().rows(); }// get Expression size
    size_t cols() const { return cast().cols(); }// get Expression size
// template binary operation, works for any expressions
private:
    Expression &operator=(const Expression &) = default;

    Expression() = default;

    Expression(Expression &&node) = default;

    Expression &operator=(Expression &&node) = default;

    friend T;
};


// binary expression: (binary op,lhs, rhs)
// Func can easily allows user customized theirs binary operators
template<typename Func, typename TLhs, typename TRhs>
struct BinaryOp : public Expression<BinaryOp<Func, TLhs, TRhs> > {
    BinaryOp(const TLhs &lhs, const TRhs &rhs) : lhs_(lhs.cast()), rhs_(rhs.cast()) {}

    // work function, computing this expression at position i, import for lazy computing

    auto value(size_t i, size_t j) const {
        return Func::Op(lhs_.value(i, j), rhs_.value(i, j));
    }

    size_t rows() const { return std::min(static_cast<size_t>(lhs_.rows()), static_cast<size_t>(rhs_.rows())); }

    size_t cols() const { return std::min(static_cast<size_t>(lhs_.cols()), static_cast<size_t>(rhs_.cols())); }

private:
    const TLhs &lhs_;
    const TRhs &rhs_;
};

template<typename Func, typename TLhs, typename TRhs>
requires(is_OPERATOR<Func>)
static inline BinaryOp<Func, TLhs, TRhs> expToBinaryOp(const Expression<TLhs> &lhs, const Expression<TRhs> &rhs) {
    static_assert(is_OPERATOR<Func>);
    return BinaryOp<Func, TLhs, TRhs>(lhs.cast(), rhs.cast());
}

template<typename Func, typename TLhs, typename TRhs>
requires(is_OPERATOR<Func>)
static inline BinaryOp<Func, TLhs, TRhs> expToBinaryOp(const Expression<TLhs> &lhs, Expression<TRhs> &&rhs) {
    static_assert(is_OPERATOR<Func>);
    return BinaryOp<Func, TLhs, TRhs>(lhs.cast(), rhs.cast());
}

namespace UnOperatorBinary {
template<typename TLhs, typename TRhs>
inline BinaryOp<Minimum, TLhs, TRhs>
min(const Expression<TLhs> &lhs, const Expression<TRhs> &rhs) {
    return expToBinaryOp<Minimum>(lhs, rhs);
}

template<typename TLhs, typename TRhs>
inline BinaryOp<Maximum, TLhs, TRhs>
max(const Expression<TLhs> &lhs, const Expression<TRhs> &rhs) {
    return expToBinaryOp<Maximum>(lhs, rhs);
}
}
// allocation just by user
// no constructor and destructor to allocate and de-allocate memory

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_MATRIX_EXPRESSION_TEMPLATE_HPP
