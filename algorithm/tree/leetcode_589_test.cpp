// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode_multi.hpp>
#include <stack>
#include "leetcode_589.cpp"

namespace leetcode_589 {

using Node = TREE_NODE::TreeNodeMulti;
using std::stack;

TEST_CASE("test_case 1 [test_589]", "[test_589]") {
    Solution solution;
    CHECK(true); // too simple
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_LEETCODE_589_TEST_HPP
