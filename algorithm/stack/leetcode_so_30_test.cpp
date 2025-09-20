// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Plan 剑指OfferII-I Day01
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP

#include "leetcode_so_30.cpp"
#include <catch_main.hpp>
#include <memory>

namespace leetcode_so_30 {

TEST_CASE("test case pure-1 [test_sw_30]", "[test_sw_30]") {
    std::function<MinStack *()> lambda;
    Solution solution;
    SECTION("pure") {
        lambda = [&solution]() { return solution.pure(); };
    }SECTION("effective") {
        lambda = [&solution]() { return solution.effective(); };
    }
    const auto ptr = std::unique_ptr<MinStack>(lambda());
    ptr->push(0);
    ptr->push(1);
    ptr->push(0);
    CHECK(0 == ptr->min());
    ptr->pop();
    CHECK(0 == ptr->min());
}

TEST_CASE("test case pure-2 [test_sw_30]", "[test_sw_30]") {
    std::function<MinStack *()> lambda;
    Solution solution;
    SECTION("pure") {
        lambda = [&solution]() { return solution.pure(); };
    }SECTION("effective") {
        lambda = [&solution]() { return solution.effective(); };
    }
    const auto ptr = std::unique_ptr<MinStack>(lambda());
    ptr->push(-2);
    ptr->push(0);
    ptr->push(-1);
    CHECK(-2 == ptr->min());
    CHECK(-1 == ptr->top());
    ptr->pop();
    CHECK(-2 == ptr->min());
    CHECK(0 == ptr->top());
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_SO_30_TEST_HPP
