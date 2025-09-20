// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO
#include <vector>
#include <string>
#include <utility>

namespace leetcode_so_12 {
using std::vector;
using std::string;
#endif

class Solution {
private:
    bool dfs(vector<vector<char>> &board, const string &word, const string &wor, const std::pair<size_t, size_t> loca) {
        if (word == wor) {
            return true;
        }
        const auto&[row, line] = loca;
        const auto ch = board[row][line];
        const auto this_ch = word[wor.size()];
        board[row][line] = ' ';
        bool temp{false};
        temp = temp || (row > 0 && this_ch == board[row - 1][line] &&
                        dfs(board, word, wor + board[row - 1][line], {row - 1, line}))
               || (row + 1 < board.size() && this_ch == board[row + 1][line] &&
                   dfs(board, word, wor + board[row + 1][line], {row + 1, line}))
               || (line > 0 && this_ch == board[row][line - 1] &&
                   dfs(board, word, wor + board[row][line - 1], {row, line - 1}))
               || (line + 1 < board.front().size() && this_ch == board[row][line + 1] &&
                   dfs(board, word, wor + board[row][line + 1], {row, line + 1}));
        board[row][line] = ch;
        return temp;
    }

public:
    bool exist(const vector<vector<char>> &board, const string &word) {
        if (board.empty() || board.front().empty()) {
            return word.empty();
        } else if (word.empty()) {
            return true;
        }
        vector<vector<char>> boardMutable{board};
        const auto row{board.size()}, col{board.front().size()};
        for (size_t i{0}; i < row; ++i) {
            for (size_t j{0}; j < col; ++j) {
                if (board[i][j] == word.front() && dfs(boardMutable, word, string(1, board[i][j]), {i, j})) {
                    return true;
                }
            }
        }
        return false;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
