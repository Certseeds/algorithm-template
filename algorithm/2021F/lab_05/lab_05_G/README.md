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
