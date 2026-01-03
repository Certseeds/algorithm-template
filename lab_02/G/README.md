# Problem G (Order 1427)

## Description

Given an array $a$ of length $n$. You need to find a subarray $a[l..r]$ with length at least $k$ that has the largest median.

A median in an array of length $x$ is the $\left\lfloor\frac{x+1}{2}\right\rfloor$-th smallest element. For example: $\mathrm{median}([1,2,3,4]) = 2$, $\mathrm{median}([3,2,1]) = 2$, $\mathrm{median}([2,1,2,1]) = 1$.

## Input

The 1st line contains two integers $n$ and $k$ ($1 \le k \le n \le 200000$). The 2nd line has $n$ integers: $a_1, a_2, \dots, a_n$. For each $a_i$ ($0 \le a_i \le 10^9$).

## Output

Output one integer $m$ — the maximum median you can get.

## Sample Input

```text
5 3
1 2 3 2 1
```

## Sample Output

```text
2
```

## Hint

The max median 2 is found from the subarray [2, 3, 2].

## Solution / 思路解析

- 思路概述：要找到长度至少为 $k$ 的子数组中能取得的最大中位数，可用二分答案（枚举候选中位数 $x$）＋判定函数的方法：判断是否存在一个长度至少为 $k$ 的子数组，其中位数不小于 $x$。对 $x$ 做二分，找到最大的可行值即为答案。
- 判定函数（代码实现要点）：把原数组元素映射为 +1（若 $a_i \ge x$）或 -1（若 $a_i < x$），计算前缀和 pref。若存在区间长度至少为 $k$，使得区间和大于 0，则说明该区间中 “不小于 $x$” 的元素严格多于“小于 $x$”的元素，从而中位数至少为 $x$。实现通过维护最小前缀值（到位置 i-k）并检查 pref[i] - min_pref > 0 来完成判定。
- 二分搜索：对答案的搜索区间可设为题面值域（代码中用 [0, 1e9]），在每步取上中位数向上取整的方式推进（`mid = lo + (hi-lo+1)>>1`），当判定函数为真时把 lo 提升到 mid，否则把 hi 下调到 mid-1，循环结束 lo 即为答案。
- 复杂度：判定函数为 O(n)，二分搜索约 O(log V)，总体 O(n log V)。空间 O(n) 用于前缀和数组。
- 边界与注意事项：
  - 要确保映射与前缀和的定义满足中位数判定的严格性（这里用 +1/-1，并用严格大于 0 判断）；对于偶数长度的中位数定义（题中定义为 floor((len+1)/2)）该映射是正确的。
  - 注意输入值域（这里在 0..1e9）和 int32 类型的安全使用；实现中用 int32_t 存储并操作前缀和（累加范围在 [-n,n] 内），安全。
