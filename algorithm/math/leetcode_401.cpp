// SPDX-License-Identifier: AGPL-3.0-or-later
/*
algorithm_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

namespace leetcode_401 {
using std::vector;
using std::string;
#endif

class Solution {
private:
    string minutes_toString(const int x) {
        string will_return;
        if (x < 10) {
            will_return.push_back('0');
            will_return.push_back(x + '0');
        } else {
            will_return.push_back((x / 10) + '0');
            will_return.push_back((x % 10) + '0');
        }
        return will_return;
    }

    vector<string> hours_complex(const int x) {
        switch (x) {
            case 0: {
                return {"0"};
            }
            case 1: {
                return {"1", "2", "4", "8"};
            }
            case 2: {
                return {"3", "5", "6", "9", "10"};
            }
            case 3: {
                return {"7", "11"};
            }
            default: {
                return {};
            }
        }
    }

    vector<string> minutes_complex(const int x) {
        vector<int> nums;
        switch (x) {
            case 0: {
                return {"00"};
            }
            case 1: {
                return {"01", "02", "04", "08", "16", "32"};
            }
            case 5: {
                return {"31", "47", "55", "59"};
            }
            case 2: {
                for (int32_t i{0}; i < 6; i++) {
                    for (int32_t j{i + 1}; j < 6; j++) {
                        nums.push_back((1 << i) + (1 << j));
                    }
                }
                break;
            }
            case 3: {
                for (int32_t i{0}; i < 6; i++) {
                    for (int32_t j{i + 1}; j < 6; j++) {
                        for (int32_t k{j + 1}; k < 6; k++) {
                            nums.push_back((1 << i) + (1 << j) + (1 << k));
                        }
                    }
                }
                break;
            }
            case 4: {
                for (int32_t i{0}; i < 6; i++) {
                    for (int32_t j{i + 1}; j < 6; j++) {
                        if (63 - (1 << i) - (1 << j) < 60) {
                            nums.push_back(63 - (1 << i) - (1 << j));
                        }
                    }
                }
                break;
            }
            default: {
                return {};
            }
        }
        vector<string> will_return;
        for (auto i: nums) {
            will_return.push_back(minutes_toString(i));
        }
        return will_return;
    }

public:
    vector<string> readBinaryWatch(const int32_t num) {
        vector<string> will_return;
        for (int32_t k{0}; k <= std::min(4, num); k++) {
            vector<string> hours = hours_complex(k);
            vector<string> minutes = minutes_complex(num - k);
            for (const auto &i: hours) {
                for (const auto &j: minutes) {
                    will_return.push_back(i + ":" + j);
                }
            }
        }
        return will_return;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
