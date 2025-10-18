# lab_08_D

## Description

Given $N$ integers, you are required to merge them into one single integer using $N-1$ operations.

During each operation, you can choose two integers $x$ and $y$ and replace the two integers with one single integer $x+y$ which costs $x+y$ power.

Now you wonder the minimum sum of power possible to complete the mission.

### Input

The first line contains one integer $N(1\leq N\leq 5\times 10^5)$.

The second line contains $N$ integers $A_1,A_2,\ldots,A_N(1\leq A_i\leq 10^7)$, denoting the $N$ integers you are required to merge.

### Output

Output one single integer indicating the minimum power to complete the mission.

### Sample Input

``` log
4
5 1 9 2
```

### Sample Output

``` log
28
```

### HINT

不要使用任何与堆和BST相关的STL!

## 算法分析 (zh-CN)

实现要点：
- 该题为经典的最优合并（Huffman）问题。每次从集合中选择两个最小的数 x 和 y，将它们合并为 x+y，代价为 x+y，将合并结果重新加入集合。
- 由于题目要求不使用 STL 的堆或 BST，代码中实现了一个最小堆（MinHeap），支持 push/top/pop 操作并在堆上反复执行合并操作。

时间复杂度：构建堆为 O(N)，每次合并进行两次出堆和一次入堆，单次为 O(log N)，共 N-1 次合并，总体 O(N log N)。

空间复杂度：O(N) 用于堆与输入数组。

正确性：贪心地每次合并当前最小的两个数可以最小化总体代价，这是 Huffman 或最优合并树的经典证明。

注意事项与边界：
- 当 N=1 时，代价为 0，应特殊处理。
- 元素值与累加和可能较大，使用 64 位整型累加以防溢出。
