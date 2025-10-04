## Description

Given a rooted tree numbered from $1$ to $n$, each edge has a weight $w$.

The root node of the tree is node $1$.

You are asked to calculate the number of paths that start from the root, terminate in a leaf node, and satisfy the sum of edge weights in the path equals to $num$.

### Input

The first line contains two integers $n$ and $num$ $(1 \le n \le 500000, 1 \le num \le 2000000000)$, indicating the number of tree nodes and the target number.

Then $n-1$ lines follow. Each line contains three integers $u, v, w$ $(1 \le u, v \le n, 1 \le w \le 100)$ describing an edge. The first two integers are the indices of nodes that form an edge and the last integer indicates the weight of the edge.

### Output

Output an integer which means how many paths satisfying the sum of edge weights in the path equals to $num$.

### Sample Input

``` log
6 6
1 2 2
1 3 3
3 4 4
3 5 3
2 6 4
```

### Sample Output

``` log
2
```

### HINT

Paths must start at root (1) and end at a leaf.

Count those whose sum of edge weights equals the target $num$.

## 复用信息

+ Contest 1125:CS217 2022 Fall Lab 6 Tree
+ Contest 1103:CS217 2021 Fall Lab 07 Tree
+ Contest 1104:CS203 2021 Fall Lab 07 Tree
+ Contest 1124:CS203 2022 Fall Lab 6 Tree
+ Contest 1148:CS203 2023 Fall Lab 6 Tree
+ Contest 1174:CS203 2024 Fall Lab 6

### 算法分析

实现使用链式前向星(head + edges 数组)来表示树并在读入阶段构建图。

随后从根节点 1 开始使用显式栈进行迭代深度优先遍历，计算每个节点到根的路径和(path-sum)。

当遍历到子节点时，将父节点的 path-sum 加上该边权重作为子节点的 path-sum，这样可以在线性时间内得到所有节点的路径和。

一个节点被判定为叶子当且仅当它在遍历时没有除父节点外的子节点；最终统计所有叶子中 path-sum 等于目标 `num` 的个数。

实现采用显式栈而非递归，以避免在 n 很大（<=5e5）时发生栈溢出。

时间复杂度为 O(n)，空间复杂度为 O(n)，其中 n 为节点数，主要开销来自前向星邻接结构及若干辅助数组。

代码遵循三段式结构(read -> solve -> write)，并使用定长整数类型保证稳定性和可移植性。

实现考虑了单节点和深链等边界情况，迭代遍历和前向星结构能稳健处理这些情形。
