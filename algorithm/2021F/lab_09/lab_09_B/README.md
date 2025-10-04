# Problem B

## Description

We have a chess board.

It has $8 \times 8$ grids, the index from bottom to top is 1-8, from left to right is a-h.

The knight moves a 3×2 square at each step.

Given the start position of the knight, please find the minimum number of steps he should perform to reach the end position.

### Input

The first line gives $t(1\leq t\leq 5000)$ indicating the total number of test data sets.

Each subsequent row of $t$ will give a start point and an end point.

### Output

For each test case, print minimum number of steps needed to reach the end

### Sample Input

``` log
3
f6 f6
e2 e4
e2 e3
```

### Sample Output

``` log
0
2
3
```

### HINT

### 题目分析

问题：骑士在 8x8 棋盘上的最短跳跃步数。

思路：预构造静态的骑士跳跃图（64 个顶点，最多 8 条出边），对每个查询用 BFS 求最短路。图使用链式前向星表示以满足复用要求。

复杂度：构造图 O(1)（常量），每次 BFS 最坏 O(V+E)=O(64)。

要点：坐标与编号之间转换要准确（chess_to_index），并对相同起点与终点返回 0。

