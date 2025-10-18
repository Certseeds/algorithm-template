---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_04_B

## Description

Given a group of n students arranged in a line under the edict that while the line has students, repeatedly execute the i-th student for i = 1..len stepping by m (i.e. every m-th student is removed). Produce the going-out order of students (a standard Josephus elimination order).

## Input

Two numbers n, m (1 < m <= 10, m <= n < 2e6)

## Output

The going-out order of students (space separated indices).

## Sample

### Sample Input

```text
5 2
```

### Sample Output

```text
1 3 5 2 4
```

## Notes

This is a classic Josephus problem. For large n you should use a linked-list/simulation with efficient removal or use a data structure like an order-statistics tree to get O(n log n) or better.

## cn-翻译

甲 个学生排成一排
按下列算法踢人
一直 开 行列有人 小
    赋 行列之长 于 冷
    赋 一 于 爱
    一直 开 爱 不大于 冷 毕
        踢出 队列 之 爱
        爱 自增 MU

## 样例

输入:`5 2`
输出:`1 3 5 2 4`

### 分析:

```
NU=5,MU=2
1 <= 2 <= 10
2 <= 5 <= 2000000
```

首先排列 `1 2 3 4 5`
第一轮踢掉`1,3,5` 留下`2,4`
第二轮踢掉`2` 留下`4`
第三轮踢掉`4`

## 解题思路

### 问题分析

本题是经典的 约瑟夫问题 (Josephus Problem) 的变种. `n` 个学生排成一队, 从第 1 个学生开始, 每隔 `m` 个位置就淘汰一人, 直到所有人都被淘汰. 要求输出学生被淘汰的顺序.

与传统的环形约瑟夫问题不同, 这里的学生是 线性排列 的. 每次淘汰操作会使队列的长度动态缩短, 并且计数始终从当前队列的头部重新开始.

例如, 初始队列为 `[1, 2, 3, 4, 5]`, `m = 2`.

1. 第一轮淘汰:
    + 淘汰第 1 个: `[2, 3, 4, 5]`, 淘汰顺序: `[1]`
    + 淘汰第 1 + 2 = 3 个 (在原队列中的位置): `[2, 4, 5]`, 淘汰顺序: `[1, 3]`
    + 淘汰第 1 + 2 + 2 = 5 个 (在原队列中的位置): `[2, 4]`, 淘汰顺序: `[1, 3, 5]`
2. 第二轮淘汰 (队列重置为 `[2, 4]`):
    + 淘汰第 1 个: `[4]`, 淘汰顺序: `[1, 3, 5, 2]`
3. 第三轮淘汰 (队列重置为 `[4]`):
    + 淘汰第 1 个: `[]`, 淘汰顺序: `[1, 3, 5, 2, 4]`

### 数据结构与算法

为了模拟这个过程, 我们需要一个能够高效执行 "按位置删除" 操作的数据结构.

#### 1. `std::vector` (朴素方法)

最直观的方法是使用 `std::vector` 来存储学生队列. 每次淘汰一个学生, 就从 `vector` 中删除对应位置的元素.

+ 优点: 实现简单直观.
+ 缺点: `std::vector` 的删除操作 (`erase`) 时间复杂度为 O(N), 因为需要移动被删除元素之后的所有元素. 在本题中, 每次淘汰都需要进行一次 `erase`, 总共进行 `n` 次淘汰. 每一轮淘汰中可能包含多次删除. 总体时间复杂度会非常高, 远超 O(N^2), 对于 `n` 达到 `2e6` 的规模会超时.

#### 2. `std::list` 或自定义链表 (优化方法)

`main.cpp` 中的实现采用了自定义的单向链表 (`LISTNODE::ListNode`). 链表是解决此类问题的理想选择, 因为它的删除操作非常高效.

+ 优点:
    + 高效删除: 只要有指向待删除节点前一个节点的指针, 删除操作的时间复杂度就是 O(1).
    + 模拟直观: 链表的结构天然适合模拟队列中元素的移除.

+ 算法流程:
    1. 构建链表: 创建一个包含 `n` 个节点的链表, 节点值从 1 到 `n`.
    2. 模拟淘汰:
        + 使用一个 `while` 循环, 条件是链表不为空 (`stable.next != nullptr`).
        + 在每一轮淘汰中, 使用两个指针: `pre` 指向当前节点的前一个节点, `now` 指向当前节点.
        + 从链表头开始, 步进 `m` 次来找到要淘汰的节点.
        + 找到后, 将该节点的值存入结果数组, 然后通过 `pre->next = now->next` 来 "跳过" `now` 节点, 实现删除.
        + 释放被删除节点的内存 (`delete now`).
        + 这个过程在每一轮中重复, 直到当前轮次无法再步进 `m` 次.
        + 然后外层 `while` 循环继续, 开始新一轮的淘汰, 直到链表为空.

#### 3. 特殊情况处理 (`m = 1`)

代码中对 `m = 1` 的情况做了特殊处理. 如果 `m = 1`, 意味着每次都淘汰第一个人, 所以淘汰顺序就是 `1, 2, 3, ..., n`. 这种情况可以直接生成结果, 避免了复杂的模拟, 提高了效率.

### 结论

实现采用 模拟法, 并通过 自定义链表 优化了删除操作的效率, 从而将整体时间复杂度控制在可接受范围内
