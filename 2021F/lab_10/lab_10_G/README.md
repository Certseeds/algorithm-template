## Description

There are n spies (numbered 1~n), some spies know who is spy.

There are j spies can be caught, each cost $w_i$.

Once these spy are caught, they will tell out all the spies he know.

If all the spies can be caught, please output the minimum cost, otherwise, please output the minimum No. of the spies which cannot be caught.

### Input

The first line contains an integer n $ (1\leq n \leq 100000) $, indicating there are n spies in total.

The second line contains an integer j $ (1\leq j \leq n) $, indicating there are j spies can be caught directly.

The next j lines, each line contains two integers b, w $ (1\leq b \leq n, 1\leq w \leq 1000) $, indicating catch spy_b directly need cost w.

The next line contains an integer k $ (1\leq k \leq 100000) $.

The next k lines, each line contains two integer u, v $ (1\leq u, v \leq n) $, indicating spy_u knows the information of spy_v.

### Output

If all the spies can be caught, please output YES in the first line and output the minimum cost in the second line.

If not all the spies can be caught, please output NO in the first line and output the minimum No. in the second line.

### Sample Input

``` log
3
2
1 10
2 100
2
1 3
2 3
```

### Sample Output

``` log
YES
110
```

### 算法分析

本题为有向图的最小代价全覆盖问题。

算法先用 Tarjan 算法求强连通分量（SCC），每个分量统计可直接抓捕的间谍最小代价。

对每个分量，若入度为 0 且无可抓捕间谍，则无法全覆盖，输出最小编号。

否则，将所有入度为 0 的分量的最小代价累加，得到全覆盖的最小总代价。

整体时间复杂度 $O(N+K)$，空间复杂度 $O(N+K)$，适合大规模稀疏图和分层判定。
