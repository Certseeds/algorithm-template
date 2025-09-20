// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP

#include <tuple>
#include <vector>
#include <cstdint>

namespace binary_search {
using std::tie;
using std::tuple;
using std::vector;
using std::vector;
using num_t = int32_t;
using cVecRef = const vector<num_t> &;

// !IMPORTANT [first,last)!!
// nums升序,寻找[first,last)内,第一个不小于value的值（x>=value的第一个)
num_t lower_bound(cVecRef nums, num_t first, num_t last, num_t value);

// nums升序,寻找[first,last)内,任意等于value的值.
// 任意!
num_t any_equal(cVecRef nums, num_t first, num_t last, num_t value);

// nums升序,寻找[first,last)内,第一个大于value的值（x>value的第一个)
num_t upper_bound(cVecRef nums, num_t first, num_t last, num_t value);

// 升序,[first,last)内,最后一个小于value的值（x<value的最大值）
num_t lower_bound_warpper(cVecRef nums, num_t first, num_t last, num_t value);

//升序,[first,last)内,最后一个小于等于value的值,(x<=value 最大值)
num_t upper_bound_warpper(cVecRef nums, num_t first, num_t last, num_t value);

num_t binary_search_pos(cVecRef vec, int32_t target, int32_t begin, int32_t end);
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_BINARY_SEARCH_BASIC_HPP
