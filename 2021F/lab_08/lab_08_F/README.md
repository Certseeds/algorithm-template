# lab_08_F

## Description

Recently Satori opened a bunny store.

Initially the store has no bunny at all.

Yet at the $i$-th day of the next $M$ days, one of the following events will occur.


1. A girl with property $A_i$ enters the store, intending to adopt a bunny.


   - If there are bunnies available, she will adopt the $j$-th bunny with the minimum value of $|A_i-B_j|$.

   - If there are multiple bunnies with the same minimum $|A_i-B_j|$, she will choose the one whose $B_j$ is the smallest.

   - Otherwise, she will wait until one bunny chooses her.

1. A bunny with property $B_i$ enters the store, willing to be adopted.



   - If there are girls waiting to adopt, it will choose the $j$-th girl with the minimum value of $|B_i-A_j|$ as its owner.

   - If there are multiple girls with the same minimum $|B_i-A_j|$, it will choose the one whose $A_j$ is the smallest.

   - Otherwise, it will stay at the store until one girl adopts it.

Each time when girl $i$ adopted a bunny $j$ successfully, Satori will earn $|A_i-B_j|$ coins.

Help Satori calculate the sum of coins she earns in total.

### Input

The first line contains a single integer $M(1\leq M\leq 3\times 10^5)$.

The next $M$ lines each follows one of the two formats below:

- `1 A_i` indicating a girl with property $A_i$ arrives $(1\leq A_i\leq 10^9)$.

- `0 B_i` indicating a bunny with property $B_i$ arrives $(1\leq B_i\leq 10^9)$.

It is guaranteed that all integers in $A$ and $B$ are distinct.

### Output

Output one single integer indicating the total money Satori earns.

### Sample Input

``` log
6
1 5
0 9
0 3
0 1
1 2
1 7
```

### Sample Output

``` log
9
```

### HINT

不要使用任何与堆和BST相关的STL!

## 算法分析 (zh-CN)

实现要点：
- 在线匹配问题：维护两个等待集合（girls 和 bunnies），到达新元素时尝试在对方集合中找到最接近的元素进行匹配，匹配规则为绝对差最小，若相同则选择属性值更小的那个。
- 代码中使用 Treap（随机化平衡二叉搜索树）实现等待集合，支持插入、删除、前驱（floor）与后继（ceiling）查询，平均时间复杂度为 O(log N)。
- 当新元素到达：在对方集合中查找 floor 与 ceiling，比较两者哪个与当前值差值更小并按规则选择，删除被匹配元素并累加收益；若没有匹配元素则将当前元素加入等待集合。

时间复杂度：每个事件平均 O(log Q)，Q 为当前等待集合大小，总体 O(M log M) 其中 M 为事件数。

空间复杂度：O(M) 以存储等待元素与 Treap 节点。

正确性：按照题目规则每次总是选择当前可行的最优匹配（局部最优），题目保证属性值互不相同，避免平局歧义。

注意事项与边界：
- 属性值互不相同，有利于查找与删除操作的唯一性。
- 使用 64 位类型统计总收益以避免溢出。
