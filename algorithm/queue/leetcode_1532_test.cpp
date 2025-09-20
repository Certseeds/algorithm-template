// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2023 nanoseeds

*/
//@Tag Queue
//@Tag 队列
//@Tag 模拟
#ifndef ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_1532_TEST_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_1532_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include <functional>
#include <memory>
#include "leetcode_1532.cpp"

namespace leetcode_1532 {
using std::string;

TEST_CASE("test case pure-1 [test_1532]", "[test_1532]") {
    Solution solution;
    const std::unique_ptr<ProductOfNumbers> pointer = std::unique_ptr<ProductOfNumbers>(solution.pure());
    pointer->add(3);
    pointer->add(0);
    pointer->add(2);
    pointer->add(5);
    pointer->add(4);
    CHECK(20 == pointer->getProduct(2));
    CHECK(40 == pointer->getProduct(3));
    CHECK(0 == pointer->getProduct(4));
    pointer->add(8);
    CHECK(32 == pointer->getProduct(2));
}

}
#endif //ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_1532_TEST_HPP
