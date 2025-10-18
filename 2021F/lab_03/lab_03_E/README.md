---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_E

## Description

You are given a random sequence $\{a\}$ of $n$ distinct elements.

You can swap adjacent elements, and the cost of swapping $(a_i,a_{i+1})$ equals $\min(a_i,a_{i+1})$.

Compute the minimum total cost to sort the sequence in ascending order by performing adjacent swaps.

## Input

The first line contains an integer $n$.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$.

Constraints: $1 \le n \le 10^5$, $0 \le a_i \le 10^9$.

## Output

Output a single integer: the minimum total cost required to sort the sequence.

## Sample

### Sample Input

```text
5
1 3 2 4 5
```

### Sample Output

```text
2
```

## 复用信息

+ Contest 1095:CS203 2021 Fall Lab 03 Sorting
+ Contest 1096:CS217 2021 Fall Lab 03 Sorting
+ Contest 1163:CS203 2024 Fall Lab 2

## Algorithm Analysis (实现说明)

+ 思路: 题目要求通过相邻交换把数组排序, 交换 (a_i, a_{i+1}) 的代价为 min(a_i, a_{i+1})。将数组排序所需的代价等于对每次把较大的元素向右移动时累加被它跨越的较小元素的值。一个等价的视角是: 对于当前元素 x，考虑其左侧比 x 大的元素的个数 cnt，大元素每次与 x 交换时的最小值贡献为 x，因此该元素对答案的贡献为 x * cnt。
+ 实现要点: 先做坐标压缩得到秩 rank；使用 Fenwick 树维护已遍历元素的计数。遍历原数组，从左到右查询当前值右侧的已出现更大的元素数 greater = i - leq（其中 leq 是 <= 当前值 的计数），把 a[i] * greater 累加到答案，再把当前值加入 Fenwick 树。
+ 复杂度: 坐标压缩 O(n log n)，遍历与 Fenwick 操作 O(n log n)。总体 O(n log n)，空间 O(n)。
+ 边界情况: n<=1 时直接返回 0；重复元素的处理通过压缩与 <= 计数保证正确性。
