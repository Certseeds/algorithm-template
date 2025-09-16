// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Plan 数据结构入门 Day7

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP


#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include "leetcode_203.cpp"

namespace leetcode_203 {
using LISTNODE::ListNode;
using std::vector;

TEST_CASE("test case 1 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{1, 2, 6, 3, 4, 5, 6};
    static constexpr const auto remove{6};
    const vector<int32_t> output{1, 2, 3, 4, 5};
    auto clas = Solution();
    const ListNode *const result = clas.removeElements(vec1[0], remove);
    CHECK(ListNode::equal(output, result));
}

TEST_CASE("test case 2 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{6, 6, 6, 5, 6, 9, 3, 4, 5, 6};
    static constexpr const auto remove{6};
    const vector<int32_t> output{5, 9, 3, 4, 5};
    auto clas = Solution();
    const ListNode *const result = clas.removeElements(vec1[0], remove);
    CHECK(ListNode::equal(output, result));
}

TEST_CASE("test case 3 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{6, 6, 6, 6, 6};
    static constexpr const auto remove{6};
    auto clas = Solution();
    const ListNode *const result = clas.removeElements(vec1[0], remove);
    CHECK(nullptr == result);
}

TEST_CASE("test case 4 [test_203]", "[test_203]") {
    const LISTNODE::ListNodeLink vec1{};
    static constexpr const auto remove{114514};
    auto clas = Solution();
    const ListNode *const result = clas.removeElements(vec1[0], remove);
    CHECK(nullptr == result);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_203_TEST_HPP
