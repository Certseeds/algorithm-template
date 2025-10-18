# lab_04_D — Minimum Weight Differences

## Description

Given a sequence `a` with `n` items, the weights of each item are `a[i]`.
We define the minimum weight difference of `a[i]` as `h[i] = min_{j>i} |a[j] - a[i]|`.

Please compute the minimum weight difference of each item.

### Input

The first line has an integer `n` (2 <= `n` <= 2×10^6).

The second line has `n` space-separated integers: `a1, a2, …, an` (1 <= `a[i]` <= 10^9).

### Output

Print space-separated integers:
`h1 h2 … h_{n-1}`.

### Sample Input

```log
5
1 2 3 4 5
```

### Sample Output

```log
1 1 1 1
```

### HINT

It can be solved in a simple and efficient way by using sorting and an auxiliary linked-list-like structure. Please note that the size of input might be really large, so use efficient input methods.

## 解题思路

### 问题分析

题目要求计算一个序列 `a` 中每个元素 `a[i]` 的 "最小权重差". 这个差值 `h[i]` 定义为在 `a[i]` 右侧的所有元素 `a[j]` (其中 `j > i`) 与 `a[i]` 的差的绝对值中的最小值. 即 `h[i] = min_{j>i} |a[j] - a[i]|`.

一个朴素的想法是对于每个 `a[i]`, 都向后遍历 `a[i+1]` 到 `a[n-1]`, 找到差值最小的那个. 这种方法的时间复杂度是 O(N^2), 对于 `N` 高达 `2*10^6` 的数据规模, 显然会超时.

我们需要一个更高效的算法. 关键在于, 对于 `a[i]`, 我们要找的 `a[j]` 是在数值上最接近 `a[i]` 的. 这启发我们从已处理过的元素集合中寻找 `a[i]` 的前驱 (小于 `a[i]` 的最大值) 和后继 (大于 `a[i]` 的最小值).

### 算法设计

`main.cpp` 中的实现采用了一个非常巧妙的策略: 从后向前遍历序列, 并使用一个能够动态维护有序集合的数据结构.

1.  遍历顺序: 从 `a[n-1]` 到 `a[0]` 倒序遍历. 当我们处理 `a[i]` 时, 我们需要的数据 `a[j]` (其中 `j > i`) 正是那些已经被我们遍历过并放入数据结构中的元素.

2.  数据结构选择: 我们需要一个数据结构, 它能够:
    + 高效地插入一个新元素.
    + 高效地查找一个给定值的前驱和后继.

    `main.cpp` 实现了一个 AVL树 (自平衡二叉搜索树).
    + 插入 (insert): AVL树的插入操作通过旋转来维持树的平衡, 时间复杂度为 O(log M), 其中 M 是树中元素的数量.
    + 查找前驱/后继 (getPreNode/getNextNode): 在平衡二叉搜索树中, 查找一个值的前驱和后继也是 O(log M) 的操作.

3.  算法流程:
    + 创建一个空的 AVL 树.
    + 从 `i = n-2` 向下遍历到 `0`. (注意, `a[n-1]` 没有右侧元素, 所以不需要计算).
    + 在处理 `a[i]` 之前, 先将 `a[i+1]` 到 `a[n-1]` 的所有元素插入到 AVL 树中.
    + 对于当前的 `a[i]`, 在 AVL 树中查找它的前驱 (`prev`) 和后继 (`next`).
    + `h[i]` 的值就是 `min(|a[i] - prev.val|, |a[i] - next.val|)`.
        + 如果前驱或后继不存在, 就只考虑存在的那一个.
    + 将计算出的 `h[i]` 存入结果数组.
    + 为了实现这个逻辑, 代码从 `a[n-1]` 开始, 每次迭代处理一个元素 `*iter`, 先将其插入树中, 然后为 `*(iter-1)` 计算最小差值.

4.  代码实现细节:
    + `cal` 函数中, 首先将序列的最后一个元素 `*data.crbegin()` 插入 AVL 树.
    + 然后使用反向迭代器 `crbegin() + 1` 开始循环, 每次迭代处理一个新的元素 `*iter`.
    + 在循环中, 先将 `*iter` 插入树中.
    + 然后调用 `tree.getPreNode(*iter)` 和 `tree.getNextNode(*iter)` 来找到前驱和后继.
    + 计算最小差值并存入 `will_return` 数组.
    + `std::unordered_set` 用于处理重复元素, 如果一个元素已经存在, 它的最小差值为0.
    + 最后, 由于结果是倒序计算的, 输出时需要再次反向遍历 `will_return` 数组.

### 结论

通过 从后向前遍历 并结合 AVL树 这种高效的动态有序集合数据结构, 该算法成功地将每次查找最小差值的时间复杂度从 O(N) 降到了 O(log N), 使得总时间复杂度为 O(N log N), 这足以在规定时间内处理大规模数据.

## 复用信息

+ Contest 1118:CS203 2022 Fall Lab 3 LinkedList
+ Contest 1119:CS217 2022 Fall Lab 3 LinkedList
+ Contest 1097:CS203 2021 Fall Lab 04 LinkedList
+ Contest 1098:CS217 2021 Fall Lab 04 LinkedList
+ Contest 1141:CS203 2023 Fall Lab 3 LinkedList
