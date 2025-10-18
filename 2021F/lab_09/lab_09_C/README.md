# Problem C

## Description

Given a graph with $n$ nodes and $m$ edges, we define cycles as paths which start from and end at the same point.

One day, a student thinks that graphs with cycles are very "bad" and graphs without cycles are really "good".

But he does not know how to distinguish them.

Can you help him?

### Input

Line 1: Two integers $n(1\le n\le 10^5)$ and $m(1\le m\le 10^5)$, which means the graph has $n$ nodes and $m$ edges.

There are $m$ lines following: Line 2~(m+1): Two integers $u$, $v$ which means there is an undirected edge between node $u$ and node $v$.

Node indices are integers in range $[1,n]$.

### Output

Print whether the given graph is bad or not. Use "Bad" to indicate that the graph is bad and "Good" otherwise.

### Sample Input

``` log
3 3
1 2
2 3
1 3
```

### Sample Output

``` log
Bad
```

### HINT

### 题目分析

问题：判断无向图是否含环（输出 "Bad"/"Good"）。

思路：使用链式前向星构建无向图（实际在内部以有向边形式存储两次），利用并查集（DSU）遍历边集检测是否存在将两个已在同一集合的顶点连接的边，从而确定存在环。

复杂度：O(n + m α(n))，其中 α 为并查集反阿克曼函数。

要点：遍历链式前向星时每条无向边出现两次，采用 u < v 的策略只处理一次以免重复。

