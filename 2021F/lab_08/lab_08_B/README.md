# lab_08_B

## Description

You are given a complete binary tree and each node has a distinct key value.

Now you are asked to determine whether the tree is a heap or not.

If it is a heap, you are to determine if it is a Max-heap or a Min-heap.

### Input

The first line contains $N(2\leq N\leq 10^6)$, denoting the number of nodes in the tree.

The second line contains $N$ integers $A_1,A_2,\ldots,A_N(1\leq A_i\leq 10^9)$, denoting the key value of node $i$.

It is guaranteed that no two key values are the same.

To simplify the problem, the tree is constructed as follows:

- The root of the tree is node 1.
- For each $2\leq i\leq N$, there is an edge between $i$ and $\lfloor i/2\rfloor$.

### Output

If the tree is a Max-heap, print "Max".

If the tree is a Min-heap, print "Min".

If the tree is not a heap, print "Neither" (without quotes).

### Sample Input

``` log
7
55 6 12 4 2 5 8
```

### Sample Output

``` log
Max
```

### HINT

不要使用任何与堆和BST相关的STL！

## 算法分析 (zh-CN)

实现要点：
- 题目给出数组按完全二叉树节点编号顺序存放。
- 遍历 i = 2..N，比较 a[i] 与父节点 a[i/2]：
  - 若对所有 i 均满足 a[parent] >= a[i]，则为 Max-heap；
  - 若对所有 i 均满足 a[parent] <= a[i]，则为 Min-heap；
  - 否则为 Neither。

时间复杂度：O(N)（单次线性扫描）。

空间复杂度：O(N)（存储数组）。

正确性：完全二叉树以数组表示，父子关系固定，上述判定直接对应堆定义。

边界与注意：
- N≥2；若 N=1（特殊情况），按实现可视为 Max（或按题意调整）。
