# Problem D (Order 1424)

## Description

Given a nondecreasing sequence $a$ of $n$ integers $a_1, a_2, \dots, a_n$.

Please find the number of pairs of indices $i, j$ (with $i < j$) such that $a_i + a_j$ is a power of two.

## Input

The 1st line is a positive integer $n$ ($1 \le n \le 100000$).

The 2nd line contains $n$ integers: $a_1, a_2, \dots, a_n$.

For each $a_i$ ($1 \le a_i \le 10^9$).

## Output

Print the number of pairs of indices $i, j$ ($i < j$) such that $a_i + a_j$ is a power of two.

## Sample Input

```text
4
1 2 3 7
```

## Sample Output

```text
2
```

## Hint

The corresponding solutions to the sample are: $1 + 3 = 2^2$; $1 + 7 = 2^3$.

## Solution / 思路解析

- 思路概述：题目要求统计下标对 $(i,j)$，使得 $i<j$ 且 $a_i+a_j$ 是 2 的幂。常见做法是利用哈希表统计每个数的出现次数，然后对每个数枚举可能的 2 的幂值 $2^t$，查找补数 $2^t - a_i$ 的频次并累加。最后注意去重与自配对的处理。
- 程序实现要点（与代码对应）：
  - 首先统计每个值的出现次数（哈希表 `sizes`）。
  - 对于同值配对（$a_i=a_j$），当 $2a_i$ 恰好是某个 $2^t$ 时，需要把组合数 $C(cnt,2)$ 累加到结果（代码中以 `same_count` 累加）。
  - 然后遍历每个位置 i，枚举所有较大的 2 的幂 `arr[j]`，若存在补数 `arr[j]-a[i]` 则使用其出现信息（位置/计数）来保证只计入 $i<j$ 的配对；为避免重复计数，代码通过把位置和计数打包到 uint64 并用 `uset` 累计。
- 复杂度：枚举每个元素并对 31 个可能的 2 的幂进行查找，时间复杂度约为 O(n * log MAX_VAL)（这里常数为 31），空间复杂度 O(n) 用于计数哈希表。
- 边界与注意事项：
  - 需要小心重复元素导致的重复计数（代码显式分开处理相同元素的内部配对）。
  - 注意题中约束下最大可能的 2 的幂数量（此实现假定小于 2^31），使用固定的幂数组避免重复计算。
