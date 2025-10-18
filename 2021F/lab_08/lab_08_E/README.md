# lab_08_E

## Description

Given an array of length $N$: $A_1,A_2,\ldots,A_N$.

For every $1\leq i\leq N$, you are asked to figure out the median of $A_1,A_2,\ldots,A_i$.

The median of $A_1,A_2,\ldots,A_i$ is defined as the $\lceil i/2\rceil$-th element of the multiset after it is sorted.

### Input

The first line contains one integer $N(1\leq N\leq 5\times 10^5)$.

The second line contains $N$ integers $A_1,A_2,\ldots,A_N(1\leq A_i\leq 10^9)$.

### Output

Output $N$ integers in a single line separated by spaces, the $i$-th of which represents the median of $A_1,A_2,\ldots,A_i$.

### Sample Input

``` log
5
2 5 1 4 7
```

### Sample Output

``` log
2 2 2 2 4
```

### HINT

不要使用任何与堆和BST相关的STL!

## 算法分析 (zh-CN)

实现要点：
- 使用两个自实现的堆：大顶堆（lower）保存较小的一半元素，小顶堆（upper）保存较大的一半元素。
- 每次插入新元素时先插入合适的堆，然后调整两堆大小以保证 lower.size() >= upper.size() 且两堆大小差不超过 1。
- 当前前缀的中位数即为 lower.top()，因为题目要求的是第 ceil(i/2) 个元素。

时间复杂度：每次插入为 O(log N)，总体 O(N log N)。

空间复杂度：O(N)。

正确性：通过维持两堆的大小与分界，lower.top() 始终为前缀集合中第 ceil(i/2) 个元素，满足定义。

注意事项与边界：
- 实现中使用自定义堆以避免 STL 的堆/BST 依赖。
- 注意在平衡步骤中正确移动堆顶元素以维持不变式。
