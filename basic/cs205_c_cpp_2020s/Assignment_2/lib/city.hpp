/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-02-08 22:48:30
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:49:10
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#ifndef _ASSIGNMENT_2_CITY_
#define _ASSIGNMENT_2_CITY_

#include <cstring>
#include <algorithm>

static constexpr const int32_t LENGTH_OF_NAME = 35;

struct city {
    char *city_name{nullptr};
    char *country_name{nullptr};
    double *latitude{nullptr};
    double *longitude{nullptr};

    city();

    city(char *ci_name, char *coun_name, double la, double lo);

    ~city();
};

#endif
