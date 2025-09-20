// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
/*
 * @题目描述
 * 数组α具有ν个元素,请输出数组a `中位数的double形式`
 * `中位数的double形式` 定义为,
 * match (ν % 2) {
 *  0 => { return (α[ν/2-1]+α[ν/2]); }
 *  1 => { return 2*α[ν/2]; }
 * };
 * @输入
 * 第一行输入 int32_t n, 大于1,小于5*10^6
 * 第二行有n个int32_t, [0,2^31-1]
 * @输出
 * 一个 `中位数的double形式`
 * @解析,此处坑点在于 int32_t *2会爆掉,所以都需要使用int64_t
 * */
//@Tag Done
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC target("mmx")

#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <cstring>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_03_B{
#endif

using std::cin;
using std::cout;
using std::tuple;
using std::string;
using std::vector;
static constexpr const char end{'\n'};

using num_t = int64_t;
using input_type = vector<num_t>;
using output_type = num_t;

inline input_type read();

output_type cal(input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

// function from algorithm/sort/merge_sort.cpp
static void mergesort_rec(vector<num_t> &nums, vector<num_t> &zeros, int begin, int endnum) {
    if (begin >= endnum) {
        return;
    } else if (begin + 1 == endnum) {
        if (nums[begin] > nums[endnum]) {
            std::swap(nums[begin], nums[endnum]);
        }
    }
    int middle = begin + (endnum - begin) / 2;;
    mergesort_rec(nums, zeros, begin, middle);
    mergesort_rec(nums, zeros, middle + 1, endnum);
    int pos = begin;
    int start1 = begin;
    int start2 = middle + 1;
    for (; start1 <= middle && start2 <= endnum; pos++) {
        if (nums[start1] < nums[start2]) {
            zeros[pos] = nums[start1];
            start1++;
        } else {
            zeros[pos] = nums[start2];
            start2++;
        }
    }
    for (; start1 <= middle; pos++, start1++) {
        zeros[pos] = nums[start1];;
    }
    for (; start2 <= endnum; pos++, start2++) {
        zeros[pos] = nums[start2];
    }
    memcpy(reinterpret_cast<void *>(&nums[begin]), reinterpret_cast<void *>(&zeros[begin]),
           sizeof(num_t) * (endnum - begin + 1));
}

inline input_type read() {
    num_t niu{0};
    std::cin >> niu;
    vector<num_t> vec(niu, 0);
    for (num_t i{0}; i < niu; i++) {
        std::cin >> vec[i];
    }
    return vec;
}

output_type cal(input_type &data) {
    const auto data_size = data.size();
    vector<num_t> zeros(data_size, 0);
    mergesort_rec(data, zeros, 0, data_size - 1);
    const auto half_size = data_size / 2;
    switch (data_size % 2) {
        case 0: {
            //(α[ν/2-1]+α[ν/2])/2;
            return data[half_size - 1] + data[half_size];
        }
        case 1: {
            return data[half_size] + data[half_size];
        }
    }
    return 0.0f;
}

void output(const output_type &data) {
    cout << data << end;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
