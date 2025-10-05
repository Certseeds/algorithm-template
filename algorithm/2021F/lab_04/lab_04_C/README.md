---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_04_C

## Description

There are n chains, each chain has a single node with a weight value. We will connect two chains by a sequence of p operations. Each operation connects chain a to chain b by attaching the head of chain b as the tail of chain a. After all operations, for each original node i (1..n) that is currently the head of a chain and the chain has at least q nodes, print the weight of the q-th node in that chain. Output all such weights separated by spaces.

## Input

The first line contains three integers n, p, q (1 < n, p < 1e6, 0 < q < 10).
The next line contains n integers representing the initial weight of node 1..n.
Following are p lines, each with two integers a b meaning connect chain a and b (attach head of b to tail of a). It is guaranteed that a and b are both current chain heads when the operation is applied.

## Output

For each node from 1 to n, if the node is the head of a chain and that chain has at least q nodes, output the weight of the q-th node in that chain (space separated).

## Sample

### Sample Input

```text
5 3 2
1 2 3 4 5
1 3
1 4
2 5
```

### Sample Output

```text
3 5
```

## 解题思路

### 问题分析

题目要求模拟自行车链条的连接过程. 初始时, 有 `n` 个独立的链粒 (节点), 每个链粒自身构成一个长度为 1 的链条. 接下来有 `p` 次操作, 每次操作将一个链条 (以 `b` 为头) 连接到另一个链条 (以 `a` 为头) 的末尾. 操作完成后, 需要遍历所有初始的链粒, 如果某个链粒 `i` 仍然是它所在链条的头, 并且该链条的长度不小于 `q`, 那么就输出该链条中第 `q` 个节点的权重.

### 数据结构与算法

为了高效地模拟链条的连接和查询, 我们需要一种能够快速找到链条尾部以及支持节点连接的数据结构. `main.cpp` 的实现采用了 自定义链表 结合 辅助数组 的策略.

1.  节点表示:
    + 使用 `LISTNODE::ListNode` 结构体来表示每个链粒, 其中包含权重 `val` 和指向下一个节点的指针 `next`.
    + 初始时, 创建一个 `std::vector<ListNode*> nodes` 来存储 `n` 个链粒的指针, 每个链粒的 `next` 指针都为 `nullptr`.

2.  快速定位链尾:
    + 链条连接操作 `a->next = b` 需要找到链条 `a` 的尾部. 如果每次都从头遍历链条 `a` 来找尾部, 当链条很长时, 这个操作会非常耗时, 导致总体性能下降.
    + 为了优化这一点, 代码引入了一个辅助数组 `std::vector<ListNode*> to_tail`. `to_tail[i]` 存储以 `i+1` 号节点为 初始头节点 的链条的 当前尾节点指针.
    + 这样, 当需要连接链条 `a` 和 `b` 时, 可以通过 `to_tail[a-1]` 直接获得链条 `a` 的尾节点, 时间复杂度为 O(1).

3.  算法流程:
    + 初始化:
        + 读取 `n`, `p`, `q`.
        + 创建 `n` 个 `ListNode` 节点, 并读入它们的权重, 存放在 `nodes` 数组中.
        + 创建 `to_tail` 数组, 并将其初始化为与 `nodes` 相同, 因为初始时每个链条都只有一个节点, 头尾是同一个.
    + 执行连接操作:
        + 遍历 `p` 次操作. 对于每次操作 `a, b`:
        + 获取链条 `a` 的尾节点: `fir_tail = to_tail[a-1]`.
        + 获取链条 `b` 的头节点: `rih_head = nodes[b-1]`.
        + 获取链条 `b` 的尾节点: `rih_tail = to_tail[b-1]`.
        + 执行连接: `fir_tail->next = rih_head`.
        + 更新 `to_tail` 数组:
            + 链条 `a` 的新尾节点现在是原链条 `b` 的尾节点: `to_tail[a-1] = rih_tail`.
            + 链条 `b` 不再是独立的链条 (它被合并了), 所以将其在 `to_tail` 中的记录置空: `to_tail[b-1] = nullptr`. 这也巧妙地标记了节点 `b` 不再是头节点.
    + 查询与输出:
        + 遍历所有初始节点 (从 0 到 `n-1`).
        + 检查 `to_tail[i]` 是否为 `nullptr`. 如果不是, 说明节点 `i+1` 仍然是一个链条的头.
        + 从这个头节点 `nodes[i]` 开始, 向后遍历 `q-1` 步, 找到第 `q` 个节点.
        + 如果在此过程中链条没有提前结束 (即链条长度 `>= q`), 就将第 `q` 个节点的权重存入结果数组.
        + 最后, 按格式输出结果数组中的所有权重.

4.  资源管理:
    + 由于代码中使用了 `new` 来动态分配 `ListNode` 节点的内存, 因此在程序结束前, 需要一个 `destoryResource` 函数来遍历并 `delete` 所有已分配的节点, 避免内存泄漏.

### 结论

该实现通过引入一个辅助数组 `to_tail` 来记录每个链条的尾节点, 将链条连接操作的时间复杂度从 O(L) (L为链条长度) 优化到了 O(1). 最终的查询阶段是对每个作为头节点的链条进行一次遍历, 最多遍历 `q` 步. 整体算法高效, 能够处理大规模数据.

## Data Structure Restrictions

**Lab Level**: Lab 04 (Linked Lists)

**Allowed Structures Used**:
- ✅ **Custom ListNode**: Singly-linked list node structure
  ```cpp
  struct ListNode {
      int32_t val;
      ListNode *next;
      ListNode(int32_t v, ListNode *n) : val(v), next(n) {}
  };
  ```
- ✅ **std::vector**: Auxiliary arrays for `nodes` and `to_tail`
- ✅ **Pointer manipulation**: Direct node linking via pointers

**Techniques Demonstrated**:
1. **Custom linked list implementation**: Using `ListNode` structure
2. **Efficient tail tracking**: O(1) access to chain tails via auxiliary array
3. **In-place operations**: Connecting chains by pointer manipulation
4. **Memory management**: Proper allocation (`new`) and deallocation (`delete`)

**Complexity Analysis**:
- Initialization: O(n)
- Each connection: O(1) (thanks to `to_tail` optimization)
- Query phase: O(n × q) worst case
- Total: O(n + p + n×q)

**Compliance**: This solution perfectly demonstrates Lab 04 level capabilities:
- Uses custom linked list nodes (key skill for this lab)
- Performs pointer-based operations
- Optimizes with auxiliary data structures (allowed since Lab Welcome)
- Manages memory properly

Without the `to_tail` optimization, connection operations would be O(L) per operation, making the algorithm much slower. This showcases understanding of both linked lists and algorithm optimization.

See [Lab 04 Restrictions](../RESTRICTIONS.md) for full details on allowed data structures at this level.
