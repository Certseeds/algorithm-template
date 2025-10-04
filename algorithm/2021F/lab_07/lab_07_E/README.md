## Description

There is a tree with $n$ nodes and numbered from 1 to $n$, connected by $n-1$ edges.

The root of the tree is node 1.

Now Dateri is on the root node and wants to visit each node in the tree and return the root.

Also, he wants to pass each edge exactly twice and visit the leaves in a specific order.

Your task is to find whether there exists such a route satisfying Dateri's request.

### Input

The first line contains an integer $n$ $(3 \le n \le 5000)$, the number of nodes in the tree.

Then next $n - 1$ lines describe edges.

Each edge is described with two integers — indexes of nodes which it connects.

Then the next line contains $k$ integers (here $k$ is the number of leaves in the tree), which describes the order in which the leaves should be visited.

Guaranteed that each leaf node appears in this order exactly once.

### Output

If the route does not exist, output $-1$.

Otherwise, output $2n-1$ indexes of the tree, describing the route.

Multiple integers in one line must be separated by exactly one space.

### Sample Input

``` log
6
1 2
1 3
2 4
4 5
4 6
5 6 3
```

### Sample Output

``` log
1 2 4 5 4 6 4 2 1 3 1
```

### HINT

### 算法分析

在读入阶段使用链式前向星构建无向树并以 1 为根构造有根树的子节点列表。

对每个节点递归计算其子树包含的叶子数量和叶子在所给顺序中的最小/最大位置，以判定该节点的叶子在序列中是否构成连续区间。

若任一节点不满足连续区间属性，则不存在满足约束的遍历序列; 否则将每个节点的子节点按其子树最小位置排序以恢复合法访问次序。

最后使用迭代方式构建欧拉游走序列(每条边恰好被走两次)，并输出长度为 2n-1 的路径。

递归计算子树区间时需处理叶子与非叶子的差异，整体时间复杂度为 O(n log n) 主要来自子节点排序，空间复杂度为 O(n)。
