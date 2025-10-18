# lab_04_G — Sum of Products of Largest and k-th Largest in Subarrays

> Time Limit: 2 Sec  Memory Limit: 128 MB

## Description

Given a sequence $\{a_i\}$ of length `n` where the sequence is a permutation of `[1..n]`.

Define

$$
f(l,r,k)=
\begin{cases}
\text{the product of the largest and the $k$-th largest element in }\{a_l,\dots,a_r\}, & \text{if } r-l+1\ge k,\\
0, & \text{if } r-l+1<k.
\end{cases}
$$

Given `k`, compute

$\sum_{l=1}^{n}\sum_{r=l}^{n} f(l,r,k) \bmod (10^9+7)$.

## Input

The first line contains an integer `T` (1 <= T <= 10), the number of test cases.

For each test case, the first line contains two integers `n` and `k` (1 <= n <= 100000, 1 <= k <= min(80, n)).

The second line contains `n` integers describing the sequence `a_i` (each `a_i` <= 1000000).

## Output

For each test case, output a single integer: the answer modulo `10^9+7`.

### Sample Input

```log
1 5 2 1 2 3 4 5
```

### Sample Output

```log
130
```

> 我感觉这已经和链表没有任何关系了, 纯小众变态题目

## 解题思路

### 问题分析

本题要求对一个给定的排列, 计算所有子数组中最大元素与第 `k` 大元素的乘积之和. 由于子数组数量是 O(N^2), 对每个子数组都进行查找是不可行的. 因此, 需要转换思路, 从每个元素的贡献角度来计算总和.

### 核心思想: 贡献法

我们不枚举子数组, 而是枚举每个元素 `v` (从 `n` 到 `1`), 并计算它在两种情况下的贡献:
1.  当 `v` 作为子数组的 第 `k` 大 元素时.
2.  当 `v` 作为子数组的 最大 元素时.

由于题目要求的是最大值和第 `k` 大值的乘积, 直接计算一个元素作为第 `k` 大, 同时另一个元素作为最大的情况比较复杂. `main.cpp` 采用了一种更精妙的贡献法: 枚举每个值 `v` 作为第 `k` 大的场景, 同时确定该场景下的最大值, 并计算这样的子数组有多少个.

### 算法流程 (从大到小枚举)

代码实现采用从 `n` 到 `1` 的顺序遍历值 `v`. 当我们处理值 `v` 时, 所有比 `v` 大的值的位置都已经被记录下来.

1.  预处理:
    +   因为输入是 `1` 到 `n` 的排列, 我们可以创建一个 `pos` 数组, `pos[v]` 存储值 `v` 在原数组中的位置 (1-based index). 这使得我们可以 O(1) 地通过值找到其位置.

2.  数据结构:
    +   为了高效地找到一个位置 `p` 左右两边那些 值更大 的元素的位置, 代码使用了一个 `std::vector<uint64_t>` 作为 位图 (bitset). 这个位图标记了哪些位置上的元素已经被处理过 (即值比当前 `v` 大).

3.  主循环 (v 从 n 到 1):
    +   对于当前值 `v`, 通过 `pos[v]` 找到其位置 `p`.
    +   查找邻居: 在位图中, 查找位置 `p` 左侧和右侧最近的 `k` 个 "已激活" 的位置. 这些位置上的值都比 `v` 大.
        +   `Lpos` 数组存储左侧的 `k` 个邻居位置.
        +   `Rpos` 数组存储右侧的 `k` 个邻居位置.
        +   为了加速查找, 代码使用了 `__builtin_clzll` (前导零计数) 和 `__builtin_ctzll` (末尾零计数) 这类位操作内建函数, 可以在 O(1) 时间内在 `uint64_t` 中找到最高/最低的置位, 从而快速定位到位图中的下一个邻居.
    +   组合计数:
        +   现在我们考虑以 `v` (在位置 `p`) 作为第 `k` 大元素的子数组. 这样的子数组必须包含 `v` 以及 `k-1` 个比 `v` 大的元素.
        +   这 `k-1` 个较大的元素可以从 `p` 的左侧和右侧邻居中选取. 假设我们从左侧选 `u` 个, 从右侧选 `t` 个, 其中 `u + t = k - 1`.
        +   对于一个固定的 `(u, t)` 组合, 子数组的左端点可以在 `Lpos[u+1]` 和 `Lpos[u]` 之间选择, 右端点可以在 `Rpos[t]` 和 `Rpos[t+1]` 之间选择. ( `Lpos[0]` 和 `Rpos[0]` 都是 `p`).
        +   这样就可以计算出满足条件的子数组数量: `ways = (Lpos[u] - Lpos[u+1]) * (Rpos[t+1] - Rpos[t])`.
    +   计算贡献:
        +   对于上述 `ways` 个子数组, 第 `k` 大的元素是 `v`.
        +   最大元素是 `v` 和它左右 `k-1` 个邻居中的最大值. 代码通过预计算邻居值的前缀最大值 (`maxLeft`, `maxRight`) 来快速得到 `mval = max(maxLeft[u], maxRight[t])`.
        +   将贡献 `v * mval * ways` 累加到总和 `acc` 中.
    +   更新位图: 将位置 `p` 在位图中标记为已激活.

4.  k=1 的特殊情况:
    +   当 `k=1` 时, 问题退化为计算 `sum(max(sub_array)^2)`.
    +   这是一个经典问题, 可以用 单调栈 在 O(N) 时间内解决. 对每个元素 `a[i]`, 找到它作为最大值的区间范围 (即左边第一个比它大的 `NL[i]` 和右边第一个比它大的 `NR[i]`). 那么 `a[i]` 作为最大值的子数组共有 `(i - NL[i]) * (NR[i] - i)` 个.

### 结论

该算法通过贡献法, 将问题转化为一个精巧的组合计数问题. 利用从大到小的值序遍历, 并结合位图和位运算技巧高效查找邻居, 使得在处理每个值 `v` 时, 只需要 O(k) 的时间来计算其贡献. 总体时间复杂度为 O(N*k), 远优于朴素算法, 能够通过本题的数据范围.
