/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-02-08 22:48:30
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:49:10
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include "city.hpp"

city::city() {
    city_name = new char[LENGTH_OF_NAME + 1];
    country_name = new char[LENGTH_OF_NAME + 1];
    latitude = new double;
    longitude = new double;
    memset(city_name, '\0', LENGTH_OF_NAME * sizeof(char));
    memset(country_name, '\0', LENGTH_OF_NAME * sizeof(char));
}

city::city(char *ci_name, char *coun_name, double la, double lo) {
    city_name = new char[LENGTH_OF_NAME + 1];
    country_name = new char[LENGTH_OF_NAME + 1];
    latitude = new double;
    longitude = new double;
    memset(city_name, '\0', LENGTH_OF_NAME + 1);
    memset(country_name, '\0', LENGTH_OF_NAME + 1);
    memcpy(city_name, ci_name, std::min(LENGTH_OF_NAME, static_cast<int>(strlen(ci_name))) * sizeof(char));
    memcpy(country_name, coun_name, std::min(LENGTH_OF_NAME, static_cast<int>(strlen(coun_name))) * sizeof(char));
    (*latitude) = la;
    (*longitude) = lo;
}

city::~city() {
    delete[] city_name;
    delete[] country_name;
    delete latitude;
    delete longitude;
}
