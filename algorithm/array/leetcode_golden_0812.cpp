
// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <unordered_map>
#include <stack>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <cassert>

using std::vector;
using std::string;
using std::unordered_map;

namespace leetcode_golden_0812 {
#endif

class Solution {
private:
    bool check(const vector<vector<int32_t>> &nums, int32_t i, int32_t j) {
        const auto length = static_cast<int>(nums.size());
        for (int32_t x{0}; x < length; x++) {
            if (x != j && nums[i][x] == 1) {
                return false;
            }
            if (x != i && nums[x][j] == 1) {
                return false;
            }
        }
        for (int32_t x{i + 1}, y{j + 1}; x < length && y < length; x++, y++) {
            if (nums[x][y] == 1) {
                return false;
            }
        }
        for (int32_t x{i - 1}, y{j - 1}; x >= 0 && y >= 0; x--, y--) {
            if (nums[x][y] == 1) {
                return false;
            }
        }
        for (int32_t x{i - 1}, y{j + 1}; x >= 0 && y < length; x--, y++) {
            if (nums[x][y] == 1) {
                return false;
            }
        }
        for (int32_t x{i + 1}, y{j - 1}; x < length && y >= 0; x++, y--) {
            if (nums[x][y] == 1) {
                return false;
            }
        }
        return true;
    }

    void store(const vector<vector<int32_t>> &nums, vector<vector<string>> &insert) {
        const auto length = nums.size();
        insert.emplace_back();
        for (size_t i{0}; i < length; i++) {
            string line(length, '.');
            for (size_t j{0}; j < length; j++) {
                if (nums[i][j] == 1) {
                    line[j] = 'Q';
                }
            }
            insert.back().push_back(line);
        }
    }

public:
    vector<vector<string>> solveNQueen(int32_t n) {
        if (n == 1) {
            return {{"Q"}};
        } else if (n < 4) {
            return {};
        }
        assert(n > 3);
        // 感觉这里的思路应该用递归比较好, 对于每一个n, 我们假设n-1已经解决了, 对于每一种情况来说,有左上 左下 右上 右下四个拓展情况, 每种拓展情况有2n-1个类型,
        // 通过(n-1)^2的时间复杂度visit获取其
        // 但是八皇后问题不能这样递推, 因为不是所有n皇后问题都能够简化出一个n-1皇后的区域, 倒不如说能规约出来的才比较少见.
        // 使用回溯的方式来计算,
        vector<vector<string>> will_return{};
        vector<vector<int32_t>> visit(n, vector<int32_t>(n, 0));
        int32_t i{0}, j{0};
        int32_t count{0};
        std::stack<int> sta{};
        // 需要返回的数组只不过是一个{(x1,y1),(x2,y2)....}的映射, 所以不需要存储那个, 只需要存每个皇后的坐标即可, 也方便之后进行去重.
        while (i < n && j < n) {
            if (visit[i][j] == 0) {
                visit[i][j] = 1;
            } // this can be a queen.
            // then should filter all the other positions, line, row and diagonal.
            // 或者是不存储只是尝试?
            // 对(i,j)尝试放一个, 接下来对(i+1,0 to n-1)进行挨个尝试, 每个判定一次, 如果都不行, 则回退i并j+1.
            // 大概n^3
            if (check(visit, i, j)) {
                if (i + 1 < n) {
                    i++;
                    sta.push(j);
                    j = 0;
                    continue;
                } else {
                    store(visit, will_return);
                    // should get the last i
                }
            }
            visit[i][j] = 0;
            if (j + 1 < n) {
                j++;
            } else if (j + 1 == n) {
                i--;
                j = sta.top();
                sta.pop();
                if (i == 0 && j + 1 >= n) {
                    break;
                }
                while (j + 1 == n) {
                    visit[i][j] = 0;
                    i--;
                    j = sta.top();
                    sta.pop();
                }
                visit[i][j] = 0;
                j += 1;
            }

        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
