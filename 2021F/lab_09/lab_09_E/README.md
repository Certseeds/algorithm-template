# Problem E

## Description

Today is Valentine’s day, and Pisces is going to date with the beautiful princess in the neighboring kingdom.

There are $n$ cities numbered from $1$ to $n$ on the mainland, with Pisces in city $1$ and the princess in city $n$.

There are $m$ unidirectional roads among these $n$ cities.

Usually, it takes Pisces $1$ unit of time to travel from one city to another, but due to the probable existence of thorns, rivers or even robbers, some of the roads will take $2$ units of time to travel.

In other words, the cost of traveling from one city to another is either $1$ unit or $2$ units of time.

Pisces wants to know the minimum time that he can meet the princess.

### Input

The first line contains $2$ integers $n$ $(2\le n\le 2*10^5)$ and $m$ $(1\le m\le4*10^5)$.

In each of the next $m$ lines, there are $3$ integers $u$, $v$ $(1\le u,v\le n)$ and $w$ $(1\le w\le 2)$, which means there is a road from $u$ to $v$, and it takes $w$ unit(s) of time for Pisces to go through.

### Output

Print the minimum time in one line. Or, if he cannot reach the destination, print "-1" (without quotes).

### Sample Input

``` log
4 5
1 2 1
2 4 1
2 3 2
3 4 1
1 3 1
```

### Sample Output

``` log
2
```

### HINT

### 题目分析

问题：有向图的单源最短路（权值为正），求 1 到 n 的最短距离。

思路：使用链式前向星存图，运行 Dijkstra（优先队列）。采用常见的距离数组和优先队列松弛操作，遇到目标节点可提前终止。

复杂度：O((n + m) log n)。

要点：用大常数表示 INF，优先队列可能插入多个同一顶点的距离条目，需要通过比较当前弹出项与 dist[] 过滤过期条目。

