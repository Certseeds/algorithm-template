// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2024-2025 nanoseeds

#ifndef ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP
#define ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP

#include <catch_main.hpp>
#include "leetcode_ringbuffer_queue.cpp"

#include <optional>
#include <cstdint>

namespace rbqueue {

TEST_CASE("test case pure-1 [test_rbqueue_09]", "[test_rbqueue_09]") {
    ringbuffer_queue rbq(3);
    CHECK(rbq.isEmpty());
    rbq.push(1);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 1);
    CHECK(rbq.front() == 1);
    rbq.push(2);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 1);
    rbq.push(3);
    CHECK_FALSE(rbq.isEmpty());
    CHECK(rbq.isFull());
    CHECK(rbq.front() == 1);
    rbq.pop();
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 2);
    rbq.pop();
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();

    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    rbq.push(4);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 4);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 2);
    rbq.push(6);
    CHECK_FALSE(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
    rbq.pop();
    CHECK(rbq.isEmpty());
    CHECK_FALSE(rbq.isFull());
    CHECK(rbq.front() == 3);
}
}

#endif //ALGORITHM_TEMPLATE_ALGORITHM_QUEUE_RINGBUFFER_QUEUE_HPP
