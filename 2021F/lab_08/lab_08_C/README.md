# lab_08_C

## Description

We construct an array $C$ out of two given array $A$ and $B$ such that each element in array $C$ is the product of an element in $A$ and an element in $B$.

For example, we have $A=[1,2,1]$ and $B=[5,2]$, then $C=[5,2,10,4,5,2]$.

Now we only want to know the first $K$ smallest element of array $C$.

### Input

The first line contains three integers $N$, $M$ and $K$, denoting the length of array $A$, the length of array $B$ and $K$ smallest respectively.

$(1\leq N,M\leq 5\times 10^5),K\leq \min(5\times 10^5,N\times M)$.

The second line contains $N$ integers $A_1,A_2,\ldots,A_N(1\leq A_i\leq 10^9)$.

The third line contains $M$ integers $B_1,B_2,\ldots,B_M(1\leq B_i\leq 10^9)$.

### Output

Output $K$ integers separated by spaces in ascending order, denoting the first $K$ smallest elements in $C$.

### Sample Input

``` log
3 2 6
1 2 1
5 2
```

### Sample Output

``` log
2 2 4 5 5 10
```

### HINT

不要使用任何与堆和BST相关的STL!

## 算法分析 (zh-CN)

实现要点：
- 题目要求输出数组 C（由 A 与 B 的所有乘积构成）中前 K 个最小值。
- 做法：先对 A、B 排序，然后用自实现的最小堆维护当前最小候选对 (i, j)。初始将每个 A[i] 与 B[0] 配对入堆，依次弹出堆顶并将 (i, j+1) 入堆，直到得到 K 个最小乘积。
- 堆节点包含 (i, j, value) 并按 value 与索引稳定性比较以保证顺序一致。

时间复杂度：堆大小最多为 min(N, K)，总操作数约 O(K log min(N,K))，排序花费 O(N log N + M log M)。

空间复杂度：O(min(N,K) + N + M)。

正确性：此方法为常见“合并 K 条有序链”或“求 A×B 笛卡尔积前 K 小”的标准做法，保证按值顺序生成最小乘积且不重复缺失。

注意事项与边界：
- K ≤ N×M，注意当 K 很大时时间与内存压力；题目给限值，方案可接受。
- 使用 64 位类型存乘积以防溢出（A, B 最高 1e9，乘积可达 1e18）。
