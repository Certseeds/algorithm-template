---
SPDX-License-Identifier: CC-BY-NC-SA-4.0
---

# lab_03_B — Median (double form)

## Description

Given an array α of length ν, output the "median in double form" defined as:

- If ν is even: return (α[ν/2 - 1] + α[ν/2])
- If ν is odd: return 2 * α[ν/2]

The array is 0-indexed in the definition above.

The result is an integer (not a floating point number): when ν is odd we return twice the middle element, when ν is even we return the sum of the two middle elements.

## Input

The first line contains an integer n (2 ≤ n ≤ 5*10^6).

The second line contains n integers (each in range [0, 2^31 - 1]).

## Output

Output a single integer: the median in the double form defined above.

## Notes

- Be careful with overflow: 2 * int32_t can overflow a 32-bit signed integer. Use 64-bit integers (e.g., `int64_t`) when computing the result.

## Analysis

该程序使用自定义的归并排序对输入数组进行排序，以便可以确定性地访问中间元素。

排序完成后，当数组长度为偶数时返回中间两个元素之和；当长度为奇数时返回中间元素的两倍，从而实现“double median”的定义。

所有计算使用 64 位整数，以避免对 32 位整数执行加倍或相加时发生溢出。

归并排序为主要耗时步骤，时间复杂度为 $O(n\log n)$，并需要 $O(n)$ 的辅助内存作为临时缓冲区。

## 复用信息

- Contest 1095:CS203 2021 Fall Lab 03 Sorting
- Contest 1096:CS217 2021 Fall Lab 03 Sorting
- Contest 1137:CS203 2023 Fall Lab 2 Sorting
- Contest 1187:CS203 2025 Fall Lab 2 Sorting
