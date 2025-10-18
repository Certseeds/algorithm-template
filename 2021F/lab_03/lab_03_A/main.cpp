// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
//@Tag Done
#include <tuple>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_03_A{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::sort;
using std::tuple;
using std::vector;
static constexpr const char end{'\n'}, space{' '};

using num_t = int32_t;
using input_type = tuple<vector<vector<num_t>>, vector<vector<num_t>>>;
using output_type = tuple<vector<uint64_t>, vector<vector<num_t>>>;

inline input_type read();

output_type cal(const input_type &data);

void output(const output_type &data);

int main() {
    const auto input_data = read();
    const auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t tao{0}; // τ
    std::cin >> tao;
    vector<vector<num_t>> DList(tao);
    vector<vector<num_t>> EList(tao);
    for (int32_t i{0}; i < tao; i++) {
        num_t niu{0}, miu{0}; // ν,μ
        std::cin >> niu >> miu;
        DList[i] = vector<num_t>(niu, 0);
        EList[i] = vector<num_t>(miu, 0);
        for (int32_t j{0}; j < niu; ++j) {
            std::cin >> DList[i][j];
        }
        for (int32_t j{0}; j < miu; ++j) {
            std::cin >> EList[i][j];
        }
    }
    return std::make_tuple(DList, EList);
}

uint64_t cal_detail(vector<num_t> &vec, size_t d_length) {
    const auto vec_size = vec.size();
    vector<num_t> vec_output(vec_size);
    size_t left{0}, left_end{d_length - 1};
    size_t right{d_length}, right_end{vec_size - 1};
    size_t order{0};
    uint64_t will_return{0};
    for (; left <= left_end && right <= right_end; order++) {
        if (vec[left] <= vec[right]) {
            vec_output[order] = vec[left];
            will_return += (right - left_end - 1);
            left++;
        } else {
            vec_output[order] = vec[right];
            right++;
        }
    }
    for (; left <= left_end; left++, order++) {
        vec_output[order] = vec[left];
        will_return += (right - left_end - 1);
    }
    for (; right <= right_end; right++, order++) {
        vec_output[order] = vec[right];
    }
    vec = vec_output;
    return will_return;
}

output_type cal(const input_type &data) {
    vector<vector<num_t>> DList;
    vector<vector<num_t>> EList;
    tie(DList, EList) = data;
    vector<uint64_t> pairs;
    vector<vector<num_t>> CList;
    const auto data_length = DList.size();
    for (size_t i{0}; i < data_length; i++) {
        const auto d = DList[i];
        const auto e = EList[i];
        vector<num_t> list{d.begin(), d.end()};
        list.insert(list.end(), e.begin(), e.end());
        uint64_t count = cal_detail(list, d.size());
        pairs.emplace_back(count);
        CList.emplace_back(list);
    }
    return std::make_tuple(pairs, CList);
}

void output(const output_type &data) {
    vector<uint64_t> pairs;
    vector<vector<num_t>> CList;
    tie(pairs, CList) = data;
    const auto data_length = pairs.size();
    for (size_t i{0}; i < data_length; ++i) {
        cout << pairs[i] << end;
        for (auto &&ele: CList[i]) {
            cout << ele << space;
        }
        cout << end;
    }
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步,提高性能.
    return 0;
}();
#ifdef ALGORITHM_TEST_MACRO
}
#endif
