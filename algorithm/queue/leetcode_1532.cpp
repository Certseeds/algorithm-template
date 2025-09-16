// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023 nanoseeds

*/
#include <vector>
#include <cstdint>
#include <cstddef>

#ifdef CS203_DSAA_TEST_MACRO

namespace leetcode_1532 {
using std::vector;
#endif

class ProductOfNumbers {
protected:
    ProductOfNumbers() = default;

public:
    virtual void add(int32_t num) = 0;

    virtual int32_t getProduct(int32_t k) = 0;

    virtual ~ProductOfNumbers() = default;
};

class ProductOfNumbersNormal : public ProductOfNumbers {
private:
    std::vector<int32_t> mutlies{1}; // 前置1, 解决队列只有一个元素的问题
public:
    ProductOfNumbersNormal() = default;

    void add(int32_t num) override {
        if (num == 0) {
            this->mutlies.clear();
            this->mutlies.push_back(1);
            return;
        }
        const auto last = this->mutlies.back();
        this->mutlies.push_back(last * num);
    }

    int32_t getProduct(int32_t k) override {
        if (this->mutlies.size() <= static_cast<size_t>(k)) {
            return 0;
        }
        const auto maximum = this->mutlies[this->mutlies.size() - 1];
        const auto divided = this->mutlies[this->mutlies.size() - k - 1];
        return maximum / divided;
    }
};

class Solution {
public:
    ProductOfNumbers *pure() {
        return new ProductOfNumbersNormal();
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
