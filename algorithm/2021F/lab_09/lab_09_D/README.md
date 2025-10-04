# Problem D

## Description

An $N\times M$ matrix of non-negative integers.

Please take out several numbers from it such that the summation of these numbers is maximized.

You should guarantee that any two taken out numbers are not adjacent.

We say $a$ is adjacent to $b$ if $b$ is one of $a$'s 8-connected neighborhoods in the matrix.

### Input

The first row has a positive integer $T(1\leq T\leq 20)$, which indicates that there are T groups of data. For each set of data, the first row has two positive integers $N,M(1\leq N,M\leq 6)$, which describe the number matrix as N rows and M columns. The next N rows, with M non-negative integers in each row, describe this numerical matrix.

### Output

A total of T rows, one non-negative integer per row, and the output of the resulting answer.

### Sample Input

``` log
3
4 4
67 75 63 10
29 29 92 14
21 68 71 56
8 67 91 25
2 3
87 70 85
10 3 17
3 3
1 1 1
1 99 1
1 1 1
```

### Sample Output

``` log
271
172
99
```

### HINT

### 题目分析

问题：在 n×m 网格上选择若干格子使得任意两格子不在 8 邻域内，求最大权和。

思路：保留链式前向星构建 8 邻域图以满足要求，但实际算法采用逐行掩码 DP（mask DP）。对每一行枚举不相邻的掩码，状态转移检查当前行与前一行是否有垂直或对角冲突，转移更新最大和。

复杂度：`O(n * 2^m * 2^m)` (当 m 较小时可行)。

要点：预筛选行内合法掩码（无相邻位），转移时排除与前一行的竖直与对角冲突以保证 8 邻域约束。

