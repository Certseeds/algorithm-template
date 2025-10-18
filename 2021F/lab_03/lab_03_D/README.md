---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_D

## Description

Given a sequence $\{a\}$ of $n$ distinct numbers, where $n$ is even.

Permute the sequence to form a circle such that no element equals the average of its two neighbors.

Formally, find a permutation $\{b\}$ of $\{a\}$ satisfying:

- For all $i \in \{2,3,\dots,n-1\}$: $b_i \ne (b_{i-1}+b_{i+1})/2$.
- Also $b_1 \ne (b_2 + b_n)/2$
- $b_n \ne (b_{n-1} + b_1)/2$.

There may be multiple valid answers. Print any one.

A solution is guaranteed to exist for every test case.

## Input

The first line contains an integer $n$. The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

Constraints: $n$ is even and $3 \le n \le 10^6$, $0 \le a_i \le 10^9$.

## Output

Print one line with $n$ integers: $b_1, b_2, \dots, b_n$.

## Analysis

算法先对数组进行排序，然后将前半部分和后半部分交替放置以构造圆排列。

每个较小的元素都会与较大的元素相邻，因此其值不可能等于两邻居的平均值；对较大元素亦然。

由于元素互不相同且 n 为偶数，两个半部分不会重叠，交错放置得到的序列是原序列的一个合法置换。

排序步骤时间复杂度为 $O(n\log n)$，交错拼接为线性时间，额外空间仅为输出数组（或常数工作空间）。

## Sample

### Sample Input

```text
6
3 2 1 4 5 6
```

### Sample Output

```text
1 2 4 3 5 6
```

> 似乎样例有错? 应该是 `1 4 2 5 3 6`
