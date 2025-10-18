# Problem F (Order 1426)

## Description

Given an $N \times N$ matrix $A$, whose element in the $i$-th row and $j$-th column $A[i][j]$ equals

$$
A[i][j] = i^2 + 12345 \times i + j^2 - 12345 \times j + i \times j
$$

Please find the $M$-th smallest element in the matrix.


## Input

The 1st line is a positive integer $T$ ($1 \le T \le 10$) which is the number of test cases.

Then $T$ lines follow.

Each line has two integers $N$ ($1 \le N \le 50000$) and $M$ ($1 \le M \le N \times N$) for a test case.

## Output

Output $T$ lines.

Each line has an integer $ans$, the $M$-th smallest element in the matrix.

## Sample Input

```text
2
1 1
2 1
```

## Sample Output

```text
3
-12338
```

## Hint

The corresponding solutions to the sample are:

(1)

$$
A[1][1] = 1^2 + 12345 \times 1 + 1^2 - 12345 \times 1 + 1 \times 1 = 3
$$

(2)

$$
A[1][2] = 1^2 + 12345 \times 1 + 2^2 - 12345 \times 2 + 1 \times 2 = -12338
$$

$$
A[2][1]=22+12345 \times 2+12−12345 \times 1+2 \times 1=12352
$$

$$
A[2][2]=22+12345 \times 2+22−12345 \times 2+2 \times 2=12
$$

So the smallest element is -12338

## Solution / 思路解析

- 思路概述：矩阵元素按公式 $A[i][j] = i^2 + 12345i + j^2 -12345j + i j$ 定义，要求第 $M$ 小元素。常见做法是对答案值 $X$ 进行二分（答案是某个整数或实数范围内的值），并用一个计数函数计算矩阵中小于等于 $X$ 的元素个数 cnt。如果 cnt >= M，则可将上界收缩，否则下界上移。最终二分求得第 M 小元素的值。
- 计数函数实现要点（代码对应）：对每一行 i，关于 j 的不等式 $A[i][j] \le X$ 是一个关于 j 的二次不等式。把它化为标准二次形式后，计算判别式并求解实根区间 $[L,R]$，然后取整并交到 $[1,N]$ 区间内，令该行对总计数贡献为 $\max(0, R-L+1)$。遍历所有 i 累加计数得到 cnt。
- 复杂度：每次二分需要对 N 行做一次二次方程求根，复杂度 O(N)（每行常数时间，主要是开方操作）。二分迭代次数为 O(log RANGE)（RANGE 为值域长度），整体复杂度约 O(N log RANGE)。空间 O(1)（常数额外空间）。
- 精度与整型注意：实现中使用 64 位整数和 long double 来计算判别式与根，并对上下界做向上/向下取整以得到整数列范围，且提前剪枝（D<0）以提高稳定性。
- 边界与注意事项：
  - 确保对极端 X 值（非常大或非常小）时判别式不会产生误差；使用 long double 并在转换为整数时加减一个小量（如 1e-12）来抵消浮点误差。
  - 当 N 较大（例如 50000）时，count_leq 的每次遍历仍是可行的，但注意总二分次数与常数因子会影响运行时间。
