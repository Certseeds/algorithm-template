# lab_08_A

## Description

You're required to devise a data structure as follows.

It is a complete binary tree.

The key of each node is larger than its children's (if it has any).

We call it Heap.

Initially your heap is empty.

Then you are asked to insert $N$ distinct integers into the heap one by one.

When you insert a new element into the heap, you should:

- Place it at the leftmost position of the complete binary tree.
- Swap it with its father if it is larger than the key of its father until it becomes the root of the heap or it is smaller than the key of its father.

Now little HEAP wants to know the number of swapping times in each insertion.

### Input

The first line contains a single integer $N(1\leq N\leq 3\times 10^5)$.

The second line contains $N$ integers $A_1,A_2,\ldots,A_N(1\leq A_i\leq 10^9)$, denoting the integers you are going to insert in order.

It is guaranteed that these integers are distinct.

### Output

Output $N$ integers separated by spaces, representing the number of swapping times in each insertion.

### Sample Input

``` log
7
5 4 8 6 2 12 55
```

### Sample Output

``` log
0 0 1 1 0 2 2
```

### HINT

## 算法分析 (zh-CN)

实现要点：
- 采用 1-based 的数组表示完全二叉堆。每次插入时，将新元素放在数组末尾，然后执行上浮（sift-up）：当当前结点比父结点大时，交换并将位置移动到父结点，直到不需要交换为止。
- 在上浮过程中计数交换次数，并记录每次插入的交换次数输出。

时间复杂度：每次插入的上浮次数最多为 O(log N)，因此总体复杂度为 O(N log N)。

空间复杂度：O(N) 用于保存堆数组与输入数组。

正确性说明：完全二叉堆的插入操作即为将元素追加到最后再上浮，算法直接模拟该过程，交换计数即为上浮的步数，满足题意。

注意事项与边界：输入保证 N≥1 且元素互不相同；代码采用 int64 存储元素以防边界值。
