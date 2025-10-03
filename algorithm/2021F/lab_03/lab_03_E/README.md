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
