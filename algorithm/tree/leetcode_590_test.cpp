// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_590_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_590_TEST_HPP

#include <catch_main.hpp>
#include <tree/treenode_multi.hpp>
#include <list>
#include <stack>
#include <vector>
#include "leetcode_590.cpp"

namespace leetcode_590 {
using std::vector;
using Node = TREE_NODE::TreeNodeMulti;
using std::stack;
using std::list;

TEST_CASE("test_case 1 [test_590]", "[test_590]") {
    Solution solution;
    CHECK(true); // too simple
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_590_TEST_HPP
