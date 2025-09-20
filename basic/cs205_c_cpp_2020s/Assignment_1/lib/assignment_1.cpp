/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-03-05 21:56:08
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:04:31
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include "assignment_1.hpp"

int sub_main() {
    vector<double> dous(4, 0.0f);
    vector<string> strs(4, "");
    int return_value1 = get_city_itude(dous, strs, "first", 0);
    if (0 != return_value1) {
        return return_value1;
    }
    int return_value2 = get_city_itude(dous, strs, "second", 2);
    if (0 != return_value2) {
        return return_value2;
    }
    cout << "The distance between ";
    cout << strs[0] << " and ";
    cout << strs[2] << " is ";
    cout << count_distance(dous) << " km";
    return 0;
}

double count_distance(vector<double> &dous) {
    dous[0] = 90 - dous[0];
    dous[2] = 90 - dous[2];
    // data is la,lo ,la,lo
    const double distance_1 =
            std::sin(std::abs(dous[0]) * PI / 180) *
            std::sin(std::abs(dous[2]) * PI / 180) *
            std::cos(std::abs(dous[1] - dous[3]) * PI / 180);
    const double distance_2 =
            std::cos(std::abs(dous[0]) * PI / 180) *
            std::cos(std::abs(dous[2]) * PI / 180);
    const double distance = radius_earth * std::acos(distance_1 + distance_2);
    return distance;
}

int get_city_itude(
        vector<double> &dous, vector<string> &strs, const string &num, int order) {
    char first[1024] = {0};
    char itude[1024] = {0};
    cout << "The " << num << " city : ";
    cin.getline(first, max_length);
    strs[order] = first;
    if (!judge_legal(strs[order])) {
        cout << "City name should not contain special characters" << endl;
        return -1;
    }
    cout << "The latitude and longitude of " << num << " city: ";
    cin.getline(itude, max_length);
    strs[order + 1] = delete_space(itude);
    if (std::count(strs[order + 1].begin(), strs[order + 1].end(), ' ') == 0) {
        cout << "bad input,longitude or latitude's middle ";
        cout << "should be space and both of them is needed" << endl;
        return -2;
    }
    if (!judge_legal2(strs[order + 1])) {
        cout << "bad input,longitude or latitude should not contain special characters" << endl;
        return -3;
    }
    int double_return_value = give_two_double(strs[order + 1], dous, order);
    if (-1 == double_return_value) {
        cout << "longitude or latitude contain too much + . -  or" << endl;
        return -4;
    }
    if (-2 == double_return_value) {
        cout << "input should obey correct input format" << endl;
        return -5;
    }
    if (0.0f == dous[order] || 0.0f == dous[order + 1]) {
        cout << "longitude or latitude should not be zero" << endl;
        return -6;
    }
    if (std::abs(dous[order]) > 90 || std::abs(dous[order + 1]) > 180) {
        cout << "latitude should belong to [-90,+90]" << endl;
        cout << "longitude should belong to [-180,+180]" << endl;
        return -7;
    }
    return 0;
}

bool judge_legal(const string &s) {
    for (auto i: s) {
        if (!(static_cast<int>(' ') == i || static_cast<int>(',') == i ||
              (i >= static_cast<int>('A') && i <= static_cast<int>('Z')) ||
              (i >= static_cast<int>('a') && i <= static_cast<int>('z')))) {
            return false;
        }
    }
    return true;
}

bool judge_legal2(const string &s) {
    for (auto i: s) {
        if (!(static_cast<int>('+') == i || static_cast<int>('-') == i ||
              static_cast<int>(' ') == i || static_cast<int>('.') == i ||
              (i >= static_cast<int>('0') && i <= static_cast<int>('9')))) {
            return false;
        }
    }
    return true;
}

string delete_space(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

bool check_double(const string &s) {
    if (std::count(s.begin(), s.end(), '.') > 1 ||
        (std::count(s.begin(), s.end(), '+') +
         std::count(s.begin(), s.end(), '-') > 1)) {
        return false;
    }
    return true;
}

int give_two_double(const string &s, vector<double> &num, int order) {
    int middle = s.find_first_of(' ');
    string s1 = delete_space(s.substr(0, middle));
    string s2 = delete_space(s.substr(middle, s.size()));
    if (!check_double(s1) || !check_double(s2)) {
        return -1;
    }
    try {
        num[order] = std::stof(s1);
        num[order + 1] = std::stof(s2);
    } catch (const std::invalid_argument &e) {
        return -2;
    }
    return 0;
}
