/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:52:02
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "city.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int sub_main_assignment_2();

city *get_city(char *line);

int input_city(string th, char *temp, city **cities);

vector<int> matches(char *str, city **cities);

bool judgement_equal_bye(string str);

double count_distance(vector<double> &dous);

string trim(string str);

static constexpr const int32_t LENGTH_OF_ARRAY = 1000;
static constexpr const int32_t location_length = 5;
static constexpr const int32_t longitude_max = 90;
static constexpr const int32_t latitude_max = 180;
static constexpr const int32_t max_length = 1024;
static constexpr const int32_t min_length = 3;
static constexpr const int32_t radius_earth = 6371;
static constexpr const double_t PI = 3.1415926535f;

const string FILE_NAME = "./../../../Assignment_2/test/world_cities.csv";
