/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-05 21:56:08
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:04:31
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int sub_main();

int get_city_itude(vector<double> &dous, vector<string> &strs, const string &num, int order);

bool judge_legal(const string &s);

bool judge_legal2(const string &s);

string delete_space(string str);

int give_two_double(const string &s, vector<double> &num, int order);

bool check_double(const string &s);

double count_distance(vector<double> &dous);

static constexpr const int32_t max_length = 1024;
static constexpr const int32_t radius_earth = 6371;
static constexpr const double PI = 3.1415926535;
