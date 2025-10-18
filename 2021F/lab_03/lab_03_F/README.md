---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_F

## Description

You have $n$ plants.

The $i$-th plant has height $h_i$ and strength $s_i$.

There are two fertilizers: $F_h$ and $F_s$.

Applying one $F_h$ to a plant doubles its height.

Applying one $F_s$ sets the plant's strength equal to its height.

You may use at most $p$ bags of $F_h$ and at most $q$ bags of $F_s$.

Maximize the sum of strengths $\sum s_i$ after applying at most $p$ of $F_h$ and at most $q$ of $F_s$.

## Input

The first line contains three integers $n, p, q$.

Then follow $n$ lines.

Each of the next $n$ lines contains two integers $h_i, s_i$.

Constraints: $1 \le n \le 2\cdot 10^5$, $0 \le p \le 20$, $0 \le q \le 2\cdot 10^5$, $1 \le h_i, s_i \le 10^9$.

## Output

Print one integer: the maximum possible sum $\sum s_i$.

## Sample

### Sample Input

```text
2 1 1
10 8
6 1
```

### Sample Output

```text
21
```

## 复用信息

+ Contest 1095:CS203 2021 Fall Lab 03 Sorting
+ Contest 1096:CS217 2021 Fall Lab 03 Sorting
+ Contest 1137:CS203 2023 Fall Lab 2 Sorting
+ Contest 1187:CS203 2025 Fall Lab 2 Sorting

## Algorithm Analysis (实现说明)

+ 思路: 将两种操作(对高度使用 F_h 翻倍, 使用 F_s 将强度设为高度)组合来最大化总强度。先把每个植物不使用额外肥料时的基线强度 base = sum s_i 记下。对每个植物，定义 g0 = max(h_i - s_i, 0) 表示使用 F_s 可带来的净增量。使用最多 q 个 F_s 时，优先把 q 个 g0 最大的植物设为 s= h。
+ 对于最多 p 次将某一植物的高度翻倍的操作（p<=20），可以枚举把所有 p 放在某一植物上的情况: 计算该植物翻倍后的 g1 = max(h_i * 2^p - s_i, 0)，并把 g0 的排序中替换原位置后计算前 q 个的和得到候选值。取所有枚举中的最大值。为高效实现, 先对 g0 做降序排序并构建前缀和; 枚举时用二分/插入位置快速计算替换后前 q 个之和。
+ 复杂度: 排序 O(n log n)；枚举 n 个位置并在 O(log n) 或 O(1) 时间内计算新前缀和，总体 O(n log n)。空间 O(n)。
+ 边界情况: p=0 时相当于只使用 F_s；q=0 时只考虑翻倍的增益；当 q>n 时取 n 个最大增益。
