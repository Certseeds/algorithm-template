## Description

Given a tree whose nodes are numbered from 1 to $n$.

You are asked to print all the leaf nodes of the tree in ascending order.

The root of the tree is node 1.

### Input

The first line contains one integer $n$ $(1 \le n \le 1000000)$, indicating the number of nodes in the tree.

Then $n-1$ lines follow. Each line contains two integers $u, v$ $(1 \le u, v \le n)$ describing an edge, indicating the indices of nodes which form an edge.

### Output

One line contains integers in ascending order.

Multiple integers in one line must be separated by one space.

### Sample Input

``` log
4
1 2
1 3
3 4
```

### Sample Output

``` log
2 4
```

### HINT

## 复用信息

+ Contest 1148:CS203 2023 Fall Lab 6 Tree
+ Contest 1103:CS217 2021 Fall Lab 07 Tree
+ Contest 1104:CS203 2021 Fall Lab 07 Tree

### 算法分析

实现使用链式前向星(head + edges 数组)来表示无根树并在读入阶段构建图。

程序通过遍历每个节点的出边数来计算度数，注意图中采用了双向边存储，因此内部度数为实际度的两倍，但判断叶子时仅需判断除根以外节点的出边数是否为1。

当 n==1 时单独处理，直接输出 1 作为叶子。

最终将所有叶子结点收集后排序并按升序输出。

时间复杂度为 O(n)，空间复杂度为 O(n)。
