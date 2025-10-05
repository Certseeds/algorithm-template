# Problem A (Order 1414)

## Description

给定两个数组 A 和 B, 判断 B 中的每个元素是否出现在 A 中。

## Input

第一行：正整数 n, 表示数组 A 的长度, $1 \leq n \leq 1000$

第二行：n 个整数 $a_1, a_2, ..., a_n$, $1 \leq  a_i \leq  10^9$

第三行：正整数 T, 表示数组 B 的长度, $1 \leq T \leq 1000$

第四行：T 个整数 $b_1, b_2, ..., b_T$, $1 \leq  b_i \leq  10^9$

## Output

对 B 中的每个元素输出一行：若该元素存在于 A 中, 输出 "yes"；否则输出 "no"。

## 复用信息

+ Contest 1091:CS203 2021 Fall Welcome Lab
+ Contest 1092:CS217 2021 Fall Welcome Lab
+ Contest 1133:CS203 2023 Fall Lab 0 Welcome Lab
+ Contest 1160:CS203 2024 Fall Lab 0 Welcome Lab
+ Contest 1185:CS203 2025 Fall Lab 0 Welcome Lab

## Data Structure Restrictions

**Lab Level**: Welcome

**Allowed Structures Used**:
- ✅ `std::unordered_set<int32_t>`: For O(1) lookup of elements in set A
- ✅ `std::vector<int32_t>`: For storing query elements from array B
- ✅ Basic loops and conditionals

**Compliance**: This solution uses only data structures allowed in Lab Welcome level. It demonstrates:
- Efficient use of hash set for membership checking
- Simple input/output pattern
- Intuitive approach without complex algorithms

See [Lab Welcome Restrictions](../RESTRICTIONS.md) for full details on allowed data structures at this level.
