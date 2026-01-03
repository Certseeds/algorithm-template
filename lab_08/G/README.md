# lab_08_G

> 这个问题实际上是中国计算机学会 (CCF) 举办的 NOIP 2018 提高组 Day 1 的第三题《赛道修建》

## Description

Given a weighted tree with $N$ nodes.

The distance of a simple path is defined as the sum of all edges in the path.

You should choose $M$ simple paths with no edge intersection between any two paths.

Two paths can intersect at nodes, but not share edges.

Now you are asked to calculate the maximum distance of the shortest path.

### Input

The first line contains two integers $N$ and $M$ $(1\leq M< N\leq 5\times 10^4)$.

The next $N-1$ lines each contain three integers $x,y,w$, denoting there is an edge with weight $w$ connecting $x$ and $y$ $(1\leq x,y\leq N, 1\leq w\leq 10^4)$.

### Output

Output one single integer, indicating the maximum distance of the shortest path.

### Sample Input

``` log
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
```

### Sample Output

``` log
31
```
