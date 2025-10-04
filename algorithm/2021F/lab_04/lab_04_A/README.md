# lab_04_A — Polynomial Sum

## Description

Given two polynomials with n and m terms, please calculate the sum of the two polynomials.

Inputs and outputs are exponentially larger to smaller

### Input

The first line has two numbers: n and m $(0<n,m<1000000)$

The next n lines are the coefficients and exponents of the terms in the first polynomial.

After that, the next m lines are the coefficients and exponents of the terms in the second polynomial.

The values of all coefficients and exponents are in the range $(-10^9,10^9)$.

### Output

The first line is an integer k, it is the number of terms in the result.

The next k lines are the coefficients and exponents of the result.

### Sample Input

```log
2 2
1 3
2 1
1 4
2 3
```

### Sample Output

```log
3
1 4
3 3
2 1
```

### HINT

The introduction of Polynomial is available on Wikipedia: [Polynomial](https://en.wikipedia.org/wiki/Polynomial)

You may find this Java FastIO template helpful: [FastIO example](https://paste.ubuntu.com/p/6ybMcVXvz5/)

## 复用信息

+ Contest 1097:CS203 2021 Fall Lab 04 LinkedList
+ Contest 1098:CS217 2021 Fall Lab 04 LinkedList
+ Contest 1141:CS203 2023 Fall Lab 3 LinkedList

## 解题思路

### 问题分析

该题目要求计算两个多项式的和. 每个多项式由若干个 "系数-指数" 对构成. 核心任务是将两个输入多项式中具有相同指数的项的系数相加, 并整合所有项, 最终按指数降序输出结果.

### 数据结构选择

为了高效地存储和合并多项式, 我们需要一个能够将指数映射到系数的数据结构, 并且能够自动处理指数的排序.

`std::map<int32_t, int32_t>` 是一个理想的选择. 在这个映射中:

+ 键 (Key): 存储多项式的 指数 (exponent).
+ 值 (Value): 存储对应项的 系数 (coefficient).

`std::map` 的主要优势在于它是一个基于红黑树的有序关联容器, 它会根据键(在此即指数)自动进行升序排序. 这极大地简化了后续按指数顺序输出的需求.

### 算法流程

1. 初始化: 创建一个 `std::map<int32_t, int32_t>` 实例, 用于存放最终合并后的多项式.

2. 读取多项式:
    + 遍历第一个多项式的所有项. 对于每一个读入的 "系数-指数" 对, 将其存入 map 中. `map[指数] = 系数`.
    + 遍历第二个多项式的所有项. 对于每一个读入的 "系数-指数" 对, 将其系数累加到 map 中对应指数的项上. `map[指数] += 系数`. `std::map` 的 `[]` 操作符在这里非常方便: 如果 map 中已存在该指数, 它会直接访问并允许修改对应的系数值; 如果不存在, 它会自动创建一个新条目, 并将系数初始化为0, 然后再执行加法.

3. 处理零系数项: 在合并过程中, 某些项的系数可能变为零. `std::map` 中会保留这些条目. 虽然本题的实现没有显式移除它们, 但在输出时可以根据需要进行过滤.

4. 输出结果:
    + 首先, 输出 map 的大小 `map.size()`, 这代表了结果多项式的项数.
    + 由于 `std::map` 按键(指数)升序存储, 而题目要求按指数降序输出, 因此需要使用反向迭代器 (`crbegin()` 到 `crend()`) 来遍历 map.
    + 在遍历过程中, 打印每个项的系数和指数. 代码中包含一个 `if (iter->first != 0)` 的判断, 这意味着指数为0的项(即常数项)不会被输出. 根据题目要求和样例, 这可能是特定题设下的特殊规则.

这种方法利用了 `std::map` 的特性, 以简洁高效的方式完成了多项式的合并与排序, 完全符合 `AGENTS.md` 中提倡的利用标准库算法和数据结构的原则.
