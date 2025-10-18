## Description

There are n cities and m roads, each road is unidirectional.

Sinzo wants to build some roads, to make each city can reach other cities.

Please tell how many roads should Sinzo construct at least?

### Input

The first line contains two integers, n, m $ (1\leq n, m\leq 10^5) $, indicating the number of cities and the number of roads.

The next m lines, each line contains two integers u, v, indicating there is a unidirectional road from u to v.

### Output

Please output the number of roads to construct in one line.

### Sample Input

``` log
4 4
1 2
2 3
3 1
3 4
```

### Sample Output

``` log
1
```

### 算法分析

本题要求最少添加多少边使有向图强连通。

算法采用 Tarjan 算法求强连通分量（SCC），并统计每个分量的入度和出度。

若分量入度为 0，需有边指向该分量；出度为 0，需有边从该分量指向其他分量。

答案为入度为 0 和出度为 0 的分量数的最大值。

整体时间复杂度 $O(N+M)$，空间复杂度 $O(N+M)$，适合大规模稀疏图。
