# lab_05_F — Longest Subarray with Bounded Difference

## Description

Dateri has a magic sequence and LowbieH is interested in it.

Dateri promises that if LowbieH can answer his question, then he will play fencing with LowbieH .

We denote the magic sequence by `{a_n}` and Dateri will choose a lucky number `k`.

He asks LowbieH to find length of the longest consecutive subsequence such that the absolute difference between any two number in the subsequence should not exceed `k`.

Can you help LowbieH?

## Input

The first line contains two integers `k(0 <= k <= 2*10^9)` and `n(1 <= n <= 3 * 10^6)`.

The second line contains `n` integers `a_1,...,a_n(1 <= a_i <= 2 * 10^9, 1 <= i <= n)`.

## Output

One line contains the answer, i.e. the length of the longest available consecutive subsequence.

## Sample Input

```log
3 9
5 1 3 5 8 6 6 9 10
```

## Sample Output

```log
4
```

## HINT

There are two available consecutive subsequences : `{5,8,6,6}` and `{8,6,6,9}`.

## 复用信息

+ Contest 1083:2020 Fall Lab05 Stack + Queue
+ Contest 1099:CS203 2021 Fall Lab 05 Stack + Queue
+ Contest 1100:CS217 2021 Fall Lab 05 Stack + Queue
+ Contest 1143:CS203 2023 Fall Lab 4 Stack/Queue
+ Contest 1168:CS203 2024 Fall Lab 4

## Analysis

思路: 维护一个滑动窗口, 在窗口内需要同时知道最大值与最小值, 若二者差值不超过 k 则窗口合法.

为了 O(1) 均摊获取窗口最大最小, 使用两个单调队列(deque):

1. q_max: 保存可能成为最大值的下标, 对应值严格递增弹出尾部保持递减队列.
2. q_min: 保存可能成为最小值的下标, 对应值严格递减弹出尾部保持递增队列.

右指针每前进一位, 将元素更新进入两个队列; 若当前窗口内最大值与最小值之差大于 k, 左指针收缩, 同时弹出已经离开窗口的下标.

窗口收缩直至满足条件, 此时统计窗口长度更新答案.

时间复杂度: 每个元素进出每个双端队列至多一次, O(n).

空间复杂度: 两个双端队列 O(n) 最坏, 均摊近似 O(1) 额外.

边界情况:

1. n=1 时答案为 1.
2. k=0 时寻找最长相同元素的连续段.
3. 全部单调递增且差值逐渐超过 k 时需正确收缩.
4. 数据范围大 (2*10^9) 但只做差值比较, 使用 64 位中间计算避免潜在溢出.

