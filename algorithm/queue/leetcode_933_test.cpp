// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag Queue
//@Tag 队列
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_933_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_933_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include <functional>
#include <memory>
#include "leetcode_933.cpp"

namespace leetcode_933 {
using std::string;

TEST_CASE("test case pure-1 [test_933]", "[test_933]") {
    Solution solution;
    const std::unique_ptr<RecentCounter> pointer = std::unique_ptr<RecentCounter>(solution.pure());
    CHECK(1 == pointer->ping(1));
    CHECK(2 == pointer->ping(100));
    CHECK(3 == pointer->ping(3000));
    CHECK(3 == pointer->ping(3002));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_QUEUE_LEETCODE_933_TEST_HPP
