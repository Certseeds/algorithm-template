// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-19 22:37:16
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_04.hpp"

int32_t question4() {
    // file path
    std::fstream file("./../../../Assignment_4/lab_records.csv");
    // read
    if (!file.is_open()) {
        cout << "open file fail " << endl;
        return -1;
    }
    std::string line;
    vector<int32_t> lab_scores(lab_number, 0);
    // read
    while (!file.eof()) {
        getline(file, line);
        if (line.empty()) {
            continue;
        }
        //cout << line << endl;
        auto temp = str_to_scores(line);
        // count scores.
        for (uint32_t i = 0; i < temp.second.size(); ++i) {
            lab_scores[i] += temp.second[i];
        }
    }
    // output
    int score_sum = std::accumulate(lab_scores.begin(), lab_scores.end(), 0);
    for (int32_t i = 0; i < lab_number; i++) {
        if (lab_scores[i] * lab_number < score_sum) {
            cout << (i + 1) << endl;
        }
    }
    return 0;
}

std::pair<int32_t, vector<int32_t>> str_to_scores(const std::string &str_in) {
    // transfer string to scores.
    std::string str(str_in);
    vector<int32_t> will_return;
    int32_t id = std::atoi(str.substr(0, str.find_first_of(',')).c_str());
    str = str.substr(str.find_first_of(',') + 1);
    while (0 != std::count(str.begin(), str.end(), ',')) {
        //cout << str.find_first_of(',') << endl;
        will_return.push_back(std::atoi(str.substr(0, str.find_first_of(',')).c_str()));
        str = str.substr(str.find_first_of(',') + 1);
    }
    will_return.push_back(std::atoi(str.c_str()));
    return std::make_pair(id, will_return);
}
