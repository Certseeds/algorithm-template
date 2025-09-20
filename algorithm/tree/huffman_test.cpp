// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag tree
//@Tag 树
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP

#include <catch_main.hpp>
#include "huffman.cpp"

namespace tree::huffman {

TEST_CASE("test_case 1 [test_tree_huffman]", "[test_tree_huffman]") {
    const huffman hn{"1145141919810"};
    const string str{"1919810"};
    CHECK(str == hn.decal(hn.cal(str)));
}

TEST_CASE("test_case 2 [test_tree_huffman]", "[test_tree_huffman]") {
    const huffman hn{"An awesome Algorithm template for Solve Online-Judge !"};
    const string str{"An awesome for Solve Online-Judge !"};
    CHECK(str == hn.decal(hn.cal(str)));
}

TEST_CASE("test_case 3 [test_tree_huffman]", "[test_tree_huffman]") {
    const huffman hn{
            string(45, 'a') + string(13, 'b') + string(12, 'c') + string(16, 'd') + string(9, 'e') + string(5, 'f')};
    const string str{"abedcaffe"};
    CHECK(str == hn.decal(hn.cal(str)));
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_TREE_HUFFMAN_TEST_HPP
