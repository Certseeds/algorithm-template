## Description

Given n cities and m roads.

Sinzo wants to build these m roads one by one to guarantee all cities are connected, i.e., each city can reach all other cities.

Sinzo wants to know how much roads after she built that all the n cities are connected.

### Input

The first line contains 2 integers, n, m $ (1\leq n, m \leq 10^5) $, indicating there are n cities and m roads to build.

The next m lines, each line contains 2 integers u, v $ (1\leq u, v \leq n) $, indicating Sinzo wants to build a unidirectional road from u to v.

Note that: these m roads are built in order.

### Output

Please output the minimum roads to build.

If Sinzo build all m roads, the n cities are not connected, then output -1.

### Sample Input

``` log
4 5
1 2
2 3
3 4
1 3
4 1
```

### Sample Output

``` log
5
```

### 算法分析

本题要求在有向图中，按顺序依次加入边，找到第一个使所有城市强连通的时刻。

实现采用链式前向星存储边，分别维护正向和反向图。

- 每次二分查找前缀长度，判断前 k 条边是否使图强连通。
- 强连通性判定通过两次 DFS（正向和反向），从 1 号城市出发，遍历所有可达节点。
- 若两次遍历都能覆盖所有城市，则当前前缀满足要求。
- 若所有边加入后仍不强连通，则输出 -1。

整体时间复杂度为 $O(m \log m \cdot n)$，适合 $n, m$ 均为 $10^5$ 级别的稀疏图。
