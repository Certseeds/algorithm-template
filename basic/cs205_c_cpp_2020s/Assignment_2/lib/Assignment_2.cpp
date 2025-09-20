/*
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2021-01-05 18:49:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-02-08 22:52:02
 */
// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
#include "Assignment_2.hpp"

int sub_main_assignment_2() {
    std::ifstream read_file(FILE_NAME);
    char temp[max_length];
    city *cities[LENGTH_OF_ARRAY];
    city *choose_city[2]{nullptr, nullptr};
    for (auto &citie: cities) {
        citie = new city();
    }
    if (!read_file.is_open()) {
        cout << "Warning! fail to find file!" << endl;
        return -1;
    }
    int32_t count = 0;
    memset(temp, '0', max_length * sizeof(char));
    while (read_file.getline(temp, max_length) && temp[0] != '\0') {
        if (LENGTH_OF_ARRAY == count) {
            cout << "Warning! Array Too Small! Some Data do not loaded" << endl;
            break;
        }
        delete cities[count];
        cities[count] = get_city(temp);
        memset(temp, '\0', max_length * sizeof(char));
        count++;
    }
    int32_t order = -1;
    read_file.close();
    while (true) {
        order = -1;
        while (order < 0) {
            order = input_city("first", temp, cities);
            memset(temp, '\0', max_length * sizeof(char));
        }
        choose_city[0] = cities[order];
        order = -1;
        while (order < 0) {
            order = input_city("second", temp, cities);
            memset(temp, '\0', max_length * sizeof(char));
        }
        choose_city[1] = cities[order];
        cout << choose_city[0]->city_name << " " << choose_city[1]->city_name << endl;
        cout << "Input Bye to output" << endl;
        cin.getline(temp, max_length);
        if (judgement_equal_bye(trim(temp))) {
            break;
        }
        memset(temp, '\0', max_length * sizeof(char));
    }
    vector<double> lang_long = {(*choose_city[0]->latitude), (*choose_city[0]->longitude), (*choose_city[1]->latitude),
                                (*choose_city[1]->longitude)};
    cout << "Distance between " << choose_city[0]->city_name << " and ";
    cout << choose_city[1]->city_name << " is : " << count_distance(lang_long) << " km " << endl;
    for (auto &i: cities) {
        delete i;
    }
    return 0;
}

city *get_city(char *line) {
    char *location[location_length];
    memset(location, 0, sizeof(char *) * location_length);
    uint32_t length = strlen(line);
    uint32_t count = 1;
    for (auto i = 0u; i < length; i++) {
        location[0] = line;
        if (',' == (*(line + i))) {
            location[count] = (line + i + 1);
            (*(line + i)) = '\0';
            count++;
        }
    }
    if (strlen(location[0]) > LENGTH_OF_NAME ||
        strlen(location[2]) > LENGTH_OF_NAME) {
        cout << "Warning! city name or country name is too long, it will be truncated." << endl;
    }
    city *will_return = new city(location[0], location[2], std::atof(location[3]), std::atof(location[4]));
    return will_return;
}

int input_city(string th, char *temp, city **cities) {
    cout << "input " << th << " city name, longer than or equal than 3 letter : ";
    cin.getline(temp, max_length);
    string trim_temp = trim(temp);
    memset(temp, '\0', max_length);
    memcpy(temp, &trim_temp[0], trim_temp.size());
    if (strlen(temp) < min_length) {
        cout << " please input city name longer than 3 letter" << endl;
        return -1;
    }
    vector<int> list = matches(temp, cities);
    if (list.size() > 1) {
        cout << "More than one city matches, please choose one from those cities using numbers begin at 0" << endl;
        for (auto i: list) {
            cout << cities[i]->city_name << " , " << cities[i]->country_name << endl;
        }
        cin.getline(temp, max_length);
        string trim_temp = trim(temp);
        memset(temp, '\0', max_length);
        memcpy(temp, &trim_temp[0], trim_temp.size());
        int count = std::atoi(temp);
        memset(temp, '\0', max_length);
        if (count >= 0 && count < static_cast<int32_t>(list.size())) {
            cout << "matches city " << cities[list[count]]->city_name << endl;
            return list[count];
        }
        cout << "Out of range,Please input once again." << endl;
        return -2;
    } else if (list.empty()) {
        cout << "No city matches, please input once again " << endl;
        return -3;
    } else {
        cout << "matches city " << cities[list[0]]->city_name << endl;
        return list[0];
    }
}

vector<int> matches(char *str, city **cities) {
    vector<int> will_return = {};
    for (int i = 0; i < LENGTH_OF_ARRAY; i++) {
        if (nullptr != strstr(cities[i]->city_name, str)) {
            will_return.push_back(i);
        }
    }
    return will_return;
}

string trim(string str) {
    if (str.empty()) {
        return str;
    }
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

bool judgement_equal_bye(string str) {
    if (str.size() == min_length &&
        ('b' == str[0] || 'B' == str[0]) &&
        ('y' == str[1] || 'Y' == str[1]) &&
        ('e' == str[2] || 'E' == str[2])
            ) {
        return true;
    }
    return false;
}

double count_distance(vector<double> &dous) {
    dous[0] = longitude_max - dous[0];
    dous[2] = longitude_max - dous[2];
    // data is la,lo ,la,lo
    double distance_1 =
            std::sin(std::abs(dous[0]) * PI / latitude_max) *
            std::sin(std::abs(dous[2]) * PI / latitude_max) *
            std::cos(std::abs(dous[1] - dous[3]) * PI / latitude_max);
    double distance_2 =
            std::cos(std::abs(dous[0]) * PI / latitude_max) *
            std::cos(std::abs(dous[2]) * PI / latitude_max);
    double distance = radius_earth * std::acos(distance_1 + distance_2);
    return distance;
}
