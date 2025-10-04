// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds


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

#ifdef ALGORITHM_TEST_MACRO
namespace lab_03_C{
#endif

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
    int32_t ops = 0;
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i + 1 < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            // compare nums[k] and nums[j]
            ++ops;
            if (nums[j] < nums[k]) k = j;
        }
        if (k != i) {
            // one swap operation
            ++ops;
            std::swap(nums[i], nums[k]);
        }
    }
    return ops;
}

int32_t insert_sort(vector<num_t> nums) {
    int32_t ops = 0;
    const int n = static_cast<int>(nums.size());
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0) {
            // compare nums[j-1] and nums[j]
            ++ops;
            if (nums[j - 1] > nums[j]) {
                // swap
                ++ops;
                std::swap(nums[j - 1], nums[j]);
                --j;
            } else {
                break;
            }
        }
    }
    return ops;
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
#ifdef ALGORITHM_TEST_MACRO
}
#endif
