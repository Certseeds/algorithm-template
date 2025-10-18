---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_G

## Description

There are too many cables under your table, and you want to tidy them.

You designed a simple cabling scheme: There are n cables, each cable is a line in form of $y=k_i∗x+b_i$, your table is the region between $x=x1$ and $x=x2$

If any two cables intersect on your table region (not include the edges), your table is not tidy and you need to design another scheme.

More formally, there are n lines in form of $y=k_i∗x+b_i$, if there are two lines intersect on $(x_p,y_p)$, and $x1<x_p<x2$, then the scheme need be redesigned.

You want to know whether you need to redesign the scheme.

## Input

The first line contains an integer $n$ ($2 \le n \le 10^5$).

The second line contains two integers $x_1$ and $x_2$ ($-10^9 \le x_1 < x_2 \le 10^9$).

The following $n$ lines each contain two integers $k_i, b_i$ ($-10^6 \le k_i, b_i \le 10^6$) describing the lines.

All lines are pairwise distinct.

## Output

Print "YES" if the scheme must be redesigned. Otherwise print "NO".

## Analysis

该解法在 $x_1$ 和 $x_2$ 处分别计算每条直线的取值，以确定两条边界上直线的相对次序。

按在 $x_1$ 处的值对直线索引排序，遇到 $x_1$ 处相等时以 $x_2$ 的值作为次要比较键；随后检查按该顺序在 $x_2$ 处的值序列是否存在逆序对。

若存在逆序对，则说明有两条直线在两边界之间改变了相对位置，它们必然在区间 $(x_1,x_2)$ 的内部相交，因此输出 "YES"，否则输出 "NO"。

该方法由排序主导，时间复杂度为 $O(n\log n)$，并需要 $O(n)$ 空间保存边界处的计算值。

## Sample

### Sample Input

```text
2
1 3
1 0
-1 3
```

### Sample Output

```text
YES
```
