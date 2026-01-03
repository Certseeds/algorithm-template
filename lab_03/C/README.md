---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_C

## Description

Given an unsorted sequence, sort it using insertion sort and selection sort respectively.

Compare which algorithm performs fewer operations.

We count both "swap two numbers" and "compare two numbers" as one operation each.

The algorithm with fewer total operations is considered better.

It is guaranteed that the number of operations differs between the two algorithms for all test cases.

## Input

The first line contains an integer $T$ ($1 \le T \le 10$), the number of test cases.

For each test case the first line contains an integer $n$ ($2 \le n \le 10^3$), followed by $n$ integers.

## Output

For each test case, output two lines. The first line is the sorted array in ascending order.

The second line is the winner message.

Print "Insertion Sort wins!" if insertion sort uses fewer operations.

Otherwise print "Selection Sort wins!".

## Analysis

实现通过分别模拟插入排序和选择排序的操作计数来比较两者的开销。

插入排序在每次将当前元素向前移动时，对每次比较计数一次；当发生相邻元素交换时再计数一次交换操作。

选择排序在每次扫描后缀寻找最小值时，对每次比较计数一次；若找到的最小值需要与当前位置交换，则计数一次交换操作。

在得到两者的操作计数后，程序用 `std::sort` 对序列进行排序以打印最终结果，并根据计数比较决定胜者。

两种计数例程的最坏情况时间复杂度均为 $O(n^2)$，额外空间开销仅为对输入序列的临时拷贝（$O(n)$）。

## Sample

### Sample Input

```text
2
3 1 3 2
3 3 2 1
```

### Sample Output

```text
1 2 3
Insertion Sort wins!
1 2 3
Selection Sort wins!
```
