// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
/*
 *@题目描述
 * 输入为一个无序序列, 请分别插入排序和选择排序,并比较哪一个更好
 * 只有"交换两个数字"和"比较两个数字"是一个操作.
 * 更好的排序算法,意味着操作数更少. 输入中不会有 操作数相同 的情况.
 *@输入
 * 第一行输入一个int32_t Τ(希腊字母 tau),代表测试用例数量
 * 之后每个测试用例
 *   第一行有size_t ν(希腊字母 Nu),代表数组长度
 *   接下来是ν个int32_t
 *@输出
 * 对每个测试用例来讲
 *     第一行输出排序好的数组(注:最后一个数字后没有空格)
 *     第二行 match (winner) {
 *         "insertion" => {"Insertion Sort wins!"}
 *         "selection" => {"Selection Sort wins!"}
 *     }
 *@注: 不给样例解析的屑题目
 * */

#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <limits>
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#ifdef CS203_DSAA_TEST_MACRO
namespace lab_03_C{
#endif
// TODO
using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'}, space{' '};
static constexpr const char *const insertion_winner = "Insertion Sort wins!";
static constexpr const char *const selection_winner = "Selection Sort wins!";
using num_t = int32_t;
using input_type = vector<vector<num_t>>;
using output_type = vector<vector<num_t>>; // 最后一个元素用来存放 true/false

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    size_t tau;
    std::cin >> tau;
    vector<vector<num_t>> will_return{};
    will_return.reserve(1 << 4);
    for (size_t i{0}; i < tau; ++i) {
        size_t nu;
        std::cin >> nu;
        vector<num_t> vec(nu, -1);
        for (size_t j{0}; j < nu; ++j) {
            std::cin >> vec[j];
        }
        will_return.emplace_back(vec);
    }
    return will_return;
}

int32_t selection_sort(vector<int32_t> nums) {
    int32_t will_return{0};
    const auto nums_size = static_cast<int32_t>(nums.size());
    for (int i = 0; i < nums_size - 1; ++i) {
        //will_return++;
        int k = i;
        for (int j = i + 1; j < nums_size; ++j) {
            //will_return++;
            will_return++;
            if (nums[k] > nums[j]) {
                k = j;
            }
        }
        will_return++;
        will_return++;
        std::swap(nums[i], nums[k]);
    }
    will_return++;
    return will_return;
}

int32_t insert_sort(vector<num_t> nums) {
    int32_t will_return{0};
    const auto nums_size = static_cast<int32_t>(nums.size());
    for (int i = 0; i < nums_size; i++) {
        //will_return++;
        for (int j = i; j >= 1; j--) {
            //will_return++;
            will_return++;
            if (nums[j - 1] > nums[j]) {
                will_return++;
                std::swap(nums[j - 1], nums[j]);
            }
        }
        will_return++;
    }
    will_return++;
    return will_return;
}

output_type cal(const input_type &data) {
    vector<vector<num_t>> will_return;
    const auto data_size = data.size();
    for (size_t i{0}; i < data_size; i++) {
        auto element = data[i];
        const auto insert = insert_sort(element);
        const auto selection = selection_sort(element);
        std::sort(element.begin(), element.end());
        element.emplace_back(insert > selection);
        will_return.emplace_back(element);
    }
    return will_return;
}

void output(const output_type &data) {
    for (auto &&ele: data) {
        const auto ele_size = ele.size();
        for (size_t i{0}; i < ele_size - 2; ++i) {
            std::cout << ele[i] << space;
        }
        std::cout << ele[ele_size - 2] << end;
        switch (ele[ele_size - 1]) {
            case 0: {
                std::cout << insertion_winner << end;
                break;
            }
            default: {
                std::cout << selection_winner << end;
                break;
            }
        }
    }

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
#ifdef CS203_DSAA_TEST_MACRO
}
#endif
