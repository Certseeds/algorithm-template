## Description

There a big hexagon, the side length is n, so there are $3n^2+3n+1$ points, and $9n^2+3n$ edges.

Each point has a weight.

We define the weight of each edge as the multiplying result of the weight of two endpoints in it.

Please find out the minimum cost to connect these $3n^2+3n+1$ points.

### Input

The first line contains an integer n $ (1\leq n\leq 200) $, indicating the edge length of the hexagon.

The next $2n+1$ lines, line i contains $2n+1-|i-n-1|$ integers w $ (1\leq w\leq 10^6) $, indicating the weight of each node.

### Output

Output the minimum cost in one line.

### Sample Input

``` log
1
2 2
2 1 2
2 2
```

### Sample Output

``` log
12
```

### 算法分析

本题要求在六边形网格上求最小生成树。

算法采用链式前向星存储图结构，节点编号按输入顺序分配。

边权为相邻两点权值之积，遍历所有节点，按六边形规则连边。

最小生成树采用 Prim 算法，利用优先队列维护当前可达最小边权。

每次选择未访问的最小边权节点，累计权值，直到所有节点被访问。

整体时间复杂度 $O(N\log N)$，空间复杂度 $O(N)$，适合大规模稠密图。
