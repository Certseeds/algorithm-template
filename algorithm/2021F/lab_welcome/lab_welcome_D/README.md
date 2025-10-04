# Problem D (Order 1417)

## Description

Given two arrays $A$ and $B$ with the same length $n-1$. We want to insert two integers into $A_n$ and $B_n$ ($1 \le A_n \le h$, $1 \le B_n \le h$) such that:

1. the sum of array $A$ without its largest and smallest values is larger than the sum of array $B$ without its largest and smallest values;
2. $A_n - B_n$ is minimized.

## Input

The first line contains two integers: $n, h$ ($2 \le n \le 10^5$, $1 \le h \le 10^9$).
The second line contains $n-1$ integers: $A_1, A_2, \dots, A_{n-1}$, each in $[1, h]$.
The third line contains $n-1$ integers: $B_1, B_2, \dots, B_{n-1}$, each in $[1, h]$.

## Output

Print the minimum value of $A_n - B_n$ if a proper pair $(A_n, B_n)$ exists; otherwise print "IMPOSSIBLE".

## Sample Input

``` log
3 4
1 3
2 4
```

## Sample Output

``` log
1
```

## Hint

You can insert 3 into $A_n$ and 2 into $B_n$; then the sum of $A$ excluding its max and min is 3, the sum of $B$ excluding its max and min is 2, and $A_n - B_n = 1$ which is minimal.

## 实现分析

- 实现要点: `main.cpp` 首先分析已有数组 A、B 的总和、最小值和最大值 (通过 `analysis`), 然后把需要寻找的目标差值 d = A_n - B_n 转换为对 B_n 的可行区间查找问题. 核心函数 `check` 根据分段函数 fA(aX)、fB(bX) (即删除最大/最小项后的和) 在候选断点处进行判断, 利用单调性在 d 空间上做二分求最小可行 d.
- 复杂度: 分析阶段 O(n). `check` 函数主要在 O(1) 到 O(K) 次候选点检查 (K 为常数, 附带至多 50 次采样), 总体时间复杂度为 O(n + log h * K). 空间复杂度 O(1).
- 注意事项: 实现中将一些边界点 (最小值、最大值以及区间两端) 及其邻近值作为候选点进行检查, 以保证分段边界处的正确性; 对较大区间使用采样以避免遍历所有值.
