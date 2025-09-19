// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#ifdef CS203_DSAA_TEST_MACRO

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace leetcode_1409 {
using std::unordered_map;
using std::vector;
#endif

class bit final {
private:
    vector<int32_t> vec{};
    const int32_t max_size;

    static int32_t lowbit(int32_t num) {
        return num & -num;
    }

public:
    explicit bit(const int32_t size) : vec(size + 1, 0), max_size(size) {}

    void update(const int32_t location, const int32_t num) {
        assert(location >= 1);  // 入参并不从零开始,
        for (int32_t pos{location}; pos <= max_size; pos += lowbit(pos)) {
            vec[pos] += num;
        }
    }

    int32_t query(const int32_t location) const {
        int32_t ans{0};
        for (int32_t pos{location}; pos > 0; pos -= lowbit(pos)) {
            ans += vec[pos];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int32_t> processQueries(const vector<int32_t> &queries, int32_t m) {
        vector<int32_t> will_return;
        if (queries.empty()) {
            return will_return;
        }
        unordered_map<int32_t, int32_t> num_pos;
        for (int32_t i{0}; i < m; ++i) {
            num_pos[i + 1] = i;
        }
        for (const auto &i: queries) {
            int32_t pos = num_pos[i];
            will_return.push_back(pos);
            for (auto &j: num_pos) {
                if (j.second < pos) {
                    j.second++;
                }
            }
            num_pos[i] = 0;
        }
        return will_return;
    }

    vector<int> processQueries2(const vector<int> &queries, int32_t m) {
        const int32_t query_nums = queries.size();
        bit tree(m + query_nums);
        vector<int32_t> pos(m + 1);
        for (int i{1}; i <= m; ++i) {
            pos[i] = query_nums + i;
            tree.update(query_nums + i, 1);
        }
        vector<int32_t> ans;
        for (int i{0}; i < query_nums; ++i) {
            const auto query{queries[i]};
            const auto loca = pos[query];
            tree.update(loca, -1);
            ans.push_back(tree.query(loca));
            pos[query] = query_nums - i;
            tree.update(pos[query], 1);
        }
        return ans;
    }
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
