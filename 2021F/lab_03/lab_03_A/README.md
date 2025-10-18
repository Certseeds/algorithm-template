---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_A

## Description

Let $A$ and $B$ be two non-decreasing arrays of sizes $n$ and $m$ respectively.

We form $C = \{A_1, A_2, \dots, A_n, B_1, B_2, \dots, B_m\}$. A pair $(C_i, C_j)$ is a reverse pair when $C_i > C_j$ and $i < j$.

For each test case compute two outputs. First, the number of reverse pairs in $C$.

Second, output the merged non-decreasing sequence $C$.

## Input

The first line contains an integer $T$ ($1 \le T \le 10$). Each test case contains three lines.

The first line of a test case contains two integers $n$ and $m$.

The second line contains $n$ integers $A_1, A_2, \dots, A_n$.

The third line contains $m$ integers $B_1, B_2, \dots, B_m$.

Constraints: $1 \le n, m \le 10^5$ and $0 \le A_i, B_j \le 10^9$.

## Output

For each test case print two lines. The first line is the number of reverse pairs in $C$.

The second line is the merged sequence $C$: $C_1, C_2, \dots, C_{n+m}$.

## Sample

### Sample Input

```text
2
2 4
2 3
1 2 3 4
2 2
3 4
1 2
```

### Sample Output

```text
3
1 2 2 3 3 4 4
1
2 3 4 1 2
```

## Notes

This problem can be solved by merging the two sorted arrays with a two-pointer method.

While merging, count how many elements from the remaining left part are greater than the current element taken from the right part to accumulate cross-inversions.

## Analysis

该解法在合并两个非递减数组的同时统计跨数组的逆序对。

做法是将左数组和右数组拷贝到同一个工作缓冲区，然后用双指针进行归并；当从左半部分取出一个元素时，增加当前已被取出的右半部分元素数量，作为该元素所贡献的逆序对个数。

合并后的值保存在缓冲区中，最终输出合并的非递减序列以及逆序对总数。

此方法对每个测试用例的时间复杂度为 $O(n+m)$，需要 $O(n+m)$ 的额外内存用于临时缓冲区。
