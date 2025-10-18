## Description

There are n cities and m roads, and each road has a length.

These n cities are numbered from 1 to n.

Please find the shortest path from city_1 to city_n.

### Input

The first line contains two integers n, m $ (1\leq n, m \leq 10^5) $, indicating that there are n cities, m roads.

The next m lines, each line contains 3 integers, u, v, w $ (1\leq u, v \leq n, 1\leq w \leq 10^9) $, indicating that there is a unidirectional road from u to v, cost w.

### Output

Please output the minimum cost from city_1 to city_n in one line.

If there is not exist a road from city_1 to city_n, please output -1.

### Sample Input

``` log
3 3
1 2 2
2 3 1
1 3 1
```

### Sample Output

``` log
1
```

### 算法分析

本题要求在有向图中计算从城市 1 到城市 n 的最短路径。

实现采用 Dijkstra 算法，适用于边权为非负的稀疏图。

- 首先用链式前向星存储所有边，空间和访问效率较高。
- 用优先队列维护当前最短距离的节点，每次取出距离最小的节点进行松弛。
- 对每条边，若能更新目标节点的距离，则入队。
- 若最终无法到达城市 n，则输出 -1。

整体时间复杂度为 $O((n + m) \log n)$，空间复杂度为 $O(n + m)$，可高效处理 $n, m$ 均为 $10^5$ 级别的大图。
