# Problem F

## Description

To make the kingdom more prosperous, Pisces decides to ally with the elves living in the forest.

However, the elven elders want to test Pisces, so they give him a simple question.

Given a DAG with $n$ nodes and $m$ edges, the elven elders want to know the value of
$\sum^n_{i=1}\sum^n_{j=1}count(i,j)\cdot a_i\cdot b_j$ mod $(1e9 + 7)$, where $count(x,y)$ is defined by the number of different paths from $x$ to $y$ and $count(x,x) = 0$, and $a$, $b$ are $2$ given arrays.

It is too hard for Pisces to answer this question, so he turns to you for help.

### Input

The first line contains an integer $T$ $(1\leq T \leq 10)$, which denotes the number of test cases.

For each test case, the first line contains $2$ integers $n$ and $m$ $(1 \leq n, m \leq 10^5)$

— the number of nodes and the number of edges, respectively. Each of the next $n$ lines contains $2$ integers $a_i$ and $b_i$.

And for the next $m$ lines, each line contains $2$ integers $u$ and $v$ denoting a directed edge going from node $u$ to node $v$ $(1\leq u,v \leq n)$.

### Output

For each test case, print the answer.

### Sample Input

``` log
3
3 3
1 1
1 1
1 1
1 2
1 3
2 3
2 2
1 0
0 2
1 2
1 2
2 1
500000000 0
0 500000000
1 2
```

### Sample Output

``` log
4
4
250000014
```

### HINT

### 题目分析

问题：给定 DAG，求 `S = sum_{i,j} count(i,j) * a_i * b_j` (count(i,j) 为不同路径数，count(i,i)=0)，结果对 `1e9+7` 取模。

思路：使用链式前向星存图并记录入度，先做拓扑排序，然后从拓扑序倒序对每个节点计算 `g[u] = sum_{u->v} (b[v] + g[v])` (MOD 下计算)。最后答案为 `sum_i a[i] * g[i]`。这样每条路径贡献被线性地累计，避免枚举路径。

复杂度：O(n + m)。

要点：注意 MOD 运算与拓扑排序的正确性（若输入保证 DAG，则拓扑排序覆盖所有节点）。使用 1-based 存储时小心索引偏移。
