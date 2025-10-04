# lab_04_F — String Operations (Insert / Find / Transform)

> Time Limit: 2 Sec Memory Limit: 128 MB

## Description

 Given a string S and three operators:

+ Insert(ch, p), inserting the char ch to position p.
+ Find(p), finding the char at position p and print it to screen.
+ Transform(l,r), transforming the characters from position l to position r (including l, r) (we define transforming as for each character c in l to r we apply ('a' + 'z' - c) to transform it)


## Input

The first line has a string S

The second line has an integer n, which is the number of operations.

The next n lines are one operation per line.

For each presentation, we use 1 for Insert , 2 for Find, 3 for Transform. (len(S) <= 2000000, n <= 100000)

## Output

Follow the output definition of each operation.

### Sample Input

```log
madamimadam
5
1 b 1
1 b 2
2 3
3 1 3
2 2
```

### Sample Output

```log
m
y
```

### HINT

You are likely to encounter TLE in this question, which is normal.

Use a more efficient linked-list or balanced data structure (for example, a well-implemented rope, splay, or a custom linked structure) to meet time limits.

## 解题思路

### 问题分析

本题要求对一个字符串进行三种操作:
1.  Insert(ch, p): 在位置 `p` 插入字符 `ch`.
2.  Find(p): 查找并输出位置 `p` 的字符.
3.  Transform(l, r): 对 `[l, r]` 区间内的所有字符 `c` 应用转换规则 `'a' + 'z' - c`.

字符串的长度和操作次数都很大, 这意味着我们需要一个能够高效处理这些操作的数据结构. 简单的 `std::string` 或 `std::vector<char>` 在 `Insert` 操作上效率低下 (O(N)), 会导致超时.

### 数据结构选择: Implicit Treap (无旋Treap)

`main.cpp` 的实现采用了一种高级数据结构——Implicit Treap (无旋Treap或分裂合并Treap). 这种数据结构非常适合处理序列上的区间操作.

+ Implicit (隐式): 节点的顺序由其在树中的中序遍历位置决定, 而不是由键值决定. 这使得它能像数组一样通过索引访问元素.
+ Treap: 每个节点除了有值之外, 还有一个随机生成的 优先级 (priority). 整个数据结构同时满足 二叉搜索树 (BST) 的性质 (按中序遍历位置) 和 堆 的性质 (按优先级). 这两个性质共同保证了树的期望高度为 O(log N), 从而确保了操作的高效性.

#### 核心操作: `split` 和 `merge`

Implicit Treap 的所有操作都基于两个基本原子操作:
1.  `split(T, k, &L, &R)`: 将树 `T` 分裂成两棵树 `L` 和 `R`. `L` 包含原树中序遍历的前 `k` 个节点, `R` 包含剩下的节点.
2.  `merge(L, R)`: 将树 `L` 和树 `R` 合并成一棵新树, 前提是 `L` 中的所有节点在中序遍历中都位于 `R` 的所有节点之前.

这两个操作的时间复杂度都与树的高度成正比, 即 O(log N).

### 算法实现

1.  节点 (Node):
    + `ch`: 存储字符.
    + `prio`: 随机优先级.
    + `sz`: 以该节点为根的子树的大小 (包括自身). 这是实现按位置分裂的关键.
    + `flip`: 懒惰标记 (Lazy Tag). 用于 `Transform` 操作. 当 `flip` 为 `true` 时, 表示该节点及其子树需要进行字符翻转.
    + `l`, `r`: 左右子节点指针.

2.  操作实现:
    + `Insert(ch, p)`:
        1.  使用 `split` 将树分裂成两部分: `[1, p-1]` 和 `[p, end]`.
        2.  创建一个新节点 `M` 来存储字符 `ch`.
        3.  使用 `merge` 将三部分重新组合: `merge(merge(L, M), R)`.
    + `Find(p)`:
        + 这是一个标准的在二叉搜索树中查找第 `k` 大元素的操作. 从根节点开始, 比较 `p` 和左子树的大小 `size(t->l)`, 决定向左走还是向右走, 直到找到目标节点. 时间复杂度 O(log N).
    + `Transform(l, r)`:
        1.  使用 `split` 将树分解成三部分: `A = [1, l-1]`, `B = [l, r]`, `C = [r+1, end]`.
        2.  对中间部分 `B` 的根节点应用懒惰标记: `apply_inv(B)`. 这个函数会翻转根节点的 `flip` 标志, 并更新其字符.
        3.  懒惰传播 (Push Down): `apply_inv` 只修改根节点. 当我们后续需要访问子节点时 (例如在 `split` 或 `merge` 过程中), `push` 函数会被调用, 将父节点的 `flip` 标记下推给子节点, 并清空父节点的标记. 这确保了标记最终能应用到所有相关节点, 同时避免了一次性更新整个区间的巨大开销.
        4.  将三部分重新合并: `merge(A, merge(B, C))`.

3.  构建与内存管理:
    + `build_from_string`: 为了高效地从初始字符串构建 Treap, 代码使用了一种 O(N) 的建树算法, 该算法利用单调栈来模拟笛卡尔树的构建过程.
    + 内存池: 为了避免频繁的 `new` 和 `delete` 带来的开销和内存碎片, 代码使用了一个 `std::vector<Node>` 作为内存池 (`node_pool`), 通过一个指针 `pool_ptr` 进行快速分配.

### 结论

通过使用 Implicit Treap 这种强大的数据结构, `main.cpp` 将所有操作的时间复杂度都优化到了 O(log N) (期望), 从而能够轻松应对本题的数据规模. 懒惰标记的应用是高效处理区间更新的关键.
