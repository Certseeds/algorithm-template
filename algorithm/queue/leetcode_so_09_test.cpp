// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
//@Tag Queue
//@Tag 队列
//@Tag 模拟
//@Plan 剑指OfferII-I Day01
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include <functional>
#include <memory>
#include "leetcode_so_09.cpp"

namespace leetcode_so_09 {
using std::string;

TEST_CASE("test case pure-1 [test_sw_09]", "[test_sw_09]") {
    std::function<CQueue *()> lambda;
    Solution solution;
    SECTION("pure") {
        lambda = [&solution]() { return solution.pure(); };
    }SECTION("effective") {
        lambda = [&solution]() { return solution.effective(); };
    }
    const auto ptr = std::unique_ptr<CQueue>(lambda());
    ptr->appendTail(3);
    CHECK(3 == ptr->deleteHead());
    CHECK(-1 == ptr->deleteHead());
}

TEST_CASE("test case pure-2 [test_sw_09]", "[test_sw_09]") {
    std::function<CQueue *()> lambda;
    Solution solution;
    SECTION("pure") {
        lambda = [&solution]() { return solution.pure(); };
    }SECTION("effective") {
        lambda = [&solution]() { return solution.effective(); };
    }
    const auto ptr = std::unique_ptr<CQueue>(lambda());
    CHECK(-1 == ptr->deleteHead());
    ptr->appendTail(5);
    ptr->appendTail(2);
    CHECK(5 == ptr->deleteHead());
    CHECK(2 == ptr->deleteHead());
}
}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_09_TEST_HPP
