// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#pragma GCC optimize(3, "Ofast", "inline", "no-stack-protector", "unroll-loops")
#include <list>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <vector>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

#ifdef ALGORITHM_TEST_MACRO
namespace lab_welcome_G{
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
using input_type = tuple<num_t, num_t>;
using output_type = num_t;

inline input_type read();

output_type cal(input_type data);

void output(const output_type &data);

int main() {
    auto input_data = read();
    auto output_data = cal(input_data);
    output(output_data);
    return 0;
}

inline input_type read() {
    num_t a{0}, b{0};
    std::cin >> a >> b;
    return std::make_tuple(a, b);
}

// ------------- 快速存在性搜索（整数 / 有理数） -------------
struct Rat {
    int64_t a, b; // a/b, 仅保证 b > 0，不做约分
};

static inline void rat_fix_sign(Rat &r) {
    if (r.b < 0) { r.b = -r.b; r.a = -r.a; }
}

// 纯整数搜索：除法仅在整除时允许
static bool dfs_int(int64_t v[], int len, int64_t m) {
    if (len == 1) return v[0] == m;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            const int64_t x = v[i], y = v[j];
            const int64_t vi = v[i], vj = v[j], vlast = v[len - 1];

            // 压缩：把最后一个移到 j 位置，用 i 放结果
            v[j] = vlast;

            // +
            v[i] = x + y;
            if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            // -
            v[i] = x - y;
            if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            v[i] = y - x;
            if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            // *
            v[i] = x * y;
            if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            // / 整除
            if (y != 0 && x % y == 0) {
                v[i] = x / y;
                if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            }
            if (x != 0 && y % x == 0) {
                v[i] = y / x;
                if (dfs_int(v, len - 1, m)) { v[i]=vi; v[j]=vj; v[len-1]=vlast; return true; }
            }

            // 还原
            v[i] = vi; v[j] = vj; v[len - 1] = vlast;
        }
    }
    return false;
}

// 有理数搜索：a/b 表示，最终判断 a == m*b
static bool dfs_rat(Rat v[], int len, int64_t m) {
    if (len == 1) {
        // 判断是否等于整数 m（无需约分）
        // 注意 b>0 已保证
        return v[0].a == m * v[0].b;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            const Rat X = v[i], Y = v[j];
            const Rat Vi = v[i], Vj = v[j], Vlast = v[len - 1];

            v[j] = Vlast;

            // +
            v[i].a = X.a * Y.b + Y.a * X.b;
            v[i].b = X.b * Y.b; rat_fix_sign(v[i]);
            if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }

            // -
            v[i].a = X.a * Y.b - Y.a * X.b;
            v[i].b = X.b * Y.b; rat_fix_sign(v[i]);
            if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }

            v[i].a = Y.a * X.b - X.a * Y.b;
            v[i].b = X.b * Y.b; rat_fix_sign(v[i]);
            if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }

            // *
            v[i].a = X.a * Y.a;
            v[i].b = X.b * Y.b; rat_fix_sign(v[i]);
            if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }

            // /
            if (Y.a != 0) {
                v[i].a = X.a * Y.b;
                v[i].b = X.b * Y.a; rat_fix_sign(v[i]);
                if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }
            }
            if (X.a != 0) {
                v[i].a = Y.a * X.b;
                v[i].b = Y.b * X.a; rat_fix_sign(v[i]);
                if (dfs_rat(v, len - 1, m)) { v[i]=Vi; v[j]=Vj; v[len-1]=Vlast; return true; }
            }

            v[i] = Vi; v[j] = Vj; v[len - 1] = Vlast;
        }
    }
    return false;
}

// 生成非降序多重集并统计
static void gen_multisets_and_count(int n, int64_t m, output_type &ans) {
    vector<int> cur(n, 1);

    // 递归生成
    struct Local {
        static void go(int idx, int last, int n, int64_t m, vector<int>& cur, output_type& ans) {
            if (idx == n) {
                // 乘积上界裁剪
                int64_t prod = 1;
                for (int i = 0; i < n; ++i) prod *= cur[i];
                if (m > prod) return;

                // 先整数存在性
                int64_t iv[4];
                for (int i = 0; i < n; ++i) iv[i] = cur[i];
                if (dfs_int(iv, n, m)) return; // 存在纯整数表达式 => 不合法

                // 再有理数存在性
                Rat rv[4];
                for (int i = 0; i < n; ++i) { rv[i].a = cur[i]; rv[i].b = 1; }
                if (dfs_rat(rv, n, m)) ++ans;
                return;
            }
            for (int v = last; v <= 13; ++v) {
                cur[idx] = v;
                go(idx + 1, v, n, m, cur, ans);
            }
        }
    };
    Local::go(0, 1, n, m, cur, ans);
}

output_type cal(input_type data) {
    num_t n{0};
    int64_t m{0};
    tie(n, m) = data;

    // 全局上界：若 m > 13^n，直接为 0
    int64_t global_max = 1;
    for (int i = 0; i < n; ++i) global_max *= 13;
    if (m > global_max) return 0;

    output_type ans = 0;
    gen_multisets_and_count(n, m, ans);
    return ans;
}

void output(const output_type &data) {
    cout << data << end;
}

static const auto faster_streams = [] {
    srand(time(nullptr));
    // use time to init the random seed
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 关闭c++风格输入输出 , 与C风格输入输出的同步, 提高性能.
    return 0;
}();

#ifdef ALGORITHM_TEST_MACRO
}
#endif
