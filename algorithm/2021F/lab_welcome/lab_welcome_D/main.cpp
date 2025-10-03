// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <limits>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <memory>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_D{
#endif

using std::cin;
using std::tie;
using std::cout;
using std::list;
using std::sort;
using std::array;
using std::deque;
using std::queue;
using std::stack;
using std::tuple;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;
static constexpr const char end{'\n'};

using num_t = int32_t;
using input_type = tuple<vector<num_t>, vector<num_t>, num_t>;

struct output_type {
    bool OK{true};
    num_t number{-1};

    explicit output_type(bool ok) : OK(ok) {}

    output_type(bool ok, num_t number) : OK(ok), number(number) {}
};

struct arrayInfo {
    int64_t sum{static_cast<int64_t>(0)};
    num_t maxV{std::numeric_limits<num_t>::min()};
    num_t minV{std::numeric_limits<num_t>::max()};
};

static inline input_type read();

static output_type cal(const input_type &data);

static void output(const output_type &data);

static arrayInfo analysis(const vector<num_t> &vec);

bool check(const arrayInfo &aInfo, const arrayInfo &bInfo, num_t distance, num_t maxValue);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t n{0}, h{0};
    std::cin >> n >> h;
    vector<num_t> A(n - 1, 0);
    vector<num_t> B(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> B[i];
    }
    return std::make_tuple(A, B, h);
}

static output_type cal(const input_type &data) {
    vector<num_t> A{}, B{};
    num_t h{};
    tie(A, B, h) = data;
    const auto aInfo = analysis(A);
    const auto bInfo = analysis(B);

    // search d = aX - bX in range [1-h, h-1]
    int64_t low = static_cast<int64_t>(1) - static_cast<int64_t>(h);
    int64_t high = static_cast<int64_t>(h) - static_cast<int64_t>(1);
    auto exists_for_d = [&](int64_t d) {
        return check(aInfo, bInfo, static_cast<num_t>(d), h);
    };

    // If no possible d yields true, return impossible
    // We can use binary search because existence is monotone in d (if exists for d then exists for larger d)
    int64_t left = low, right = high;
    int64_t answer = std::numeric_limits<int64_t>::max();
    while (left <= right) {
        int64_t mid = left + (right - left) / 2;
        if (exists_for_d(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (answer == std::numeric_limits<int64_t>::max()) {
        return output_type{false};
    }
    return output_type{true, static_cast<num_t>(answer)};
}


arrayInfo analysis(const vector<num_t> &vec) {
    arrayInfo will_return{};
    for (const auto &num: vec) {
        will_return.sum += num;
        will_return.maxV = std::max(will_return.maxV, num);
        will_return.minV = std::min(will_return.minV, num);
    }
    return will_return;
}

void output(const output_type &data) {
    const static string impossible = R"(IMPOSSIBLE)";
    if (data.OK) {
        std::cout << data.number << std::endl;
    } else {
        std::cout << impossible << std::endl;
    }
}

bool check(const arrayInfo &aInfo, const arrayInfo &bInfo, num_t distance, num_t maxValue) {
    // distance may be negative; convert to int64 for calculations
    int64_t d = static_cast<int64_t>(distance);
    int64_t h = static_cast<int64_t>(maxValue);

    // valid bX range so that aX = bX + d is within [1,h]
    int64_t b_low = std::max<int64_t>(1, 1 - d);
    int64_t b_high = std::min<int64_t>(h, h - d);
    if (b_low > b_high) return false;

    // helper to compute fA and fB
    auto fA = [&](int64_t aX) -> int64_t {
        if (aX <= aInfo.minV) return aInfo.sum - aInfo.maxV;
        if (aX >= aInfo.maxV) return aInfo.sum - aInfo.minV;
        return aInfo.sum - aInfo.minV - aInfo.maxV + aX;
    };
    auto fB = [&](int64_t bX) -> int64_t {
        if (bX <= bInfo.minV) return bInfo.sum - bInfo.maxV;
        if (bX >= bInfo.maxV) return bInfo.sum - bInfo.minV;
        return bInfo.sum - bInfo.minV - bInfo.maxV + bX;
    };

    // candidate breakpoints where piecewise definition changes
    // for bX these are: b_min, b_max
    // for aX = bX + d these are: a_min - d, a_max - d
    vector<int64_t> cand;
    cand.push_back(b_low);
    cand.push_back(b_high);
    cand.push_back(bInfo.minV);
    cand.push_back(bInfo.maxV);
    cand.push_back(static_cast<int64_t>(aInfo.minV) - d);
    cand.push_back(static_cast<int64_t>(aInfo.maxV) - d);

    // also include nearby integers to cover boundaries
    for (auto x : cand) {
        for (int delta = -1; delta <= 1; ++delta) {
            int64_t v = x + delta;
            if (v >= b_low && v <= b_high) {
                int64_t aX = v + d;
                if (aX < 1 || aX > h) continue;
                if (fA(aX) > fB(v)) return true;
            }
        }
    }

    // As a fallback, check a few evenly spaced points (shouldn't be needed but safe)
    int checks = 50;
    if (b_high - b_low + 1 <= checks) {
        for (int64_t vx = b_low; vx <= b_high; ++vx) {
            int64_t aX = vx + d;
            if (aX < 1 || aX > h) continue;
            if (fA(aX) > fB(vx)) return true;
        }
    } else {
        for (int i = 0; i <= checks; ++i) {
            int64_t vx = b_low + (b_high - b_low) * i / checks;
            int64_t aX = vx + d;
            if (aX < 1 || aX > h) continue;
            if (fA(aX) > fB(vx)) return true;
        }
    }

    return false;
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
