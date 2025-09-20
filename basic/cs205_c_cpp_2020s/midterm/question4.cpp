// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-16 14:06:45
 * @LastEditors  : nanoseeds
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

string encode(const vector <vector<int32_t>> &matrix);

vector <vector<int32_t>> decode(const string &line);

vector <int32_t> analysis_string(const string &str);

int main() {
    vector <vector<int32_t>> matrix = {
            {1, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 0, 0, 0}
    };
    string middle = encode(matrix);
    assert(middle == "4,4,3,4,6,3");
    vector <vector<int32_t>> after = decode(middle);
    for (uint32_t i = 0; i < matrix.size(); ++i) {
        for (uint32_t j = 0; j < matrix[0].size(); ++j) {
            assert(matrix[i][j] == after[i][j]);
        }
    }
    return 0;
}

string encode(const vector <vector<int32_t>> &matrix) {
    string will_return = "";
    if (matrix.empty() || matrix.front().empty()) {
        return will_return;
    }
    vector <int32_t> numbers{static_cast<int32_t>(matrix.size()), static_cast<int32_t>(matrix.front().size())};
    vector <int32_t> orders;
    orders.reserve(numbers[0] * numbers[1]);
    for (const auto &i: matrix) {
        orders.insert(orders.cend(), i.cbegin(), i.cend());
    }
    int32_t count = 1;
    if (orders.front() == 0) {
        numbers.push_back(0);
    }
    for (uint32_t i = 0; i < orders.size() - 1; i++) {
        if (orders[i] != orders[i + 1]) {
            numbers.push_back(count);
            count = 0;
        }
        count++;
    }
    numbers.push_back(count);
    for (auto num = numbers.cbegin(); num != numbers.cend() - 1; ++num) {
        will_return.append(to_string(*num)).append(",");
    }
    will_return.append(to_string(numbers.back()));
    return will_return;
}

vector <vector<int32_t>> decode(const string &line) {
    vector <int32_t> numbers = analysis_string(line);
    vector <int32_t> orders;
    vector <vector<int32_t>> will_return;
    orders.reserve(numbers.front() * numbers[1]);
    will_return.reserve(numbers.front() * numbers[1]);
    if (numbers.size() == 2) {
        return will_return;
    }
    bool sign = (numbers[2] != 0);
    for (uint32_t begin = 2 + !sign; begin < numbers.size(); begin++) {
        orders.insert(orders.cend(), numbers[begin], sign);
        sign = !sign;
    }
    for (int32_t i = 0; i < numbers.front(); ++i) {
        will_return.emplace_back(orders.cbegin() + i * numbers[1], orders.cbegin() + (i + 1) * numbers[1]);
    }
    return will_return;
}

vector <int32_t> analysis_string(const string &str) {
    vector <int32_t> will_return;
    if (str.empty()) {
        return will_return;
    }
    for (const auto &ch: str) {
        if (ch != ',' && (ch < '0' || ch > '9')) {
            return will_return;
        }
    }
    int32_t number = 0;
    for (const auto &ch: str) {
        if (ch == ',') {
            will_return.push_back(number);
            number = 0;
        } else {
            number = number * 10 + (ch - '0');
        }
    }
    will_return.push_back(number);
    return will_return;
}
