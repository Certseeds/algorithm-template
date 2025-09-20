// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag list
//@Tag 链表
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP

#include <catch_main.hpp>
#include "leetcode_146.cpp"

namespace leetcode_146 {

TEST_CASE("fst [test_146]", "[test_146]") {
    Solution solution;
    const auto ptr = solution.get(2);
    ptr->put(1, 1);
    ptr->put(2, 2);
    CHECK(1 == ptr->get(1));
    ptr->put(3, 3);
    CHECK(-1 == ptr->get(2));
    ptr->put(4, 4);
    CHECK(-1 == ptr->get(1));
    CHECK(3 == ptr->get(3));
    CHECK(4 == ptr->get(4));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_146_TEST_HPP
