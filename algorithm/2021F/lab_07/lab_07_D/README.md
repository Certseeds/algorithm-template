## Description

Given the order of a tree's pre-order traversal and post-order traversal, you are asked to find out how many distinct binary trees fit the given traversal orders.

### Input

The first line contains one integer $T$, which denotes the number of the test cases $(1 \le T \le 10000)$.

The nodes of a binary tree are represented by capital letters, and no two distinct nodes are represented with the same letter.

In each case, the first line contains a string $S_{pre}$, denoting the access order of the pre-order traversal.

The second line contains a string $S_{post}$, denoting the access order of the post-order traversal $(|S_{pre}|, |S_{post}|\le 26)$.

### Output

Output the number of binary trees which meet the requirements.

### Sample Input

``` log
1
ABCD
DCBA
```

### Sample Output

``` log
8
```

### HINT

### 算法分析

利用先序与后序遍历信息递归划分树的子区间，预处理后序遍历中每个字符的位置以便快速定位子树范围。

递归函数对先序区间和后序区间进行匹配，逐个拆分子树并对每个子树递归求解，若某节点只有一个子树则其左右子树互换导致可行构造数翻倍。

边界情况包括空树和单节点树，均返回 1。

由于每个节点被处理一次，算法时间复杂度为 O(m)（m 为字符串长度，<=26），空间复杂度为 O(m)。
