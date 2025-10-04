## Description

Given a tree $T$ whose nodes are numbered from 1 to $n$. and The root of the tree is node 1.

Define $dis(x, y)$ as the distance between node $x$ and node $y$ (i.e., the least number of edges in the path from node $x$ to node $y$).

Then define $k(w)=\sum_{v \in T} dis(w, v)$.

We call a node $w$ on tree $T$ the critical node if and only if $k(w) \le \min_{u\in T} k(u)$.

You are asked to print all the critical nodes of the subtree rooted at node $i$ for  $i \in [1,n]$.

### Input

The first line contains an integer $n$ $(1 \le n \le 200000)$, indicating the number of nodes of the tree $T$.

Then $n-1$ lines follow. Each line contains two integers $u, v$ $(1 \le u, v \le n)$ describing an edge, indicating the indexes of vertexes that connect an edge.

### Output

Output $n$ lines. On the $i^{th}$ line, output all the critical nodes of the subtree rooted at node $i$ in ascending order. Multiple integers in one line must be separated by one space.

### Sample Input

``` log
4
1 2
2 3
2 4
```

### Sample Output

``` log
2
2
3
4
```

### HINT

### 算法分析

首先使用链式前向星在读入阶段构建树并以 1 为根建立父子关系和深度信息。

计算以 1 为根的所有节点到根的距和，then 使用rerooting 计算每个节点的 k(u)=sum dis(u,v)。

使用 Euler-tour (tin/tout) 记录子树区间，并在 tin 序上构建线段树以支持区间最小值查询。

将具有相同 k 值的节点按 tin 排序，对于每個子树区间直接查询到最小 k 并在该 k 值对应的节点序列中二分获取位于区间內的节点集合。

最终每个子树的关键节点集合通过排序后输出。整体时间复杂度约为 O(n log n)，空间复杂度为 O(n)。
