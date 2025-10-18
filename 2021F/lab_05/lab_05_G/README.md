# lab_05_G — Mountain Pairs (Visible Pairs)

## Description

LowbieH and his friend wtd are on their trip to the SUSTech natural park.

The place is quite mountainous and they can climb `n` mountains lying on a straight line numbered from `1` to `n`, each with height `h_i(1 <= i <= n)`.

To save time, they decide to climb two different mountains and they want to see each other when they reach the top.

That is to say, LowbieH will choose the `i_th` mountain and wtd will climb the `j_th` mountain`(1 <= i < j <= n)`.

For the `k_th(i < k < j)` moutain that is between their choices, it should satisfy that `h_k < min(h_i, h_j)`.

Thus no moutains will block cross their visions.

Also, if LowbieH and wtd are on the adjacent mountains, they can certainly see each other.

Now we define such pair of mountains `(i, j)` to be a happy pair if LowbieH and wtd can see each other on them.

Can you tell them the number of all different happy pairs within given intervals ?

## Input

The first line of input contains two integers `n, q (1 <= n, q <= 3*10^5)`, which means the number of moutains and queries.

The second line of input contains `n` integers `h_1, ..., h_n (1 <= h_i <= 10^9)`, denoting the height of each moutain.

The following `q` lines contain two integers `l, r (1 <= l <= r <= n)` in each line, which means that the interval of query is `[l, r]`.

You should calculate the number of different happy pairs within this interval.

## Output

The output will be `q` lines in total.

Each line contains the answer of each query.

## Sample Input

```log
3 2
2 1 2
1 1
1 3
```

## Sample Output

```log
0
3
```

## HINT

You are recommended to use fast I/O.

## 复用信息

+ Contest 1083:2020 Fall Lab05 Stack + Queue
+ Contest 1100:CS217 2021 Fall Lab 05 Stack + Queue

## Algorithm Analysis (实现说明)

- 思路: 使用单调栈将山峰分组，构造所有满足“可见对”(u,v) 的边，其中 `u<v` 且对于 u 和 v 之间的任意 `k, h_k < min(h_u,h_v)`。遍历从左到右，维护一个栈，每一组中只保留相同高度的连续位置作为一组：
  1) 当当前高度大于栈顶组高度时，弹出栈顶组，其组内最右位置与当前 i 构成一条可见边；
  2) 若等高，则组内最近位置与当前 i 构成一条可见边，并把 i 并入该组；
  3) 若栈顶更高，则栈顶最近位置与当前 i 构成一条可见边，并把当前值推入栈。
- 得到所有边 (u,v) 后，离线处理查询：把边按 v 升序排序，查询按 r 升序处理，用 Fenwick 树在 u 轴上统计已加入的边数。对每个查询 [l,r]，我们只需统计 u ∈ [l,r-1] 且对应 v ≤ r 的边的数量。
- 实现要点: 分两步：先用单调栈构造所有边，随后构造事件（r,+1）和（l-1,-1）并用 Fenwick 树按 x=r 增量添加边的 u 值。最后按事件顺序计算答案。
- 复杂度: 构造边 O(n)，排序边 O(n log n)，事件排序 O(q log q)，Fenwick 操作总体 O((n+q) log n)。空间 O(n+q)。
- 边界: 相邻山峰总是可见；重复高度的特殊处理保证只加入最近可见边以避免重复计数。
