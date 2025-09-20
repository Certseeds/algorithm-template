// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP

#include <string>
#include <memory>

#include "class_helper/nonable.hpp"

namespace disjoint_set {
using std::vector;

class disjoint_set : private nonCopyMoveAble {
public:
    virtual ~disjoint_set() = default;

    virtual size_t find(size_t x) = 0;

    virtual void merge(size_t x, size_t y) = 0;

    virtual void mergeHeur(size_t x, size_t y) = 0;
};

std::unique_ptr<disjoint_set> getDisjointSet(size_t x);

}


#endif //ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_HPP
