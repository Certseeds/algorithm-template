# lab_04_E — Delete Decreasing Numbers

## Description

Given a sequence `{a[i]}` of length `n`, we define `a[i]` as a decreasing number if `a[i-1] > a[i]` (when `i-1 >= 1`) or `a[i] > a[i+1]` (when `i+1 <= n`).

Please process the given sequence by deleting the decreasing numbers in it. In each turn you should delete all the decreasing numbers in the sequence at the same time. Repeat the procedure until the sequence has no decreasing numbers.

### Input

The first line of input contains an integer `T` (1 <= `T` <= 10) which is the number of test cases.

For each test case, there are two lines. The first line contains an integer `n` (n <= 100000).

The second line contains `n` integers representing the sequence `{a[i]}` (1 <= `a[i]` <= 100000).

### Output

One line per test case representing the final result sequence.

### Sample Input

```log
2
10
1 4 4 3 2 8 9 4 5 7
5
1 8 6 2 4
```

### Sample Output

```log
1 4 7
1 4
```

## 复用信息

+ Contest 1097:CS203 2021 Fall Lab 04 LinkedList
+ Contest 1098:CS217 2021 Fall Lab 04 LinkedList
+ Contest 1141:CS203 2023 Fall Lab 3 LinkedList

## Analysis

我们把序列维护为一个用两个索引数组表示的双向链表。

所有违反非降（non-decreasing）规则的索引都会被入队，并带上它们应当被删除的轮次（以保证同一轮同时删除）。

当一个元素被删除时，我们将其左右邻居重新连接；如果连接后某个邻居变成了递减数，则把它安排在下一轮删除（入队）。

当队列为空时，我们从第一个存活的索引开始遍历双向链表，收集剩下的元素作为结果。

该算法对每个索引只做常数次处理，所以每个测试用例的时间复杂度为 O(n)，空间复杂度为 O(n)。

## Algorithm Analysis (实现说明)

+ 思路: 使用两个数组 prev/next 模拟双向链表并维护一个当前需要删除的索引队列。初始时将所有“递减数”（与左右邻居不满足非降条件的索引）加入队列。每一轮中把队列内所有索引同时标记为删除，并把每个连续删除段的左右活跃邻居桥接起来。桥接后检查受影响的左右邻居是否在下一轮成为递减数并加入下一轮队列。重复直到没有待删元素。
+ 实现要点: prev/next 用于 O(1) 删除和跳过已删除元素；用 removed 标记已删除，in_next 防止下一轮重复入队。对连续段一次性桥接能保证同时删除语义。
+ 复杂度: 每个元素最多被删除一次，且每个邻接关系只更新常数次，时间 O(n)，空间 O(n)。
+ 边界: n<=1 时直接返回原序列；所有元素相等或严格非降序时无需删除，马上终止。
