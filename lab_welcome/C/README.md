# Problem C (Order 1416)

## Description

Suppose in CS203, the number system only has three values 2,3,6. It holds 2<3<6.

Given an integer $n$, please find the $n$-th smallest number in CS203 number system.

## Input

The 1st line contains an integer $T$ ($1 \leq T \leq 10^3$), the number of test cases.

Each of the next $T$ lines contains an integer $n$ ($1 \leq n \leq 10^9$).

## Output

For each test case, print a line, represent the $n$-the smallest number in CS203 number system.

## Sample Input

``` log
2 1 6
```

## Sample Output

``` log
2 26
```

## 实现分析

- 实现要点: 在 `main.cpp` 中使用基数为 3 的表示, 将序号 n 转换为由字符 {'2','3','6'} 组成的字符串. 实现通过预先计算每位的容量 (CIRCLE_NUMBERS), 然后对给定的序号按 (n-1) % 3 的方式迭代得到每一位, 从最低位到最高位拼接字符.
- 复杂度: 每个查询的时间复杂度为 O(L), 其中 L 是结果字符串的位数 (约为 log_3(n)), 空间复杂度 O(1). 预计算的大小 (max_circle) 足以覆盖题目范围.
- 注意事项: 实现使用 32/64 位整数进行计数和索引, 避免使用会产生溢出的计算; 对单个测试用例多次查询时, 主函数会按序读取并逐个处理.
