// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP

#include <vector>
#include <cstdint>
#include <cstddef>
#include "class_helper/nonable.hpp"

namespace disjoint_set {
namespace linkedlist {
using std::vector;

template<typename T>
class base {
protected:
    struct node_base {
        const size_t v{};

        explicit node_base(size_t v) : v(v) {}
    };

public:
    static T *make_set(size_t x) { return T::make_set(x); }

    static T *unio(T *fst, T *snd) { return T::unio(fst, snd); }

    static node_base *find_set(const node_base &x) { return T::find_set(x); }
};
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_DISJOINT_SET_DISJOINT_SET_LINKEDLIST_HPP
