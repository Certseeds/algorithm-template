// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
#define ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
static constexpr const double eps{0.00000001}, neps{-eps};

constexpr inline int32_t sign(int32_t x) {
    return ((x > 0) - (x < 0));
}

constexpr inline int32_t sign(double x) {
    return ((x < neps) ? -1 : (x > neps));
}

#endif //ALGORITHM_TEMPLATE_INCLUDE_INCLUDE_CS203_HELPER_HPP
