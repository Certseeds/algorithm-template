// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag list
//@Tag 链表

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP

#include <catch_main.hpp>
#include <cstddef>
#include "leetcode_2.cpp"

namespace leetcode_2 {
using LISTNODE::ListNode;
using LISTNODE::ListNodeLink;

TEST_CASE("basic tests [test_2]", "[test_2]") {
    const ListNodeLink vec1{2, 4, 3}, vec2{5, 6, 4};
    auto clas = Solution();
    const ListNode *const result = clas.addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({7, 0, 8}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};
}

TEST_CASE("basic tests 2 [test_2]", "[test_2]") {
    const ListNodeLink vec1{0}, vec2{0};
    auto clas = Solution();
    const ListNode *const result = clas.addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({0}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};
}

TEST_CASE("basic tests 3 [test_2]", "[test_2]") {
    const ListNodeLink vec1{9, 9, 9, 9, 9, 9, 9}, vec2{9, 9, 9, 9};
    auto clas = Solution();
    const ListNode *const result = clas.addTwoNumbers(vec1[0], vec2[0]);
    CHECK(ListNode::equal({8, 9, 9, 9, 0, 0, 0, 1}, result));
    const ListNodeLink removed{const_cast<ListNode *>(result)};

}


}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_LIST_LEETCODE_2_TEST_HPP
