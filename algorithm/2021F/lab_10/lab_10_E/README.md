## Description

Yuki is a magical girl and she has the ability to activate portals.

The country Yuki lives in has $n$ cities and $m$ roads at certain distances.

The cities are numbered from $1$ to $n$ and all the roads are unidirectional, that is a road from $u$ to $v$ cannot be passed from $v$ to $u$.

Also, there are $p$ portals in the country, each of them connects two cities unidirectional with no distance.

Since Yuki doesn't grasp magic thoroughly, she can activate at most $k$ portals.

Now Yuki is curious about what is the minimum distance between $S$ and $T$ if she activates at most $k$ portals.

### Input

The first line contains four integers: $n$, $m$, $p$ and $k$ $ (1\leq n,m,p\leq 50\ 000,0\leq k\leq10) $ --- the number of cities, roads, portals and the number of portals Yuki can activate at most.

Each of the next $m$ lines contains three integers: $u$, $v$ and $w$ $ (1 \leq u,\ v\leq n,1\leq w\leq 1\ 000\ 000) $, meaning that there is a unidirectional road from city $u$ to city $v$ at distance $w$.

Each of the next $p$ lines contains two integer: $u$ and $v$ $ (1 \leq u,\ v\leq n) $, meaning that there is an inactive portal from city $u$ to $v$.

Please note that when it is active, Yuki can only be teleported from city $u$ to $v$ unidirectionally.

The last line contains two integers: $S$ and $T$ $ (1\leq S,T\leq n) $ --- the origin and destination.

### Output

Print one line with the result --- the minimum distance between city $S$ and $T$.

It is guaranteed that Yuki can move from city $S$ to $T$ by activating at most $k$ portals.

### Sample Input

``` log
5 6 3 1
1 3 4
1 2 2
3 5 6
2 4 3
3 4 1
4 5 2
2 3
1 4
1 2
1 5
```

### Sample Output

``` log
2
```

### 算法分析

本题为分层图最短路问题，允许激活至多 $k$ 个传送门。

算法将每个城市复制 $k+1$ 层，每层表示已用传送门数量。

普通道路在同一层连边，传送门在相邻层间连边且权值为 0。

采用 Dijkstra 算法在分层图上求 $S$ 到 $T$ 的最短距离。

每次扩展节点时，判断是否可用传送门，更新对应层的距离。

整体时间复杂度 $O((k+1)N\log((k+1)N))$，空间复杂度 $O((k+1)N)$，适合稀疏图和小 $k$。
