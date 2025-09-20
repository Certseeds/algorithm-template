// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanos

*/
#include <utility>
#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class people {
public:
    int32_t age{0};
    bool male;
    vector<string> schools;

    people(bool male_, const vector<string> &schools_) : male(male_), schools(schools_) {};

    explicit people(bool male_) : male(male_), schools() {}

    static people &always() {
        static people emp{true, {"social"}};
        return emp;
    }
};

typedef people people1;

int main() {
    for (auto &&var: people1::always().schools) {
        std::cout << var << std::endl;
    }
}
