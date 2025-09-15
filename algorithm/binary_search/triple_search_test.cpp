/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-08-01 17:33:49
 * @LastEditors: nanoseeds
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include <catch_main.hpp>
#include <algorithm>
#include <numeric>
#include <tuple>
#include <vector>


using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::tie;
using std::tuple;
using std::vector;
using num_t = int32_t;

// nums应该为一个先增后减,极大值在中心的数组
// 此函数目的在于寻找其中间的最大值,[first,last]
num_t triple_search(vector<num_t> &nums, num_t first, num_t last) {
    while (first < last - 1) {
        if (num_t middle{(last - first) / 2 + first}, right_middle{(last - middle) / 2 + middle};
                nums[middle] > nums[right_middle]) {
            last = right_middle - 1;
        } else if (nums[middle] < nums[right_middle]) {
            first = middle + 1;
        } else {
            last--;
        }
    }
    return std::max(nums[first], nums[last]);
}

const static auto func_factory = [](num_t w, num_t x, num_t y) {
    return [w, x, y](num_t z) -> num_t {
        return -1 * w * (z - x) * (z - x) + y;
    };
    // 一个工厂方法,用于生产二次函数
};

TEST_CASE("test case 1", "[test binary search- triple search]") {
    static constexpr const num_t ratio = 1;    // y = -1 * ratio * Math.pow((x-middle),2) + diff
    static constexpr const num_t first = 0;    // begin of array
    static constexpr const num_t middle = 30;  // max value's index
    static constexpr const num_t last = 100;   // last of array
    static constexpr const num_t diff = 450;   // max value of array
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //std::cout << '\n';
    // prepare data finish
    //cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 2", "[test binary search- triple search]") {
    static constexpr const num_t ratio = 3, first = 0, middle = 70, last = 100, diff = 514;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //     std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //     std::cout << '\n';
    //     prepare data finish
    //      cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 3", "[test binary search- triple search]") {
    static constexpr const num_t ratio = 200, first = 0, middle = 50, last = 100, diff = -200;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //    std::cout << '\n';
    //     prepare data finish
    //    cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 4", "[test binary search- triple search]") {
    static constexpr const num_t ratio = 3, first = 10, middle = 60, last = 80, diff = 119;
    const auto func = func_factory(ratio, middle, diff);
    vector<num_t> vec(last - first);
    std::iota(std::begin(vec), std::end(vec), first);
    std::transform(std::begin(vec), std::end(vec), std::begin(vec), func);
    //std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<num_t>(std::cout, " "));
    //std::cout << '\n';
    // prepare data finish
    //cout << triple_search(vec, 0, vec.size() - 1 );
    CHECK(*std::max_element(std::begin(vec), std::end(vec)) == triple_search(vec, 0, vec.size() - 1));
}
