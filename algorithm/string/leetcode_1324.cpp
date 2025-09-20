// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdint>
#include <cstddef>
namespace leetcode_1324 {
using std::vector;
using std::string;
#endif

class Solution {
public:
    vector<string> printVertically(const string &S) {
        vector<std::tuple<const char *, size_t>> views{};
        // step1, get the start of each elements
        // 使用raw pointer 避免内存分配
        int32_t max_length{0};
        for (auto iter{S.cbegin()}, last{S.cend()}; iter != last;) {
            const char *const pointer = iter.base();
            int32_t length{0};
            for (; iter != last && *iter != ' '; ++iter) {
                ++length;
            }
            max_length = std::max(max_length, length);
            views.emplace_back(pointer, length);
            if (iter != last) {
                ++iter;
            }
        }
        // step2, step for each pointer to get char
        const auto views_length{views.size()};
        vector<string> will_return{};
        will_return.reserve(max_length); // 预分配内存
        for (int32_t iter{0}; iter < max_length; ++iter) {
            auto back_iter = views_length;
            for (; back_iter != 0; --back_iter) {
                const auto [str, length] = views[back_iter - 1];
                if (length != 0) {
                    break;
                }
            }// 采用反向迭代,高效去除后缀空字符
            std::string str(back_iter, ' '); // 预分配内存
            for (; back_iter != 0; --back_iter) { // 反向迭代, 使用length辅助判断
                const auto [element, length] = views[back_iter - 1];
                if (length > 0) {
                    str[back_iter - 1] = *element;
                    views[back_iter - 1] = std::make_tuple(element + 1, length - 1);
                } else {
                    str[back_iter - 1] = ' ';
                }
            }
            will_return.push_back(str);
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
