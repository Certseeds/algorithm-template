// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-19 22:37:16
 * @LastEditors  : nanoseeds
 */
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
// lab number
static constexpr const int32_t lab_number = 14;

int32_t question4();

std::pair<int32_t, vector<int32_t>> str_to_scores(const std::string &str_in);
