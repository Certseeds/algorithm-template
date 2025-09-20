// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
/**
 * @Github: https://github.com/Certseeds
 * @Author: nanoseeds
 * @Date: 2020-04-19 22:37:16
 * @LastEditors  : nanoseeds
 */
#include "Assignment_4_03.hpp"

int32_t question3() {
    // file
    std::ofstream file("./lab_records.csv");
    if (!file.is_open()) {
        cout << "Open file failed" << endl;
        return 0;
    }
    // write
    for (const auto &i: umap) {
        file << i.first << ",";
        for (uint32_t j = 0; j < i.second.size() - 1; ++j) {
            file << i.second[j] << ",";
        }
        file << i.second.back() << endl;
    }
    // close
    file.close();
    return 0;
}
