## Description

There are n cities, m bidirectional roads connect to these n cities, each road has a cost.

These m roads ensure that n cities connect to each other.

Please find out the minimum cost to connect these n cities.

### Input

The first line contains two integers n, m $ (1\leq n \leq 10^5, 1\leq m \leq 5*10^5) $, indicating there are n cities and m roads.

The next m lines, each line contains three integers u, v, w $ (1\leq u, v \leq n, 1\leq w\leq 10^9) $, indicating that there is a road between u and v, cost w.

### Output

Please output the minimum cost to connect these n cities.

### Sample Input

``` log
4 4
1 2 1
2 3 1
3 4 2
1 4 8
```

### Sample Output

``` log
4
```

### 算法分析

本题要求在无向连通图中，选取若干边使所有城市连通且总花费最小，即求最小生成树（MST）。

实现采用 Kruskal 算法：

- 首先将所有边按权重升序排序。
- 用并查集维护连通性，依次选取不形成环的最小边，累计总花费。
- 当选取的边数达到 $n-1$ 时停止。

整体时间复杂度为 $O(m \log m)$，空间复杂度为 $O(n + m)$，适合 $n$ 达 $10^5$，$m$ 达 $5 \times 10^5$ 的大规模图。
