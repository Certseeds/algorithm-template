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

### Input

```text
2 1 1
10 8
6 1
```

### Output

```text
21
```

## 复用信息

+ Contest 1095:CS203 2021 Fall Lab 03 Sorting
+ Contest 1096:CS217 2021 Fall Lab 03 Sorting
+ Contest 1137:CS203 2023 Fall Lab 2 Sorting
+ Contest 1187:CS203 2025 Fall Lab 2 Sorting
