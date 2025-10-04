# Problem A

## Description

Long time ago, there was a handsome prince named Pisces, who ruled a powerful kingdom.

In his kingdom, there were $n$ cities along with $m$ directed roads connecting them.

To better govern his kingdom, Pisces had decided to draw an adjacent matrix to represent the circulation relationship among these cities.

In his matrix, if there are $a_{ij}$ roads from city $i$ to city $j$, we have $A[i][j] = a_{ij}$.

Please help him solve this problem.

### Input

The first line contains an integer $T$ $(1\leq T\leq 10)$, which denotes the number of test cases.

In each test case, the first line contains $2$ integers $n$ $(2\leq n\leq 1000)$ and $m$ $(1\leq m\leq 2000)$, indicating the number of cities and the number of roads.

And in each of the next $m$ lines, there are $2$ integers $u$ and $v$ $(1\leq u,v\leq n)$, representing that there is a directed road from city $u$ to city $v$.

### Output

For each test case, print the adjacent matrix.

### Sample Input

``` log
2
4 6
1 2
2 3
3 4
2 3
4 2
1 4
3 4
1 2
3 2
1 3
3 1
```

### Sample Output

``` log
0 1 0 1
0 0 2 0
0 0 0 1
0 1 0 0
0 1 1
0 0 0
1 1 0
```

### 题目分析

问题：给定有向图，将链式前向星表示转换为邻接矩阵输出。

思路：遍历 graph::Graph 的 head/edges 链表，将每条出边累加到矩阵对应单元。注意 graph 中为 1-based 编号，在构造矩阵时将索引减一。

复杂度：O(n + m) 构造，加上 O(n^2) 输出矩阵。

要点：遍历链式前向星时每条边访问一次，避免重复存储边列表。
