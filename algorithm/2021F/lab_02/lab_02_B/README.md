# Problem B (inferred)

## Description

For each input integer x, compute and print the value (x * (x + 1) * (x + 2)) / 6.

This equals the binomial coefficient C(x+2, 3).

## Input

- Line 1: integer T, the number of test cases.
- Next T lines (or whitespace separated values): each a single integer x.

## Output

Output T lines. The i-th line contains the integer result of `(x * (x + 1) * (x + 2)) / 6` for the i-th input x.

## Sample

### Sample Input

```text
2
1
2
```

### Sample Output

```text
1
4
```

## Implementation notes

- The implementation uses 64-bit integer arithmetic (`int64_t`) to reduce overflow risk. For very large x values consider using safe multiplication order or big integers.

- Mathematically, the expression equals C(x+2, 3), which may help reasoning about constraints and correctness.

## 复用信息

+ Contest 1186:CS203 2025 Fall Lab 1 Complexity + Binary Search
+ Contest 1093:CS203 2021 Fall Lab 02 Complexity + Binary Search
+ Contest 1094:CS217 2021 Fall Lab 02 Complexity + Binary Search
+ Contest 1135:CS203 2023 Fall Lab 1 Complexity + Binary Search

## Solution / 思路解析

- 思路概述：数学上该式子等价于组合数 $C(x+2,3)$。程序直接按代数表达式 $(x\times(x+1)\times(x+2))/6$ 计算。
- 实现要点：使用 `int64_t` 来保存中间乘积以避免溢出；若可能溢出 64 位，应使用大整数或按分步除法来减少中间值（例如先除以 2 或 3，当能整除时）。
- 复杂度：每个测试用例的计算为 O(1)，总时间 O(T)。空间 O(1)。
- 边界与注意事项：
  - 输入 x 若为负数（题面通常为非负），公式仍在整数意义下成立，但需确认题目约束。
  - 对于非常大的 x（接近 1e6~1e9），中间乘积可能超过 64 位，需按题面约束决定是否要更高精度类型或安全乘法顺序。
