# lab02-e

> cid: 1094, pid: 4

## Description

Given two nondecreasing sequences $a$ and $b$, and their length are both $n$.

What's the median after combining the subarray $a[l..r]$ and subarray $b[l..r]$?

Subarray $a[l..r]$ is a sub-array of $a$, it includes $a_l, a_{l+1}, \dots, a_r$ for $1\le l\le r\le n$, its length is $r-l+1$.

You'd like to determine the median of this set of $2k$ (where $k=r-l+1$) values, which we define here to be the $k$-th smallest value.

For example: median([1,2,3,4]) = 2.

### Input

The first line contains two positive integers $n$ ($1\le n \le 100000$) and $T$ ($1\le T \le 100000$) which is the number of testcases.

The second line contains $n$ integers: $a_1, a_2, \dots, a_n$. For each $a_i$ ($0\le a_i \le 10^9$).

The third line contains $n$ integers: $b_1, b_2, \dots, b_n$. For each $b_i$ ($0\le b_i \le 10^9$).

Then $T$ lines follow. Each line contains two integers $l$ and $r$ ($1\le l \le r \le n$) for a test case.

### Output

Output $T$ lines. Each line contains an integer $ans$, the median after combining the subarray $a[l..r]$ and subarray $b[l..r]$.

### Sample Input

``` log
5 2
1 3 5 7 9
2 3 4 5 6
5 5
1 5
```

### Sample Output

``` log
6
4
```

### HINT

The corresponding solutions to the sample are:

1) For query $(5,5)$: $a_5=9$, $b_5=6$, after combining is [9,6], the median is 6.

2) For query $(1,5)$: Combine $a$ and $b$ then sort it -> [1,2,3,3,4,5,5,6,7,9], the median (5th smallest) is 4.

## 复用信息

Contest 1093:CS203 2021 Fall Lab 02 Complexity + Binary Search
Contest 1094:CS217 2021 Fall Lab 02 Complexity + Binary Search
Contest 1162:CS203 2024 Fall Lab 1

## Algorithm Analysis (实现说明)

- 思路: 对于每个查询 [l,r]，需要找到合并后长度为 2k 的数组的第 k 小元素。由于两个子数组 a[l..r] 和 b[l..r] 的长度相等（均为 k），可以使用二分在取自 a 的元素个数 i 的范围 [0,k] 上搜索。对于某个 i，令 j=k-i，检查 a[aL+i-1] 与 b[bL+j-1] 的相对大小关系，调整二分边界直至找到满足划分的 i。返回两边边界的较大值即为第 k 小。
- 实现要点: 主函数将输入转换为 0-based 索引, 对每个查询调用 kth_equal_len(aL,bL,k)。该函数对 i 做二分搜索，并在边界条件（i==0 或 j==0）处理访问。
- 复杂度: 每次查询时间复杂度为 O(log k)，总时间 O(T log n)。预处理/空间为 O(n)。
- 边界情况: k=1 时直接比较两个元素；数组中存在重复值也能处理；所有索引访问都作好边界检查以避免越界。
