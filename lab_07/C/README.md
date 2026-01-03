## Description

There is a complete binary tree, and you will get the number of nodes in this tree.

You are asked to find the height of the tree.

Notice that the height of a leaf node is $1$, and the height of any other node equals the maximum height among all subtrees plus one.

And The height of a tree equals the height of the root node in the tree.

### Input

The first line contains one integer $T$ $(1 \le T \le 100000)$, which denotes the number of the test cases.

Then $T$ lines follow. Each line contains an integer $num$ $(1 \le num \le 10^{18})$, which denotes number of the nodes in this tree.

### Output

$T$ lines.

Each line contains one integer denotes the height of the tree in that case.

### Sample Input

``` log
3
3
4
5
```

### Sample Output

``` log
2
3
3
```

### HINT

### 算法分析

对于给定节点数 n 的完全二叉树，其高度等价于二进制位数，计算方法为 floor(log2(n)) + 1。

实现中将 n 右移并计数得到高度，避免使用浮点运算以提高精度和性能。

程序为每个测试用例独立计算高度，整体时间复杂度为 O(T * log n) ，但对于给定约束可视为 O(T)。
